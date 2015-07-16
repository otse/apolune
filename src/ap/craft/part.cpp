#include "all.h"

#include "../def.h"

using namespace ap::craft;

ap::craft::Part::Part(Craft &c, const Model m, TYPE t) :
	ap::Sprite(en::GDEF, m.t, m.r) ,
	craft(c),
	type(t)
	{
	world = false;
	//fbo = &craft.gfbo();
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

void ap::craft::Part::scan() {

}


/* ###########################
   ## Getters & Setters
   ########################### */
Craft &ap::craft::Part::gcraft() {
	return craft;
}

//float ap::Ply::gy() {
//	return .0;
//}