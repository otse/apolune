#include "stdafx.h"

#include "light.h"
#include "def.h"

using namespace en;

ap::Light::Light(const Model &m, int x, int y) :
	ap::Sprite(SORT_UNIMPORTANT, &textures::sheet, const_cast<Region *>(&m.r) ) ,
	model(m)
{
	
	//ap::world->lights.v.push_back(light);
	
}

ap::Light::~Light () {
	// remove self
	// and light
}


/* ###########################
   ## Getters & Setters
   ########################### */
void ap::Light::sx(double p) { Sprite::sx(p); }
void ap::Light::sy(double p) { Sprite::sy(p); }