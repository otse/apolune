#include <iostream>

#include "../h.h"
#include "world.h"
#include "mothership.h"
#include "light.h"
#include "def.h"


ap::Mothership::Mothership()
	: ap::Mover::Mover(
		MOTHERSHIP,
		en::GDEF,
		&textures::hangar,
		&regions::hangar
		) ,
	cock(0)
	{
		//dim(0, 0, textures::orpheus.gw(), textures::orpheus.gh());
		sorder(2);
		post();
	}

ap::Mothership::~Mothership() { // dtor
	
}

void ap::Mothership::post() {
	clawbase = new Sprite(
			en::GDEF,
			&textures::sheet,
			&regions::clawbase
	);
	//clawbase->dim(0, 0, regions::clawbase.w, regions::clawbase.h);
	
	/*Sprite *hangarlight = new Sprite(en::GDEF, &textures::hangarlight, &regions::hangarlight);
	hangarlight->sx((1514-911)*2);
	hangarlight->sy((705-527)*2);
	ap::world->lights.v.push_back(hangarlight);*/
	
	//clawbase->sworld(false);
	//ap::world->sprites.push_back(clawbase);
	
	/*Sprite *mom2 = new Sprite(
			&ap::textures::orpheus,
			const_cast<en::region_t *>(&ap::regions::orpheus)
	);
	mom2->sx(ap::regions::orpheus.w*2);
	ap::world->sprites.push_back(mom2);*/
}

/* ###########################
   ## Getters & Setters
   ########################### */
//float ap::Ply::gx() {
//	return .0;
//}

//float ap::Ply::gy() {
//	return .0;
//}