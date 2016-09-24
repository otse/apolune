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
	asd(1)
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

void ap::mesh::Piston::refit() {

	const Attitude* attitude = entangle();

	rotate = attitude->degrees;
	sregion( &PISTONS[attitude->connect] );
}

const Part::Attitude* ap::mesh::Piston::entangle() {

	friends<Part>();

	// quad
	if (TOP && RIGHT && BOTTOM && LEFT) {
		static const Attitude attitude{ 0, QUAD };
		return &attitude;
	}

	// tri
	else if (TOP && RIGHT && BOTTOM) {
		static const Attitude attitude{ 0, TRI };
		return &attitude;
	}
	else if (RIGHT && BOTTOM && LEFT) {
		static const Attitude attitude{ 90, TRI };
		return &attitude;
	}
	else if (BOTTOM && LEFT && TOP) {
		static const Attitude attitude{ 180, TRI };
		return &attitude;
	}
	else if (LEFT && TOP && RIGHT) {
		static const Attitude attitude{ 270, TRI };
		return &attitude;
	}

	// duo
	else if (TOP && RIGHT) {
		static const Attitude attitude{ 0, DUO };
		return &attitude;
	}
	else if (RIGHT && BOTTOM) {
		static const Attitude attitude{ 90, DUO };
		return &attitude;
	}
	else if (BOTTOM && LEFT) {
		static const Attitude attitude{ 180, DUO };
		return &attitude;
	}
	else if (LEFT && TOP) {
		static const Attitude attitude{ 270, DUO };
		return &attitude;
	}

	// opposite
	else if (TOP && BOTTOM) {
		static const Attitude attitude{ 0, OPPOSITE };
		return &attitude;
	}
	else if (LEFT && RIGHT) {
		static const Attitude attitude{ 90, OPPOSITE };
		return &attitude;
	}

	// uni
	else if (TOP) {
		static const Attitude attitude{ 0, UNI };
		return &attitude;
	}
	else if (RIGHT) {
		static const Attitude attitude{ 90, UNI };
		return &attitude;
	}
	else if (BOTTOM) {
		static const Attitude attitude{ 180, UNI };
		return &attitude;
	}
	else if (LEFT) {
		static const Attitude attitude{ 270, UNI };
		return &attitude;
	}

	// single
	else {
		static const Attitude attitude{ 0, SINGLE };
		return &attitude;
	}

	return nullptr;
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