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

en::Region Block::outlinesingle = { 0,0,16,16 };
en::Region Block::outlineuni = { 16,0,16,16 };
en::Region Block::outlineduo = { 32,0,16,16 };
en::Region Block::outlineopposite = { 48,0,16,16 };
en::Region Block::outlinetri = { 64,0,16,16 };
en::Region Block::outlinequad = { 80,0,16,16 };
en::Region Block::outlinejunction = { 96,0,16,16 };

en::Region Block::blocksingle = { 0,16,8,8 };
en::Region Block::blockuni = { 8,16,8,8 };
en::Region Block::blockduo = { 16,16,8,8 };
en::Region Block::blockopposite = { 24,16,8,8 };
en::Region Block::blocktri = { 32,16,8,8 };
en::Region Block::blockquad = { 40,16,8,8 };
en::Region Block::blockjunction = { 48,16,8,8 };

const Block::Side Block::single = { &outlinesingle };
const Block::Side Block::uni = { &outlineuni };
const Block::Side Block::duo = { &outlineduo };
const Block::Side Block::opposite = { &outlineopposite };
const Block::Side Block::tri = { &outlinetri };
const Block::Side Block::quad = { &outlinequad };

static float i = 126.f / 255.f;
static en::Color aft = { i,i,i };


ap::mesh::Block::Block(FIXTURE f, Tile &t) : Part(f, t) ,
	side(&single),
	outline(SORT_UNIMPORTANT, &textures::rusty, &outlinesingle),
	shadow(SORT_UNIMPORTANT, &textures::shadows, &outlinesingle)
	{
	std::fill_n(junctions, 4, nullptr);

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
	for (int i = 0; i < 4; i++)
		if (nullptr != junctions[i])
			delete junctions[i];
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

	/*if (nullptr != junctions[0]) junctions[0]->draw();
	if (nullptr != junctions[1]) junctions[1]->draw();
	if (nullptr != junctions[2]) junctions[2]->draw();
	if (nullptr != junctions[3]) junctions[3]->draw();*/
}

void ap::mesh::Block::click() {
	
}

void ap::mesh::Block::hover(mou::Hover h) {
	if ( mou::HOVER_IN == h ) {} else {}
}

void ap::mesh::Block::connect () {
	Tile **all = tile.gneighbors();

	for (int i = 0; i < 8; i++) {
		Tile *t = all[i];

		_ASSERT(t);

		Block* type = dynamic_cast<Block*> (t->gpart(fixture));

		if (type)
			type->refit();
	}

	refit();
}

void ap::mesh::Block::junction(int i, int r) {
	Sprite *j = new Sprite(SORT_UNIMPORTANT, &textures::hulls, &blockjunction);
	j->world = false;
	j->rotate = r;

	j->sx(gx());
	j->sy(gy());
	j->fbo = tile.grid.mass.gobf();

	junctions[i] = j;
}

#define TOP 		bools[0]
#define TOPRIGHT 	bools[1]
#define RIGHT 		bools[2]
#define BOTTOMRIGHT bools[3]
#define BOTTOM 		bools[4]
#define BOTTOMLEFT 	bools[5]
#define LEFT 		bools[6]
#define TOPLEFT 	bools[7]

void ap::mesh::Block::refit () {


	/*for (int i = 0; i < 4; i++) {
		if (nullptr != junctions[i]) {
			delete junctions[i];
			junctions[i] = nullptr;
		}
	}*/

	friends<Block>();

	float ro = 0;

	// quad
	if (TOP && RIGHT && BOTTOM && LEFT) {
		side = &quad;
		ro = 0;
	}

	// tri
	else if (TOP && RIGHT && BOTTOM) {
		side = &tri;
		ro = 0;
	}
	else if (RIGHT && BOTTOM && LEFT) {
		side = &tri;
		ro = 90;
	}
	else if (BOTTOM && LEFT && TOP) {
		side = &tri;
		ro = 180;
	}
	else if (LEFT && TOP && RIGHT) {
		side = &tri;
		ro = 270;
	}

	// duo
	else if (TOP && RIGHT) {
		side = &duo;
		ro = 0;
	}
	else if (RIGHT && BOTTOM) {
		side = &duo;
		ro = 90;
	}
	else if (BOTTOM && LEFT) {
		side = &duo;
		ro = 180;
	}
	else if (LEFT && TOP) {
		side = &duo;
		ro = 270;
	}

	// opposite
	else if (TOP && BOTTOM) {
		side = &opposite;
		ro = 0;
	}
	else if (LEFT && RIGHT) {
		side = &opposite;
		ro = 90;
	}

	// uni
	else if (TOP) {
		side = &uni;
		ro = 0;
	}
	else if (RIGHT) {
		side = &uni;
		ro = 90;
	}
	else if (BOTTOM) {
		side = &uni;
		ro = 180;
	}
	else if (LEFT) {
		side = &uni;
		ro = 270;
	}

	//sregion(side->r);

	outline.nodraw = shadow.nodraw = side == &quad;
	outline.rotate = shadow.rotate = ro;

	outline.sregion(side->r);
	shadow.sregion(side->r);

	/*if (side == &quad) {
		if (!TOPLEFT)
			junction(0, 0);

		if (!TOPRIGHT)
			junction(1, 90);

		if (!BOTTOMRIGHT)
			junction(2, 180);

		if (!BOTTOMLEFT)
			junction(3, 270);
	}
	else if (side == &tri) {
		if (!TOPLEFT && (rotate == 180 || rotate == 270))
			junction(0, 0);

		if (!TOPRIGHT && (rotate == 0 || rotate == 270))
			junction(1, 90);

		if (!BOTTOMRIGHT && (rotate == 0 || rotate == 90))
			junction(2, 180);

		if (!BOTTOMLEFT && (rotate == 90 || rotate == 180))
			junction(3, 270);
	}
	else if (side == &duo) {
		if (!TOPLEFT && (rotate == 270))
			junction(0, 0);

		if (!TOPRIGHT && (rotate == 0))
			junction(1, 90);

		if (!BOTTOMRIGHT && (rotate == 90))
			junction(2, 180);

		if (!BOTTOMLEFT && (rotate == 180))
			junction(3, 270);
	}*/

	//if (nullptr != wall)
		//wall->refit();
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