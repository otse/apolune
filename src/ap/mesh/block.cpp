#include "stdafx.h"

#include "part.h"

#include "../def.h"
#include "../world.h"
//#include "../ship/all.h"

#include "mass.h"
#include "tile.h"
#include "block.h"


using namespace ap::mesh;

en::Region Block::variations[6] = { { 0,16,8,8 }, { 8,16,8,8 }, { 16,16,8,8 }, { 24,16,8,8 }, { 32,16,8,8 }, { 40,16,8,8 } };

en::Region Block::BLOCKS[6] = { { 0,16,8,8 },{ 8,16,8,8 },{ 16,16,8,8 },{ 24,16,8,8 },{ 32,16,8,8 },{ 40,16,8,8 } };
en::Region Block::OUTLINES[6] = { { 0,0,16,16 },{ 16,0,16,16 },{ 32,0,16,16 },{ 48,0,16,16 },{ 64,0,16,16 },{ 80,0,16,16 } };
en::Region Block::SHADOWS[6] = { { 0,0,16,16 },{ 16,0,16,16 },{ 32,0,16,16 },{ 48,0,16,16 },{ 64,0,16,16 },{ 80,0,16,16 } };

static float i = 126.f / 255.f;
static en::Color aft = { i,i,i };


ap::mesh::Block::Block(FIXTURE f, Tile &t) : Part(f, t, SORT_BLOCKS) ,
	outline(SORT_UNIMPORTANT, &textures::rusty, &OUTLINES[0]),
	shadow(SORT_UNIMPORTANT, &textures::shadows, &SHADOWS[0])
	{

	if (AFT == fixture) {
		color = &aft;
		outline.scolor(&aft);
	}

	sw(8);
	sh(8);

	// sregion(&regions::blocksingle);
	sregion( &variations[tile.variation] );

	stexture(&textures::rusty);

	outline.sx(gx() - 4);
	outline.sy(gy() - 4);

	shadow.sx(gx() - 4);
	shadow.sy(gy() - 4);

	fbo = outline.fbo = shadow.fbo = t.grid.mass.gobf();
	//shadow.fbo = t.grid.mass.gshadow();

	// t.attach(this);

}

ap::mesh::Block::~Block() {
	// does automatic stuff for me
}

void ap::mesh::Block::step() {
	Sprite::step();
}

void ap::mesh::Block::draw(PASS p) {
	switch (p) {
	case FOREGROUND_PASS:
	case BACKGROUND_PASS:
		Sprite::draw();
		outline.draw();
		break;

	case SHADOW_PASS:
		shadow.draw();
		break;
	}
}

void ap::mesh::Block::refit() {

	const Attitude* attitude = entangle();

	if (nullptr == attitude)
		return;

	outline.nodraw = shadow.nodraw = attitude->connect == QUAD;
	outline.rotate = shadow.rotate = attitude->degrees;

	outline.sregion( &OUTLINES[attitude->connect] );
	shadow.sregion( &SHADOWS[attitude->connect] );

}

const Part::Attitude* ap::mesh::Block::entangle() {
	friends<Block>();

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