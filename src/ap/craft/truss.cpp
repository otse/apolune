#include "truss.h"

#include "../def.h"

using namespace ap::craft;

const Truss::Model Truss::single = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::trusssingle
		}, /* strength */ 100, /* weight */ 100};

const Truss::Model Truss::uni = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::trussuni
		}, 100, 100};

const Truss::Model Truss::duo = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::trussduo
		}, 100, 100};

const Truss::Model Truss::opposite = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::trussopposite
		}, 100, 100};

const Truss::Model Truss::tri = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::trusstri
		}, 100, 100};

const Truss::Model Truss::quad = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::trussquad
		}, 100, 100};


ap::craft::Truss::Truss(Tile &t) : Part(t, single.m, TRUSS) ,
	model(&single),
	wall(nullptr),
	outline(nullptr),

	junction1(nullptr),
	junction2(nullptr),
	junction3(nullptr),
	junction4(nullptr)
	{

	// if ( !! round(ilrand()) )
	wall = new Wall(tile);
}

ap::craft::Truss::~Truss() {
	
}

void ap::craft::Truss::step() {
	Part::step();

	if ( nullptr != wall )
		wall->step();
}

void ap::craft::Truss::draw() {
	if ( nullptr != wall )
		wall->draw2(true);

	Part::draw();

	if ( nullptr != junction1 ) junction1->draw();
	if ( nullptr != junction2 ) junction2->draw();
	if ( nullptr != junction3 ) junction3->draw();
	if ( nullptr != junction4 ) junction4->draw();

	if ( ! craft.crosssection && nullptr != wall )
		wall->draw2(false);
}

void ap::craft::Truss::click() {
	
}


void ap::craft::Truss::hover(mou::Hover h) {
	if ( mou::HOVER_IN == h ) {
		
	} else {
		
	}
}

void ap::craft::Truss::connect() {
	Tile **all = tile.gneighbors();

	for (int i = 0; i < 8; i ++) {
		Tile *t = all[i];
		if ( t && t->gpart() && t->gpart()->type == TRUSS )
			t->gpart()->refit();
	}

	refit();
}

#define TOP 		trusses[0]
#define TOPRIGHT 	trusses[1]
#define RIGHT 		trusses[2]
#define BOTTOMRIGHT trusses[3]
#define BOTTOM 		trusses[4]
#define BOTTOMLEFT 	trusses[5]
#define LEFT 		trusses[6]
#define TOPLEFT 	trusses[7]

void ap::craft::Truss::refit() {
	Tile **all = tile.gneighbors();

	bool trusses[8]; // = {false};

	for (int i = 0; i < 8; i ++) {
		Tile *t = all[i];
		trusses[i] = t && t->gpart() && t->gpart()->type == TRUSS;
	}
	
	// quad
	if ( TOP && RIGHT && BOTTOM && LEFT ) {
		model = &quad;
		rotate = 0;
	}

	// tri
	else if ( TOP && RIGHT && BOTTOM ) {
		model = &tri;
		rotate = 0;
	}
	else if ( RIGHT && BOTTOM && LEFT ) {
		model = &tri;
		rotate = 90;
	}
	else if ( BOTTOM && LEFT && TOP ) {
		model = &tri;
		rotate = 180;
	}
	else if ( LEFT && TOP && RIGHT ) {
		model = &tri;
		rotate = 270;
	}

	// duo
	else if ( TOP && RIGHT ) {
		model = &duo;
		rotate = 0;
	}
	else if ( RIGHT && BOTTOM ) {
		model = &duo;
		rotate = 90;
	}
	else if ( BOTTOM && LEFT ) {
		model = &duo;
		rotate = 180;
	}
	else if ( LEFT && TOP ) {
		model = &duo;
		rotate = 270;
	}

	// opposite
	else if ( TOP && BOTTOM ) {
		model = &opposite;
		rotate = 0;
	}
	else if ( LEFT && RIGHT ) {
		model = &opposite;
		rotate = 90;
	}

	// uni
	else if ( TOP ) {
		model = &uni;
		rotate = 0;
	}
	else if ( RIGHT ) {
		model = &uni;
		rotate = 90;
	}
	else if ( BOTTOM ) {
		model = &uni;
		rotate = 180;
	}
	else if ( LEFT ) {
		model = &uni;
		rotate = 270;
	}

	sregion(model->m.r);

	// junctions
	if ( model == &quad) {
		if ( ! TOPLEFT ) {
			junction1 = new Sprite(en::GDEF, &textures::parts, &regions::trussjunction);
			junction1->rotate = 90;
			junction1->sx(gx());
			junction1->sy(gy());
			LOG ("quad: ! topLEFT")
		}
	}

	if ( nullptr != wall )
		wall->refit();
}


/* ###########################
   ## Getters & Setters
   ########################### */
Wall *ap::craft::Truss::gwall() {
	return wall;
}

//float ap::Ply::gy() {
//	return .0;
//}