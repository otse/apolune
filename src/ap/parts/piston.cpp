#include "stdafx.h"

#include "piston.h"

#include "../def.h"
#include "../world.h"

#include "../mesh/mass.h"
#include "../mesh/tile.h"
#include "../mesh/block.h"


using namespace ap::mesh;

en::Region Piston::PISTONS[6] = { { 0,0,16,16 },{ 16,0,16,16 },{ 32,0,16,16 },{ 48,0,16,16 },{ 64,0,16,16 },{ 80,0,16,16 } };

static float i = 126.f / 255.f;
static en::Color aft = { i,i,i };


ap::mesh::Piston::Piston(Tile &t) : Part(FORE, t, SORT_PISTONS) ,
	face(1)
	{
	sw(16);
	sh(16);

	sregion( &PISTONS[6] );
	stexture(&textures::piston);

	sx(gx() - 4);
	sy(gy() - 4);

	fbo = t.grid.mass.gobf();
	//shadow.fbo = t.grid.mass.gshadow();
}

ap::mesh::Piston::~Piston() {

}

void ap::mesh::Piston::step() {
	Sprite::step();
}

void ap::mesh::Piston::draw(PASS p) {
	switch (p) {
	case FOREGROUND_PASS:
	//case BACKGROUND_PASS:
		Sprite::draw();
		break;

	case SHADOW_PASS:
		// nope
		break;
	}

}

void ap::mesh::Piston::connect () {
	Tile **all = tile.gneighbors();

	for (int i = 0; i < 8; i++) {
		Tile *t = all[i];

		if (nullptr == t)
			continue;

		_ASSERT(t);

		if (auto p = t->gpart(fixture))
			p->refit();
	}

	refit();
}

#define TOP 		bools[0]
#define TOPRIGHT 	bools[1]
#define RIGHT 		bools[2]
#define BOTTOMRIGHT bools[3]
#define BOTTOM 		bools[4]
#define BOTTOMLEFT 	bools[5]
#define LEFT 		bools[6]
#define TOPLEFT 	bools[7]

void ap::mesh::Piston::refit () {

	const Attitude* attitude = prefit<Part>();

	rotate = attitude->degrees;
	sregion( &PISTONS[attitude->connect] );
}

/* ###########################
   ## Getters & Setters
   ########################### */
/*Part::TYPE ap::mesh::Part::gtype() {
	return type;
}*/

//float ap::Ply::gy() {
//	return .0;
//}