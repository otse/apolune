#include "wall.h"
#include "all.h"

#include "../def.h"

using namespace ap::craft;


const Wall::Model Wall::iris = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::walliris
		},
		(en::Draws::Model) {
			&textures::parts,
			&regions::walliris_rear
		}, 100};

const Wall::Model Wall::single = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallsingle
		},
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallsingle_rear
		}, 100};

const Wall::Model Wall::uni = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::walluni
		},
		(en::Draws::Model) {
			&textures::parts,
			&regions::walluni_rear
		}, 100};

const Wall::Model Wall::duo = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallduo
		},
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallduo_rear
		}, 100};

const Wall::Model Wall::opposite = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallopposite
		},
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallopposite_rear
		}, 100};

const Wall::Model Wall::tri = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::walltri
		},
		(en::Draws::Model) {
			&textures::parts,
			&regions::walltri_rear
		}, 100};

const Wall::Model Wall::quad = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallquad
		},
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallquad_rear
		}, 100};

const Wall::Model Wall::tri2 = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::walltri2
		},
		(en::Draws::Model) {
			&textures::parts,
			&regions::walltri2_rear
		}, 100};

const Wall::Model Wall::quad2 = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallquad2
		},
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallquad2_rear
		}, 100};


ap::craft::Wall::Wall(Tile &t) : Part(t, single.m, WALL) ,
	model(&single),
	outline(nullptr)
	{
	sx(tile.gx()*48);
	sy(tile.gy()*48);
	// LOG("new wall, region " << m.m.r->x << m.m.r->y << m.m.r->w << m.m.r->h)

}

ap::craft::Wall::~Wall() {
	
}


void ap::craft::Wall::step() {
	//Part::step();
}

void ap::craft::Wall::draw2(bool rear) {
	int r = rotate;

	if ( rear ) {
		//sregion(model->rear.r);
		sregion(quad.rear.r);
		rotate = 0;
	}

	else if ( ! craft.crosssection )
		sregion(model->m.r);

	draw();

	rotate = r;
}

void ap::craft::Wall::click() {
	
}


void ap::craft::Wall::hover(mou::Hover h) {
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

void ap::craft::Wall::refit() {
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
//void ap::craft::Tile::sgrid(int c, int r) {
	//cols = c;
	//rows = r;

	//table();
//}

//float ap::Ply::gy() {
//	return .0;
//}