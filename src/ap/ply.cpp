#include <iostream>
#include <cmath>

#include "../h.h"
#include "../en/engine.h"
#include "../en/anim.h"
#include "ply.h"


ap::Ply::Ply()
	: ap::Mover::Mover(
		PLAYER,
		en::GPLAYER,
		&textures::guy,
		&regions::ply
		) ,
		heading(HEADING_RIGHT),
		use(false)
	{
	LOG("ply ctor")
	//dim(0, 0, 14, 38);
	sworld(false);
	
	spawnplosion = new Emitter(Emitter::spawnplosion);
    ap::world->add(spawnplosion);
	
	//breath = new Emitter(Emitter::breathbubbles);
    //ap::world->add(breath);
}

ap::Ply::~Ply() { // dtor
	
}

void ap::Ply::step() {
	Mover::step();
	
	if ( use ) use = false;
}

void ap::Ply::translate() {
	glTranslatef(xof, yof, 0); // xof and yof are idiots
}

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