#include "../def.h"

#include "chair.h"

using namespace ap::objects;
const Chair::Model Chair::apexcool = {
			(en::Draws::Model) {
				&textures::apexcoolchair,
				&regions::apexcoolchair
			}, 0, 0 };

ap::objects::Chair::Chair(const Chair::Model m) :
	ap::Object::Object(en::GDEF, m.m.t, m.m.r) ,
	m(m)
	{
	//tip = "It looks comfy.";
}

ap::objects::Chair::~Chair() {}

/*
void ap::objects::Chair::left() { Object::left(); }
void ap::objects::Chair::right() { Object::right(); }
void ap::objects::Chair::in() { Object::in(); }
void ap::objects::Chair::out() { Object::out(); }
*/



void ap::objects::Chair::step() {
	Object::step();
	
	//if ( ) {}
}

void ap::objects::Chair::activate() {
	Object::activate();
}


// def
