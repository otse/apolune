#include <iostream>

#include "../h.h"
#include "../en/engine.h"
#include "planet.h"


ap::Planet::Planet(float x, float y, Type type)
	: en::Draws( en::GDEF, nullptr, nullptr) ,
	type(type)
	{
	//LOG("planet ctor")
	//this->world = true;
}

ap::Planet::~Planet() {}

//void ap::Planet::size() {}

void ap::Planet::draw() {
	
}


/* ###########################
   ## Getters & Setters
   ########################### */
ap::Planet::Type ap::Planet::gtype(){ return type; }

//float ap::Ply::gy() {
//	return .0;
//}