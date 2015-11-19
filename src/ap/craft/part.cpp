#include "all.h"

#include "../def.h"

using namespace ap::craft;

ap::craft::Part::Part(Tile &t, const Model m, TYPE type) :
	ap::Sprite(en::GDEF, m.t, m.r) ,
	tile(t),
	craft(t.grid.craft),
	type(type)
	{
	sx(t.gx()*32);
	sy(t.gy()*32);
	world = false;

	em = new Emitter(Emitter::placesparks);
	em->sx(gx()+t.grid.gx()+16);
	em->sy(gy()+t.grid.gy()+16);
	ap::world->add(em);

	fbo = craft.gfbo();
}

ap::craft::Part::~Part() {
	
}


void ap::craft::Part::step() {
	Sprite::step();
}

void ap::craft::Part::draw() {
	Sprite::draw();
}

void ap::craft::Part::click() {
	
}

void ap::craft::Part::hover(mou::Hover h) {
	if ( mou::HOVER_IN == h ) {} else {}
}

void ap::craft::Part::refit() {}


/* ###########################
   ## Getters & Setters
   ########################### */
Part::TYPE ap::craft::Part::gtype() {
	return type;
}

//float ap::Ply::gy() {
//	return .0;
//}