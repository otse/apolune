#include "stdafx.h"

#include "part.h"

#include "../def.h"
#include "../world.h"
//#include "../ship/all.h"

#include "mass.h"
#include "tile.h"
#include "block.h"


using namespace ap::mesh;

const Block::Side Block::single = {
	&ap::regions::outlinesingle
};

const Block::Side Block::uni = {
	&ap::regions::outlineuni
};

const Block::Side Block::duo = {
	&ap::regions::outlineduo
};

const Block::Side Block::opposite = {
	&ap::regions::outlineopposite
};

const Block::Side Block::tri = {
	&ap::regions::outlinetri
};

const Block::Side Block::quad = {
	&ap::regions::outlinequad
};

ap::mesh::Block::Block(FIXTURE f, Tile &t) : Part(f, t) ,
	side(&single),
	outline(SORT_UNIMPORTANT, &textures::outlines, &regions::outlinesingle),
	shadow(SORT_UNIMPORTANT, &textures::shadows, &regions::outlinesingle)
	{
	std::fill_n(junctions, 4, nullptr);

	sw(8);
	sh(8);

	sregion(&regions::blocksingle);
	stexture(&textures::hulls);

	sx(t.gx()*t.grid.gpoints());
	sy(t.gy()*t.grid.gpoints());

	outline.sx(gx()-4);
	outline.sy(gy()-4);
	shadow.sx(gx() - 4);
	shadow.sy(gy() - 4);

	world = false;

	em = new Emitter(Emitter::placesparks);
	em->sx(gx()+t.grid.gx()+ (t.grid.gpoints()/2));
	em->sy(gy()+t.grid.gy()+ (t.grid.gpoints()/2));
	ap::world->add(em);

	fbo = outline.fbo = shadow.fbo = t.grid.mass.gobf();

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
		if (FORE==fixture) {
			Sprite::draw();
		}
		break;

	case BACKGROUND_PASS:
		if (AFT == fixture) {
			float i = 126 / 255;
			static en::Color aft = { i,i,i };
			color = &aft;
			Sprite::draw();
		}
		break;

	case SHADOW_PASS:
		shadow.draw();
		break;
	}
	
	outline.draw();

	if (nullptr != junctions[0]) junctions[0]->draw();
	if (nullptr != junctions[1]) junctions[1]->draw();
	if (nullptr != junctions[2]) junctions[2]->draw();
	if (nullptr != junctions[3]) junctions[3]->draw();
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
	Sprite *j = new Sprite(SORT_UNIMPORTANT, &textures::hulls, &ap::regions::blockjunction);
	j->world = false;
	j->rotate = r;

	j->sx(gx());
	j->sy(gy());
	j->fbo = tile.grid.mass.gobf();

	junctions[i] = j;
}

#define TOP 		blocks[0]
#define TOPRIGHT 	blocks[1]
#define RIGHT 		blocks[2]
#define BOTTOMRIGHT blocks[3]
#define BOTTOM 		blocks[4]
#define BOTTOMLEFT 	blocks[5]
#define LEFT 		blocks[6]
#define TOPLEFT 	blocks[7]

void ap::mesh::Block::refit () {

	Tile **all = tile.gneighbors();

	bool blocks[8];
	std::fill_n(blocks, 8, false);

	for (int i = 0; i < 4; i++) {
		if (nullptr != junctions[i]) {
			delete junctions[i];
			junctions[i] = nullptr;
		}
	}

	for (int i = 0; i < 8; i++) {
		Tile *t = all[i];

		_ASSERT(t);

		Block* type = dynamic_cast<Block*> (t->gpart(fixture));

		blocks[i] = !! type;
	}

	// quad
	if (TOP && RIGHT && BOTTOM && LEFT) {
		side = &quad;
		outline.rotate = 0;
	}

	// tri
	else if (TOP && RIGHT && BOTTOM) {
		side = &tri;
		outline.rotate = 0;
	}
	else if (RIGHT && BOTTOM && LEFT) {
		side = &tri;
		outline.rotate = 90;
	}
	else if (BOTTOM && LEFT && TOP) {
		side = &tri;
		outline.rotate = 180;
	}
	else if (LEFT && TOP && RIGHT) {
		side = &tri;
		outline.rotate = 270;
	}

	// duo
	else if (TOP && RIGHT) {
		side = &duo;
		outline.rotate = 0;
	}
	else if (RIGHT && BOTTOM) {
		side = &duo;
		outline.rotate = 90;
	}
	else if (BOTTOM && LEFT) {
		side = &duo;
		outline.rotate = 180;
	}
	else if (LEFT && TOP) {
		side = &duo;
		outline.rotate = 270;
	}

	// opposite
	else if (TOP && BOTTOM) {
		side = &opposite;
		outline.rotate = 0;
	}
	else if (LEFT && RIGHT) {
		side = &opposite;
		outline.rotate = 90;
	}

	// uni
	else if (TOP) {
		side = &uni;
		outline.rotate = 0;
	}
	else if (RIGHT) {
		side = &uni;
		outline.rotate = 90;
	}
	else if (BOTTOM) {
		side = &uni;
		outline.rotate = 180;
	}
	else if (LEFT) {
		side = &uni;
		outline.rotate = 270;
	}

	//sregion(side->r);
	outline.sregion(side->r);

	if (side == &quad) {
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
	}

	//if (nullptr != wall)
		//wall->refit();
}

	/*Part *top = (tile.gtop() && tile.gtop()->gpart()) ? tile.gtop()->gpart() : nullptr;
	Part *bottom = (tile.gbottom() && tile.gbottom()->gpart()) ? tile.gbottom()->gpart() : nullptr;
	Part *left = (tile.gleft() && tile.gleft()->gpart()) ? tile.gleft()->gpart() : nullptr;
	Part *right = (tile.gright() && tile.gright()->gpart()) ? tile.gright()->gpart() : nullptr;*/

	/*if ( !(top && top->gtype() == TRUSS && dynamic_cast<Truss *>(top)->gwall()) ) top = nullptr;
	if ( !(bottom && bottom->gtype() == TRUSS && dynamic_cast<Truss *>(bottom)->gwall()) ) bottom = nullptr;
	if ( !(left && left->gtype() == TRUSS && dynamic_cast<Truss *>(left)->gwall()) ) left = nullptr;
	if ( !(right && right->gtype() == TRUSS && dynamic_cast<Truss *>(right)->gwall()) ) right = nullptr;*/


/* ###########################
   ## Getters & Setters
   ########################### */
/*Part::TYPE ap::mesh::Part::gtype() {
	return type;
}*/

//float ap::Ply::gy() {
//	return .0;
//}