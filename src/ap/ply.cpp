#include "stdafx.h"

#include <iostream>
#include <cmath>

#include "../h.h"
#include "../en/engine.h"
#include "../en/anim.h"
#include "ply.h"


ap::Ply::Ply()
	: ap::Mover::Mover(
		PLAYER,
		SORT_PLAYER,
		&textures::guy,
		&regions::ply
		) ,
		heading(HEADING_RIGHT),
		use(false),
		tbulb(0),
		orientation(0),
		part(nullptr),
		partname("hull") // move to awesome.cpp
	{
	LOG("ply ctor")
	//dim(0, 0, 14, 38);
	sworld(true);

	spawnplosion = new Emitter(Emitter::spawnplosion);
    ap::world->lates.push_back(spawnplosion);
	
	/*breath = new Emitter(Emitter::breathbubbles);
    ap::world->add(breath);*/
}

ap::Ply::~Ply() { // dtor
	
}

void ap::Ply::step() {
	Mover::step();
	
	if ( use )
		use = false;
	
	if ( tbulb > 10 ) {

	}
}

/*void ap::Ply::translate() {
	glTranslatef(xof, yof, 0); // xof and yof are idiots
}*/

void ap::Ply::move() {
	
}

void ap::Ply::key() {
	if ( oar::DOWN == oar::keys[sf::Keyboard::E] ) {
		use = true;
	} else use = false;
	
	
	bool a = oar::keys[sf::Keyboard::A] != oar::UP;
	bool d = oar::keys[sf::Keyboard::D] != oar::UP;
	bool w = oar::keys[sf::Keyboard::W] != oar::UP;
	bool s = oar::keys[sf::Keyboard::S] != oar::UP;

	bool ccw = oar::keys[sf::Keyboard::R] != oar::UP;
	bool cw = oar::keys[sf::Keyboard::T] != oar::UP;

	if (cw) {
		orientation += .2;
	} else	if (ccw) {
		orientation -= .2;
	}

	if (orientation > 360)
		orientation -= 360;
	else if (orientation < 0)
		orientation += 360;

	if ( !(a&&d)&&(a||d) ) {
		cycle();
		sregion( anims::walk.progress(animi) );
		
		if ( a ) {
			if ( HEADING_LEFT != heading ) {
				heading = HEADING_LEFT;
				animi = {0,0,false};
				xflip = true;
			}
			ax -= momentum;
		}
		else if ( d ) {
			if ( HEADING_RIGHT != heading) {
				heading = HEADING_RIGHT;
				animi = {0,0,false};
				xflip = false;
			}
			ax += momentum;
		}
	} else {
		animi = {0,0, false};
		sregion( &regions::ply );
	}
	
	if ( w )
		ay -= momentum;
	else if ( s )
		ay += momentum;
		
	x = ( (int) ax );
	y = ( (int) ay );
	
	if ( nullptr != spawnplosion ) {

		spawnplosion->sx( x + ((regions::ply.w*2)/2) );
		spawnplosion->sy( y + ((regions::ply.h*2)/2) - 8 );
	}
	
	//breath->sx( x + ((regions::ply.w*2)/2) );
	//breath->sy( y + ((regions::ply.h*2)/2) - 25 );
	
	if ( a||d||w||s ) {
		//LOG("x y " << x << ", " << y);
	}
}

void ap::Ply::muse() {
	/*thovering += en::delta;
	
	if ( thovering >= 0.35 ) {
		if ( ! tooltip ) {
			tooltip = new en::Text(en::GDUMP, monospace2, &en::WHITE, tip);
			tooltip->scale = 2;
			tooltip->position();

			tooltip->sx( gscrx() + (monospace2.gh()) );
			tooltip->sy( gscry() - (monospace2.gh()*2) );
			tooltip->position();
			add( tooltip );
		}
		else {
			tooltip->sx( gscrx() + (monospace2.gh()) );
			tooltip->sy( gscry() -(monospace2.gh()*2) );
			tooltip->position();
		}
	}*/
}

/* ###########################
   ## Getters & Setters
   ########################### */
   
bool ap::Ply::guse() {
	return use;
}

void ap::Ply::sx(double p) {
	Sprite::sx(p);
}

void ap::Ply::sy(double p) {
	Sprite::sy(p);
}
//float ap::Ply::gx() {
//	return .0;
//}

//float ap::Ply::gy() {
//	return .0;
//}