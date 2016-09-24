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


ap::mesh::Block::Block(FIXTURE f, Tile &t) : Part(f, t, SORT_BLOCKS) ,
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

void ap::mesh::Block::junction(int i, int r) {
	Sprite *j = new Sprite(SORT_UNIMPORTANT, &textures::hulls, &blockjunction);
	j->world = false;
	j->rotate = r;

	j->sx(gx());
	j->sy(gy());
	j->fbo = tile.grid.mass.gobf();

	junctions[i] = j;
}

void ap::mesh::Block::refit () {

	FACE* pre = (FACE*) prefit<Block>();
	
	//sregion(side->r);

	outline.nodraw = shadow.nodraw = &pre->side == &quad;
	outline.rotate = shadow.rotate = pre->degrees;

	outline.sregion(pre->side.r);
	shadow.sregion(pre->side.r);

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