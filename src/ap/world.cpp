#include <algorithm>

#include "../h.h"
#include "../en/engine.h"
#include "../en/fbo.h"

#include "world.h"
//#include "planet.h"
#include "light.h"
#include "ply.h"
#include "mothership.h"
#include "emitter.h"
#include "asteroid.h"

#include "ais/chicken.h"
#include "ais/tentacle.h"
#include "objects/chair.h"
#include "objects/table.h"
#include "objects/console.h"

#include "def.h"


#include "shaders/FontVertexShader.txt"

en::Region starsreg = (en::Region) { 0, 0, (int) (en::width), (int) (en::height) };
en::Region *chickreg = new (en::Region) { 991, 503, 320, 100 };
en::Region *leasurearea = new (en::Region) { 980, 242, 1190-980, 602-242 };
//std::vector<en::Draws> stars;

ap::World::World() :
	//resort(true),
	backdrop(nullptr),
	mom(nullptr),
	
	fboreg( (en::Region) {0,0,en::width,en::height} )
	{
	LOG("world ctor")
	
	stars = new en::FBO(&en::BLACK, starsreg);
	
	en::Draws &d = stars->gdraws();
	
	d.sx( -(( d.gw() - en::width ) / 2) );
	d.sy( -(( d.gh() - en::height ) / 2) );
	
	fbos();
	
	makestars();
}

ap::World::~World() {
	LOG("world dtor")
}

#define ZOOMPART \
	if ( zoom != zoomto ) { \
		double force = en::delta*zoomspeed; \
		if ( zoomto < zoom ) { \
			zoom -= force; \
			if ( zoom < zoomto ) \
				zoom = zoomto; \
		} \
		else { \
			zoom += force; \
			if ( zoom > zoomto ) \
				zoom = zoomto; \
		} \
	}

void ap::World::step() {
	//ply->draw();
	
	//this->steroids(); // Asteroid
	//sprites.sort();

	// todo: sprites need a late-add vector
	
	// step
	{std::list<Sprite *>::iterator it;
	for ( it = sprites.l.begin(); it != sprites.l.end(); it ++) {
		Sprite *s = *it;
		s->step();
	}}
	
	// remove
	{std::list<Sprite *>::iterator it;
	for ( it = sprites.l.begin(); it != sprites.l.end(); it ++) {
		Sprite *s = *it;
		if ( s->remove ) {
			//LOG("removing Sprite in World remove loop ")
			it = sprites.l.erase(it);
			s->remove = false;
			if ( s->delete_ )
				delete s;
		}
	}}
	
	//cursorlight->sx(en::mx);
	//cursorlight->sy(en::my);
	
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, foreground->gfbid() );
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
	{std::list<Sprite *>::iterator it;
	for ( it = sprites.l.begin(); it != sprites.l.end(); it ++) {
		Sprite *s = *it;
		s->draw();
	}}
	
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, lightmap->gfbid() );
	
	glClearColor(0, 0, 0, .40f); // alpha is intensity of the ambient darkness
	glClear(GL_COLOR_BUFFER_BIT);
	
	lighting();
	
	//glPopAttrib();
	
	// draw lights into foreground
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, foreground->gfbid() );
	glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA); // perfect for pasting lightmap
	lightmap->gdraws().draw();
	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // revert to standard blending
	
	if ( ply->isinside(leasurearea) )
		zoomto = 1.5;
	else
		zoomto = 1;
	
	ZOOMPART
	
	// make zoom vars
	double w = en::width * zoom;
	double h = en::height * zoom;
	double x = -((w - en::width) / 2);
	double y = -((h - en::height) / 2);
	
	// draw backdrop onto default buffer
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	/*backdrop->sx(x);
	backdrop->sy(y);
	backdrop->sw(w);
	backdrop->sh(h);*/
	//backdrop->draw();
	
	glClearColor(1, 0, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	stars->gdraws().rotate += en::delta * .5d;
	stars->gdraws().draw();
	
	// draw foreground
	en::Draws &d = foreground->gdraws();
	d.sall(x,y,w,h);
	d.draw();
}

void ap::World::resize() {
	fboreg.w = en::width;
	fboreg.h = en::height;
	
	// set world offsets
	ap::xof = (en::width/2)-(ply->gw()/2);
	ap::yof = (en::height/2)-(ply->gh()/2)+100;
	
	//delete stars;
	delete foreground;
	delete lightmap;
	
	fbos();
}

void ap::World::fbos() {
	//stars = new en::FBO(&en::BLACK, starsreg);
	foreground = new en::FBO(&en::BLACK, fboreg);
	lightmap = new en::FBO(&en::BLACK, fboreg);
}

