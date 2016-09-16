#include "stdafx.h"

#include "truss.h"

#include "../def.h"

using namespace ap::ship;
using namespace ap::mesh;


const Truss::Model Truss::single = {
		{
			&ap::textures::parts,
			&ap::regions::trusssingle
		}, /* strength */ 100, /* weight */ 100};

const Truss::Model Truss::uni = {
		{
			&ap::textures::parts,
			&ap::regions::trussuni
		}, 100, 100};

const Truss::Model Truss::duo = {
		{
			&ap::textures::parts,
			&ap::regions::trussduo
		}, 100, 100};

const Truss::Model Truss::opposite = {
		{
			&ap::textures::parts,
			&ap::regions::trussopposite
		}, 100, 100};

const Truss::Model Truss::tri = {
		{
			&ap::textures::parts,
			&ap::regions::trusstri
		}, 100, 100};

const Truss::Model Truss::quad = {
		{
			&ap::textures::parts,
			&ap::regions::trussquad
		}, 100, 100};


ap::ship::Truss::Truss(Tile &t) : Part(t, single.m, TRUSS) ,
	model(&single),
	wall(nullptr),
	outline(nullptr),

	junctions {nullptr}
	{

	// if ( !! round(ilrand()) )
	wall = new Wall(tile);

	t.attach(this);
}

ap::ship::Truss::~Truss() {

	for (int i = 0; i < 4; i ++)
		if ( nullptr != junctions[i] )
			delete junctions[i];

}

void ap::ship::Truss::step() {
	Part::step();

	if ( nullptr != wall )
		wall->step();
}

void ap::ship::Truss::draw() {
	if ( nullptr != wall )
		wall->draw2(true);

	Part::draw();

	if ( nullptr != junctions[0] ) junctions[0]->draw();
	if ( nullptr != junctions[1] ) junctions[1]->draw();
	if ( nullptr != junctions[2] ) junctions[2]->draw();
	if ( nullptr != junctions[3] ) junctions[3]->draw();

	//if ( ! craft.crosssection && nullptr != wall )
		//wall->draw2(false);
}

void ap::ship::Truss::click() {
	
}


void ap::ship::Truss::hover(mou::Hover h) {
	if ( mou::HOVER_IN == h ) {
		
	} else {
		
	}
}

void ap::ship::Truss::connect() {
	Tile **all = tile.gneighbors();

	for (int i = 0; i < 8; i ++) {
		Tile *t = all[i];
		if ( t && t->gpart() && t->gpart()->type == TRUSS )
			t->gpart()->refit();
	}

	refit();
}

void ap::ship::Truss::junction(int i, int r) {
	Sprite *j = new Sprite(SORT_UNIMPORTANT, &textures::parts, &ap::regions::trussjunction);
	j->world = false;
	j->rotate = r;

	j->sx(gx());
	j->sy(gy());
	j->fbo = tile.grid.mass.gobf();

	junctions[i] = j;
}

#define TOP 		trusses[0]
#define TOPRIGHT 	trusses[1]
#define RIGHT 		trusses[2]
#define BOTTOMRIGHT trusses[3]
#define BOTTOM 		trusses[4]
#define BOTTOMLEFT 	trusses[5]
#define LEFT 		trusses[6]
#define TOPLEFT 	trusses[7]

void ap::ship::Truss::refit() {
	Tile **all = tile.gneighbors();

	bool trusses[8]; // = {false};

	for (int i = 0; i < 4; i ++) {
		if ( nullptr != junctions[i] ) {
			delete junctions[i];
			junctions[i] = nullptr;
		}
	}

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

	if ( model == &quad ) {
		if ( ! TOPLEFT )
			junction(0, 0);

		if ( ! TOPRIGHT )
			junction(1, 90);

		if ( ! BOTTOMRIGHT )
			junction(2, 180);

		if ( ! BOTTOMLEFT )
			junction(3, 270);
	}
	else if ( model == &tri ) {
		if ( ! TOPLEFT && ( rotate == 180 || rotate == 270 ) )
			junction(0, 0);

		if ( ! TOPRIGHT && ( rotate == 0 || rotate == 270 ) )
			junction(1, 90);

		if ( ! BOTTOMRIGHT && ( rotate == 0 || rotate == 90 ) )
			junction(2, 180);

		if ( ! BOTTOMLEFT && ( rotate == 90 || rotate == 180 ) )
			junction(3, 270);
	}
	else if ( model == &duo ) {
		if ( ! TOPLEFT && ( rotate == 270 ) )
			junction(0, 0);

		if ( ! TOPRIGHT && ( rotate == 0 ) )
			junction(1, 90);

		if ( ! BOTTOMRIGHT && ( rotate == 90 ) )
			junction(2, 180);

		if ( ! BOTTOMLEFT && ( rotate == 180 ) )
			junction(3, 270);
	}

	if ( nullptr != wall )
		wall->refit();
}




/* ###########################
   ## Getters & Setters
   ########################### */
Wall *ap::ship::Truss::gwall() {
	return wall;
}

//float ap::Ply::gy() {
//	return .0;
//}