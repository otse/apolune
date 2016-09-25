#include "stdafx.h"

#include <algorithm>

#include "../h.h"
#include "../en/fbo.h"

#include "world.h"
#include "light.h"
#include "ply.h"
#include "hangar.h"
#include "emitter.h"

#include "mesh/mass.h"

#include "def.h"

#include "../en/shader.h"
#include "../awesome.h"

en::Region starsreg = { 0, 0, (en::width*3), (en::height*3) };
en::Region *leasurearea = new (en::Region) { 980, 242, 1190-980, 602-242 };
//std::vector<en::Draws> stars;

ap::World::World() :
	//resort(true),
	backdrop(nullptr),
	hangar(nullptr),
	ship(nullptr),

	fboreg( {0,0,en::width,en::height} )
	{
	//lightshader = new en::Shader("shaders/WhitesFragment.txt", "shaders/WhitesVertex.txt");

	LOG("world ctor")
	
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
	// step
	{std::vector<Sprite *>::iterator it;
	for (it = sprites.begin(); it != sprites.end(); it++) {
		Sprite *s = *it;
		s->step();
	}}

	if (lates.size() > 0) {
		sprites.insert(std::end(sprites), std::begin(lates), std::end(lates));
		lates.clear();
	}
}

void ap::World::draw() {
	//sprites.sort([](const Sprite *a, const Sprite *b) { return a->group < b->group; });

	// remove
	//sprites.remove_if(nukeif);

	camerax = ply->gx() + (26 / 2);
	cameray = ply->gy() + (34 / 2);
	as::valuez.SetPropertyAsync(WSLit("orientation"), JSValue(ply->orientation));
	
	cursorlight->sx(en::mou::mx-75);
	cursorlight->sy(en::mou::my-75);

	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, foreground->gfbid() );
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	

	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
	{std::vector<Sprite *>::iterator it;
	for ( it = sprites.begin(); it != sprites.end(); it ++) {
		Sprite *s = *it;
		s->draw();
	}}

	
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, lightmap->gfbid() );
	
	glClearColor(0, 0, 0, .40f); // alpha is intensity of the ambient darkness
	glClear(GL_COLOR_BUFFER_BIT);
	
	lighting();
	
	//glPushMatrix(); // before scale
	//glScalef(ap::scale, ap::scale, 1);

	// draw lights into foreground
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, foreground->gfbid() );
	glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA); // perfect for pasting lightmap
	lightmap->gdraws().draw();
	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // revert to standard blending
	
	// draw backdrop onto default buffer
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	stars->gdraws().rotate += en::delta * .5;
	stars->gdraws().draw();
	//backdrop->draw();
	
	// draw foreground
	en::Draws &d = foreground->gdraws();
	d.draw();

	//glPopMatrix(); // pop scale
}

void ap::World::rescale() {
	// this may be better than gl
}

void ap::World::resize() {
	fboreg.w = en::width;
	fboreg.h = en::height;
	
	// set world offsets
	ap::xof = (en::width/2)-(ply->gw()/2);
	ap::yof = (en::height/2)-(ply->gh()/2)+100;
	
	delete stars;
	delete foreground;
	delete lightmap;
	
	fbos();
}

void ap::World::fbos() {
	stars = new en::FBO(&en::BLACK, starsreg);
	
	en::Draws &d = stars->gdraws();
	
	d.sx( -(( d.gw() - en::width ) / 2) );
	d.sy( -(( d.gh() - en::height ) / 2) );

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
	
	for ( int i = 0; i < 100000; i ++ ) {
		int x = ilrand() * stars->gw();
		int y = ilrand() * stars->gh();
		
		int j = floor(ilrand() * 4);
		en::Region &r = anims::sparkle1.rgetframe( j );
				
		en::Draws star(SORT_UNIMPORTANT, &textures::sparkle1, &r);
		
		float a;
		double randy = ilrand();
		if (randy<.03)
			a = a = ilrand();
		else if (randy<.20)
			a = a = ilrand() * .2;
		else
			a = ilrand() * .05;

		star.sa(a);
		star.rotate = ilrand() * 360;
		
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
	for ( it = lights.begin(); it < lights.end(); it ++) {
		Sprite *s = *it;
		s->draw();
	}
}

void ap::World::load() {
	LOG("world load")
		
	using namespace en;
	backdrop = new en::Draws(
			SORT_UNIMPORTANT,
			&textures::backdrop,
			&regions::backdrop);
	// don't add; we render the backdrop last, manually
	
	ship = new mesh::Mass();
	sprites.push_back(ship);

	mesh::Mass* asteroid = new mesh::Mass();
	sprites.push_back(asteroid);

	//asteroid::Asteroid *ast = new asteroid::Asteroid();
	//add(ast);
	
	cursorlight = new Sprite(SORT_UNIMPORTANT, &textures::cursorlight, &regions::cursorlight);
	cursorlight->world = false;
	cursorlight->sw(cursorlight->gw()*3);
	cursorlight->sh(cursorlight->gh()*3);
	this->lights.push_back(cursorlight);
	
	ply = new Ply();
	ply->sx(0);
	ply->sy(0);
	//ply->nodraw = true;
	sprites.push_back( ply );
	
	ap::xof = (en::width/2)-(ply->gw()/2);
	ap::yof = (en::height/2)-(ply->gh()/2)+100;

	LOG("made world")
}

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