#include <iostream>

#include "../h.h"
#include "world.h"
#include "hangar.h"
#include "light.h"
#include "def.h"

#include "ais/chicken.h"
#include "ais/tentacle.h"
#include "objects/chair.h"
#include "objects/table.h"
#include "objects/console.h"

#include "craft/all.h"

en::Region *chickreg = new (en::Region) { 991, 503, 320, 100 };


ap::Hangar::Hangar()
	: ap::Mover::Mover(
		MOTHERSHIP,
		en::GDEF,
		&textures::hangar,
		&regions::hangar
		) ,
	asd(0),
	craft(nullptr)
	{
	//dim(0, 0, textures::orpheus.gw(), textures::orpheus.gh());
	sorder(2);
}

ap::Hangar::~Hangar() { // dtor
	
}

void ap::Hangar::step() {
	grid->step();
}

void ap::Hangar::post() {

	Sprite *hangarlight = new Sprite(en::GDEF, &textures::hangarlight, &regions::hangarlight);
	hangarlight->sx((1514-911)*2);
	hangarlight->sy((705-527)*2);
	ap::world->lights.v.push_back(hangarlight);

	craft = new craft::Craft();
	ap::world->add(craft);

	grid = new craft::Grid(craft, 14, 5);
	grid->sx(264*2+64);
	grid->sy(213*2);
	grid->table();

	//grid.attach(craft);
	
	Light *light1 = new Light(lights::FLUOTUBE, 1235-911, 754-527);
	Light *light2 = new Light(lights::FLUOTUBE, 1307-911, 754-527);
	Light *light3 = new Light(lights::FLUOTUBE, 1379-911, 754-527);
	//Light *light4 = new Light(lights::FLUOTUBE, 1194/2, 402/2);
	//Light *light4 = new Light(lights::FLUOTUBE, 1283, 772);
	//Light *light5 = new Light(lights::FLUOTUBE, 1364, 772);
	
	Emitter *ventfume1 = new Emitter(Emitter::ventfume);
	ventfume1->sx(673);
	ventfume1->sy(540);
	ap::world->add(ventfume1);
	
	Emitter *ventfume2 = new Emitter(Emitter::ventfume);
	ventfume2->sx(816);
	ventfume2->sy(540);
	ap::world->add(ventfume2);
	
	Emitter *ventfume3 = new Emitter(Emitter::ventfume);
	ventfume3->sx(958);
	ventfume3->sy(540);
	ap::world->add(ventfume3);

	using namespace objects;

	Chair *chair = new Chair(Chair::apexcool);
	chair->sx((1432-910)*2);
	chair->sy((828-527-18)*2);
	ap::world->add(chair);
	
	/*Console *console = new Console();
	console->sx((1452-970)*2);
	console->sy((828-544)*2);
	add(console);*/

	Table *table = new Table(Table::apexcool);
	table->sx((1450-910)*2);
	table->sy((828-527-16)*2);
	ap::world->add(table);
	
	Simpleanim *teacup = new Simpleanim(
			en::GDEF,
			&textures::teacup,
			&regions::teacup,
			anims::teacup);
	teacup->sx(1088);
	teacup->sy(570-16);
	ap::world->add(teacup);

	/*for ( int i = 0; i < 1; i ++ ) {
		en::Region *r = new (en::Region) { 565, 503, 220, 100 };
		ais::Tentacle *tentacle = new ais::Tentacle(r);
		tentacle->sx((1500-1111)*2);
		tentacle->sy((828-527-38)*2);
		this->add(tentacle);
	}*/
	
	for ( int i = 0; i < 1; i ++ ) {
		chicken = new ais::Chicken(chickreg);
		chicken->sx((1500-911)*2);
		chicken->sy((828-527-17)*2);
		chicken->delete_ = false;
		ap::world->add(chicken);
	}

	/*Sprite *radio = new Sprite(
			en::GDEFAULT,
			&textures::apexradio,
			&regions::apexradio);
	radio->sx((1500-911)*2);
	radio->sy((828-527-17)*2);
	add(radio);*/
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

//old hangar post
	
	/*clawbase = new Sprite(
			en::GDEF,
			&textures::sheet,
			&regions::clawbase
	);*/

	//clawbase->dim(0, 0, regions::clawbase.w, regions::clawbase.h);
	
	/**/
	
	//clawbase->sap::world(false);
	//ap::ap::world->sprites.push_back(clawbase);
