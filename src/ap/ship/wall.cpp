#include "stdafx.h"

#include "wall.h"
#include "all.h"

#include "../def.h"

using namespace ap::ship;
using namespace ap::mesh;


const Wall::Model Wall::iris = {
		{
			&ap::textures::parts,
			&ap::regions::walliris
		},
		{
			&ap::textures::parts,
			&ap::regions::walliris_rear
		}, 100};

const Wall::Model Wall::single = {
		{
			&ap::textures::parts,
			&ap::regions::wallsingle
		},
		{
			&ap::textures::parts,
			&ap::regions::wallsingle_rear
		}, 100};

const Wall::Model Wall::uni = {
		{
			&ap::textures::parts,
			&ap::regions::walluni
		},
		{
			&ap::textures::parts,
			&ap::regions::walluni_rear
		}, 100};

const Wall::Model Wall::duo = {
		{
			&ap::textures::parts,
			&ap::regions::wallduo
		},
		{
			&ap::textures::parts,
			&ap::regions::wallduo_rear
		}, 100};

const Wall::Model Wall::opposite = {
		{
			&ap::textures::parts,
			&ap::regions::wallopposite
		},
		{
			&ap::textures::parts,
			&ap::regions::wallopposite_rear
		}, 100};

const Wall::Model Wall::tri = {
		{
			&ap::textures::parts,
			&ap::regions::walltri
		},
		{
			&ap::textures::parts,
			&ap::regions::walltri_rear
		}, 100};

const Wall::Model Wall::quad = {
		{
			&ap::textures::parts,
			&ap::regions::wallquad
		},
		{
			&ap::textures::parts,
			&ap::regions::wallquad_rear
		}, 100};

const Wall::Model Wall::tri2 = {
		{
			&ap::textures::parts,
			&ap::regions::walltri2
		},
		{
			&ap::textures::parts,
			&ap::regions::walltri2_rear
		}, 100};

const Wall::Model Wall::quad2 = {
		{
			&ap::textures::parts,
			&ap::regions::wallquad2
		},
		{
			&ap::textures::parts,
			&ap::regions::wallquad2_rear
		}, 100};


ap::ship::Wall::Wall(Tile &t) : Part(t) ,
	model(&single),
	outline(nullptr)
	{
	sx(tile.gx()*16);
	sy(tile.gy()*16);
	// LOG("new wall, region " << m.m.r->x << m.m.r->y << m.m.r->w << m.m.r->h)

}

ap::ship::Wall::~Wall() {
	
}


void ap::ship::Wall::step() {
	//Part::step();
}

void ap::ship::Wall::draw2(bool rear) {
	int r = rotate;

	Ship &ship = dynamic_cast<Ship &>(tile.grid.mass); // todo: bad, every mass should be able to dissect

	if ( rear ) {
		//sregion(model->rear.r);
		sregion(quad.rear.r);
		rotate = 0;
	}

	// refactorate
	else if ( !ship.crosssection )
		sregion(model->m.r);

	draw();

	rotate = r;
}

void ap::ship::Wall::click() {
	
}


void ap::ship::Wall::hover(mou::Hover h) {
	if ( mou::HOVER_IN == h ) {
		
	} else {
		
	}
}

#define TOP 		walls[0]
#define TOPRIGHT 	walls[1]
#define RIGHT 		walls[2]
#define BOTTOMRIGHT walls[3]
#define BOTTOM 		walls[4]
#define BOTTOMLEFT 	walls[5]
#define LEFT 		walls[6]
#define TOPLEFT 	walls[7]

void ap::ship::Wall::refit() {
	Tile **all = tile.gneighbors();

	bool walls[8]; // = {false};

	for (int i = 0; i < 8; i ++) {
		Tile *t = all[i];
		walls[i] = t && t->gpart() && t->gpart()->type == TRUSS && dynamic_cast<Truss *>(t->gpart())->gwall();
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

}


/* ###########################
   ## Getters & Setters
   ########################### */
//void ap::ship::Tile::sgrid(int c, int r) {
	//cols = c;
	//rows = r;

	//table();
//}

//float ap::Ply::gy() {
//	return .0;
//}