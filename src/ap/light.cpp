#include "stdafx.h"

#include "light.h"
#include "def.h"

using namespace en;

ap::Light::Light(const Model &m, int x, int y) :
	ap::Sprite(GDEF, &textures::sheet, const_cast<Region *>(&m.r) ) ,
	model(m)
{
	
	switch(model.t) {
		case CURSOR :
			light = new Sprite(GDEF, &textures::sheet, const_cast<Region *>(&m.lr));
			ox = (m.lr.w/2)*2;
			oy = (m.lr.h/2)*2;
			break;
			
		case FLUOTUBE :
			light = new Sprite(GDEF, &textures::sheet, const_cast<Region *>(&m.lr));
			ox = ((m.lr.w/2)-(m.r.w/2))*2;
			oy = ((m.lr.h/2)-(m.r.h/2)-45)*2;
			ap::world->sprites.l.push_back(this);
			break;
			
		default:
			light = nullptr;
			ox = -m.lr.w-2;
			oy = -m.lr.h-2;
			break;
	}
	
	sx(x*2);
	sy(y*2);
	
	ap::world->lights.v.push_back(light);
	
}

ap::Light::~Light () {
	// remove self
	// and light
}


/* ###########################
   ## Getters & Setters
   ########################### */
void ap::Light::sx(double p) { Sprite::sx(p); light->sx(p-ox); }
void ap::Light::sy(double p) { Sprite::sy(p); light->sy(p-oy); };