// `rough gem`
void ap::World::makestars() {
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, stars->gfbid() );
	
	glPushAttrib(GL_VIEWPORT_BIT);
	glViewport(0,0, stars->gw(), stars->gh() );
	
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // revert to standard blending
	
	for ( int i = 0; i < 2500; i ++ ) {
		int x = ilrand() * stars->gw();
		int y = ilrand() * stars->gh();
		
		int j = floor(ilrand() * 4);
		en::Region &r = anims::sparkle1.rgetframe( j );
				
		en::Draws star(en::GDEF, &textures::sparkle1, &r);
		
		float a = ilrand();// * .5;
		star.sa(a);
		
		star.sx(x);
		star.sy(y);
		star.draw();
	}
	
	glPopAttrib();
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
}

void ap::World::lighting() {
	glBlendFunc(GL_ZERO, GL_ONE_MINUS_SRC_ALPHA); // lights blending, white creates 'holes' in darkmap
	
	std::vector<Sprite *>::iterator it;
	for ( it = lights.v.begin(); it < lights.v.end(); it ++) {
		Sprite *s = *it;
		s->draw();
	}
}

void ap::World::load() {
	LOG("world load")
		
	using namespace en;
	backdrop = new en::Draws(
			GDEF,
			&textures::backdrop,
			&regions::backdrop);
	// don't add; we render the backdrop last, manually
	
	mom = new Mothership();
	//mom->nodraw = true;
	this->add( mom );
	mom->post();
	
	//cursorlight = new Light(lights::CURSOR, en::mx, en::my);
	//cursorlight->sworld(false);
	//cursorlight->light->sworld(false);
	
	/*Sprite *mist = new Sprite(en::GDEF, &textures::groundmist, &regions::groundmist);
	mist->sx(900);
	mist->sy(539);
	this->add(mist);*/
	
	ply = new Ply();
	ply->sx((1400-911)*2);
	ply->sy((828-527-33)*2);
	//ply->nodraw = true;
	this->add( ply ); // tiny willy

	for ( int i = 0; i < 1; i ++ ) {
		en::Region *r = new (en::Region) { 565, 503, 220, 100 };
		ais::Tentacle *tentacle = new ais::Tentacle(r);
		tentacle->sx((1500-1111)*2);
		tentacle->sy((828-527-38)*2);
		this->add(tentacle);
	}
	
	for ( int i = 0; i < 1; i ++ ) {
		chicken = new ais::Chicken(chickreg);
		chicken->sx((1500-911)*2);
		chicken->sy((828-527-17)*2);
		chicken->delete_ = false;
		this->add(chicken);
	}

	/*Sprite *radio = new Sprite(
			en::GDEFAULT,
			&textures::apexradio,
			&regions::apexradio);
	radio->sx((1500-911)*2);
	radio->sy((828-527-17)*2);
	add(radio);*/
	
	//LOG(ply->D->designation)
	
	/*
	std::sort(sprites.begin(), sprites.end(), en::Drawscmp()); 
	
	static bool printed = false;
	
	if ( ! printed ) {
		printed = true;
		
		LOG("order of sprites")
		for ( sprites_t::iterator i = sprites.begin(); i < sprites.end(); i ++)
		{
			Sprite *d = *i;
			LOG("'" << d->name << "' order " << d->order)
		}
		
	}
	*/
	
	// set world offsets
	ap::xof = (en::width/2)-(ply->gw()/2);
	ap::yof = (en::height/2)-(ply->gh()/2)+100;
}

void ap::World::add(Sprite *p) {
	sprites.l.push_back(p);
	//s->loc = sprites.size()-1;
	//sploc = s->loc;
	
	//LOG("s->loc = " << s->loc);
}

//void ap::World::rm(Sprite *s) {
	//v.
//}

/*
void ap::rm(Sprite *s) {
	//if ( nullptr == s )
		//return;
	
	std::list<Sprite *>::iterator it;
	for ( it = sprites.l.begin(); it != sprites.l.end(); it ++) {
		if ( *it == s ) {
			sprites.l.erase(it);
			break;
		}
	}
}*/

void ap::World::steroids() {

	/*if ( asteroids.size() < 8 ) {
		Asteroid *s = new Asteroid();
		asteroids.push_back(s);
	}*/
	
	/*if ( Asteroid::count < 8 ) {
		add( new Asteroid(
				&textures::sheet,
				const_cast<en::Region *>(&regions::asteroid)));
	}*/
}



//void ap::Planet::makesize() {
//	
//}

/* ###########################
   ## Getters & Setters
   ########################### */
void smthng() {
	return;
}

void gttrssttrs() {

}
//ap::PlanetType ap::Planet::gtype() {
//	return type;
//}

//float ap::Ply::gy() {
//	return .0;
//}