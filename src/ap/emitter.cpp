#include "stdafx.h"

#include "../en/anim.h"

#include "emitter.h"
#include "def.h"

using namespace ap;

const Emitter::Model Emitter::breathbubbles = {
			{
				&textures::bubbles,
				&regions::bubble
			},
			200., // emit
			1000., // emit vary
			1700., // particle kill
			0., // emitter kill,
			false, // wait for particle
			0., // fade in
			0., // fade out
			.75, // alpha
			0., // alpha vary
			.0, // spin
			.0, // spin vary
			20., // move
			{.5, .5}, // angle range
			1., // base size
			0., // size vary
			0., // grow
			.75, // pull angle 
			40., // pull angle force
			&anims::bubbles // anim
};

const Emitter::Model Emitter::spawnplosion = {
			{
				&textures::playerdeath,
				&regions::playerdeath
			},
			750., // emit
			0., // emit vary
			1000., // particle kill
			750*5., // emitter kill,
			true, // wait for particle
			0., // fade in
			0., // fade out
			1., // alpha
			0., // alpha vary
			.0, // spin
			.1, // spin vary
			30., // move
			{.5, .5}, // angle range
			1., // base size
			0., // size vary
			0., // grow
			.75, // pull angle 
			40., // pull angle force
			&anims::playerdeath // anim
};

const Emitter::Model Emitter::ventfume = {
			{
				&textures::ventfume,
				&regions::ventfume
			},
			500., // emit
			1500., // emit vary
			6000., // particle kill
			0, // emitter kill
			false, // wait for particle
			300., // fade in
			2500., // fade out
			.4, // alpha
			0.2, // alpha vary
			0, // spin
			0.1, // spin vary
			3., // move
			{0, 1}, // angle range
			.6, // base size
			.2, // size vary
			.1, // grow
			0.75, // pull angle
			14., // pull angle force
			0 // anim
};

const Emitter::Model Emitter::placesparks = {
			{
				&textures::sparkle1,
				&regions::sparkle1
			},
			35., // emit
			15., // emit vary
			800., // particle kill
			150, // emitter kill,
			true, // wait for particle
			32., // fade in
			600., // fade out
			.2, // alpha
			0.4, // alpha vary
			.0, // spin
			.0, // spin vary
			80., // move
			{0, 1}, // angle range
			1., // base size
			0., // size vary
			0., // grow
			.0, // pull angle 
			0., // pull angle force
			&anims::sparkle1 // anim
};

ap::Emitter::Emitter(const Model &m) :
	ap::Sprite(en::GDEF, nullptr, &en::regfluke) ,
	m(m),
	kill(en::dnow+m.emitterkill),
	timer(0.0),
	wantsout(false)
{
	delete_ = false;
}

void ap::Emitter::rm(Particle *o) {
	std::vector<Particle *>::iterator it;
	for ( it = p.begin(); it < p.end(); it ++) {
		if ( *it == o ) {
			p.erase(it);
			break;
		}
	}
}

ap::Emitter::~Emitter() {
	LOG("DELETEING EMITTER")
}

void ap::Emitter::step() {
	if ( remove ) {
		wantsout = true;
		remove = false;
	}
	
	if ( m.emitterkill  &&  kill-en::dnow <= 0 ) {
		if ( m.waitforparticle )
			wantsout = true;
		else
			remove = true;
	} else if ( timer-en::dnow <= 0 ) {
		timer = en::dnow + m.emit + (ilrand()*m.emitvary);
		
		Particle *p = new Particle(this);
		this->p.push_back(p);
	}
}

void ap::Emitter::draw() {
	std::vector<Particle *>::iterator it;
	
	for ( it = p.begin(); it < p.end(); it ++)
		((Particle *)*it) ->step();
	
	for ( it = p.begin(); it < p.end(); it ++) {
		Particle *o = *it;
		if ( o->remove ) {
			rm(o);
			delete o;
		}
	}
	
	for ( it = p.begin(); it < p.end(); it ++)
		((Particle *)*it) ->draw();
}

const Emitter::Model &ap::Emitter::gm() {
	return m;
}

// PARTICLE

ap::Particle::Particle(Emitter *const e) :
	ap::Sprite(en::GDEF, e->m.m.t, e->m.m.r ) ,
	e(e),
	spawn(en::dnow),
	kill(en::dnow + e->m.particlekill),
	timer(en::dnow),
	alpha( e->m.alpha + ( ilrand() * e->m.alphavary ) ),
	angle( e->m.anglerange[0] + (ilrand() * e->m.anglerange[1]) ),
	clockwise( !! round(ilrand()) ),
	spin( ilrand() * e->m.spinvary ),
	rotate(0)
{
	
	if ( e->m.basesize < 1  ||  e->m.sizevary > 0 ) {
		sw( (w * e->m.basesize) + (ilrand() * e->m.sizevary) );
		sh( (h * e->m.basesize) + (ilrand() * e->m.sizevary) );
	}
	
	sx(e->gx()-(w/2));
	sy(e->gy()-(h/2));
	
}

void ap::Particle::step() {
	const Emitter::Model &m = e->m;
	
	if ( nullptr != m.anim )
		sregion(m.anim->progress(animi));
	
	float a = this->alpha;
	float diff = en::dnow-spawn;
	if ( m.fadein )
		a = this->alpha * ((en::dnow-spawn) / m.fadein);
	if ( a > this->alpha )
		a = this->alpha;
	sa(a);
	
	//float end = (dnow-spawn) / m.fadeout;
	if ( kill-en::dnow <= m.fadeout ) {
		float a;
		a = this->alpha * ((kill-en::dnow) / m.fadeout);
		if ( a < 0 )
			a = 0;
		sa(a);
	}
		//a = m.alpha * ((dnow-spawn) / m.fadeout);
	
	//printf("dnow %f\nspawn %f\ndiff %f\n", dnow, spawn, dnow-spawn);
	
	if ( m.spin  ||  m.spinvary ) {
		float spin = en::delta * ( m.spin + this->spin);
		
		if ( clockwise )
			rotate += spin;
		else
			rotate -= spin;
		
		if ( rotate < 0 )
			rotate = 1 - rotate;
		
		Draws::rotate = Particle::rotate * 360;
	}
	
	if ( m.grow ) {
		double grew = en::delta * m.grow;
		double wgrew = (w * grew);
		double hgrew = (h * grew);
		x -= wgrew / 2;
		y -= hgrew / 2;
		w += wgrew;
		h += hgrew;
	}
	
	{
	float pangle = (M_PI * 2) * this->angle;
	float v = en::delta * m.move;
	x += v * cos(pangle);
	y += v * sin(pangle);
	}
	
	if ( m.pullangleforce ) {
		float pangle = (M_PI * 2) * m.pullangle;
		float v = en::delta * m.pullangleforce;
		x += (v * cos(pangle));
		y += (v * sin(pangle));
	}
	
	if ( kill-en::dnow <= 0 ) {
		remove = true;
		if ( e->wantsout )
			e->remove = true;
	}
}

ap::Particle::~Particle() {}

