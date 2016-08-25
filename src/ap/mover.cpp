#include "stdafx.h"

#include "mover.h"

using namespace ap;

ap::Mover::Mover(Type type, en::Group g, en::Texture *t, en::Region *r) : ap::Sprite(g, t,r) ,
	cycled(false),
	solid(false),
	type(type),
	momentum(0)
	{
	//LOG("mover ctor type " << type);
}

ap::Mover::~Mover() {}

void ap::Mover::translate() {
	Sprite::translate();
}

void ap::Mover::step() {
	//cycle();
	if ( ! cycled && momentum ) {
		momentum = 0;
	}
	
	cycled = false;
	// decrease velocity
}

void ap::Mover::cycle() {
	switch ( type ) {
		case PLAYER :
			momentum = ( en::delta * 140 );
			break;
	}
	cycled = true;
}

void ap::Mover::collide() {
	
}

/* ###########################
   ## Getters & Setters
   ########################### */
void ap::Mover::sx(double p) { Sprite::sx(p); ax = p; }
void ap::Mover::sy(double p) { Sprite::sy(p); ay = p; }

bool ap::Mover::gcollides() {
	return solid;
}

void ap::Mover::scollides(bool b) {
	solid = b;
}