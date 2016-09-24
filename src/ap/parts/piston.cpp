#include "stdafx.h"

#include "piston.h"

#include "../def.h"
#include "../world.h"

#include "../mesh/mass.h"
#include "../mesh/tile.h"
#include "../mesh/block.h"


using namespace ap::mesh;

en::Region Piston::single = { 0,0,16,16 };
en::Region Piston::uni = { 16,0,16,16 };
en::Region Piston::duo = { 32,0,16,16 };
en::Region Piston::opposite = { 48,0,16,16 };
en::Region Piston::tri = { 64,0,16,16 };
en::Region Piston::quad = { 80,0,16,16 };
en::Region Piston::junction = { 96,0,16,16 };

static float i = 126.f / 255.f;
static en::Color aft = { i,i,i };


ap::mesh::Piston::Piston(Tile &t) : Part(FORE, t, SORT_PISTONS) ,
	face(&single)
	{
	sw(16);
	sh(16);

	sregion(&single);
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

	//FACE* pre = (FACE*)prefit();

	//outline.nodraw = shadow.nodraw = &pre->side == &quad;
	//outline.rotate = shadow.rotate = pre->degrees;

	//outline.sregion(pre->side.r);
	//shadow.sregion(pre->side.r);

	friends<Piston>();

	//sregion(face);
	//rotate = ro;
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