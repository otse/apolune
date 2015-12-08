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
	sx(tile.gx()*32);
	sy(tile.gy()*32);
	// LOG("new wall, region " << m.m.r->x << m.m.r->y << m.m.r->w << m.m.r->h)

}

ap::craft::Wall::~Wall() {
	
}


void ap::craft::Wall::step() {
	//Part::step();
}

void ap::craft::Wall::draw2(bool rear) {
	if ( rear )
		sregion(model->rear.r);

	else if ( ! craft.crosssection )
		sregion(model->m.r);

	draw();
}

void ap::craft::Wall::click() {
	
}


void ap::craft::Wall::hover(mou::Hover h) {
	if ( mou::HOVER_IN == h ) {
		
	} else {
		
	}
}

void ap::craft::Wall::refit() {
	Part *top = (tile.gtop() && tile.gtop()->gpart()) ? tile.gtop()->gpart() : nullptr;
	Part *bottom = (tile.gbottom() && tile.gbottom()->gpart()) ? tile.gbottom()->gpart() : nullptr;
	Part *left = (tile.gleft() && tile.gleft()->gpart()) ? tile.gleft()->gpart() : nullptr;
	Part *right = (tile.gright() && tile.gright()->gpart()) ? tile.gright()->gpart() : nullptr;

	if ( !(top && top->type == TRUSS && dynamic_cast<Truss *>(top)->gwall()) ) top = nullptr;
	if ( !(bottom && bottom->type == TRUSS && dynamic_cast<Truss *>(bottom)->gwall()) ) bottom = nullptr;
	if ( !(left && left->type == TRUSS && dynamic_cast<Truss *>(left)->gwall()) ) left = nullptr;
	if ( !(right && right->type == TRUSS && dynamic_cast<Truss *>(right)->gwall()) ) right = nullptr;

	// quad
	if ( top && bottom && left && right ) {
		model = &quad;
		//sregion(&regions::wallquad);
		rotate = 0;
	}

	// tri
	else if ( top && right && bottom ) {
		model = &tri;
		rotate = 0;
	}
	else if ( right && bottom && left ) {
		model = &tri;
		rotate = 90;
	}
	else if ( bottom && left && top ) {
		model = &tri;
		rotate = 180;
	}
	else if ( left && top && right ) {
		model = &tri;
		rotate = 270;
	}

	// duo
	else if ( top && right ) {
		model = &duo;
		rotate = 0;
	}
	else if ( right && bottom ) {
		model = &duo;
		rotate = 90;
	}
	else if ( bottom && left ) {
		model = &duo;
		rotate = 180;
	}
	else if ( left && top ) {
		model = &duo;
		rotate = 270;
	}

	// opposite
	else if ( top && bottom ) {
		model = &opposite;
		rotate = 0;
	}
	else if ( left && right ) {
		model = &opposite;
		rotate = 90;
	}

	// uni
	else if ( top ) {
		model = &uni;
		rotate = 0;
	}
	else if ( right ) {
		model = &uni;
		rotate = 90;
	}
	else if ( bottom ) {
		model = &uni;
		rotate = 180;
	}
	else if ( left ) {
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