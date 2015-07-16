#include "wall.h"
#include "all.h"

#include "../def.h"

using namespace ap::craft;


const Wall::Model Wall::iris = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::walliris
		}, 100};

const Wall::Model Wall::single = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallsingle
		}, 100};

const Wall::Model Wall::uni = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::walluni
		}, 100};

const Wall::Model Wall::duo = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallduo
		}, 100};

const Wall::Model Wall::opposite = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallopposite
		}, 100};

const Wall::Model Wall::tri = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::walltri
		}, 100};

const Wall::Model Wall::quad = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallquad
		}, 100};


ap::craft::Wall::Wall(Tile &t) : Part(t, single.m, WALL) ,
	outline(nullptr)
	{
	sx(tile.gx()*32);
	sy(tile.gy()*32);
	// LOG("new wall, region " << m.m.r->x << m.m.r->y << m.m.r->w << m.m.r->h)

}

ap::craft::Wall::~Wall() {
	
}


void ap::craft::Wall::step() {
	Part::step();


}

void ap::craft::Wall::click() {
	
}


void ap::craft::Wall::hover(mou::Hover h) {
	if ( mou::HOVER_IN == h ) {
		
	} else {
		
	}
}

void ap::craft::Wall::refit() {
	LOG("refit")

	Part *top = (tile.gtop() && tile.gtop()->gpart()) ? tile.gtop()->gpart() : nullptr;
	Part *bottom = (tile.gbottom() && tile.gbottom()->gpart()) ? tile.gbottom()->gpart() : nullptr;
	Part *left = (tile.gleft() && tile.gleft()->gpart()) ? tile.gleft()->gpart() : nullptr;
	Part *right = (tile.gright() && tile.gright()->gpart()) ? tile.gright()->gpart() : nullptr;

	if ( !(top && top->gtype() == TRUSS && dynamic_cast<Truss *>(top)->gwall()) ) top = nullptr;
	if ( !(bottom && bottom->gtype() == TRUSS && dynamic_cast<Truss *>(bottom)->gwall()) ) bottom = nullptr;
	if ( !(left && left->gtype() == TRUSS && dynamic_cast<Truss *>(left)->gwall()) ) left = nullptr;
	if ( !(right && right->gtype() == TRUSS && dynamic_cast<Truss *>(right)->gwall()) ) right = nullptr;

	// quad
	if ( top && bottom && left && right ) {
		sregion(&regions::wallquad);
		rotate = 0;
	}

	// tri
	else if ( top && right && bottom ) {
		sregion(&regions::walltri);
		rotate = 0;
	}
	else if ( right && bottom && left ) {
		sregion(&regions::walltri);
		rotate = 90;
	}
	else if ( bottom && left && top ) {
		sregion(&regions::walltri);
		rotate = 180;
	}
	else if ( left && top && right ) {
		sregion(&regions::walltri);
		rotate = 270;
	}

	// duo
	else if ( top && right ) {
		sregion(&regions::wallduo);
		rotate = 0;
	}
	else if ( right && bottom ) {
		sregion(&regions::wallduo);
		rotate = 90;
	}
	else if ( bottom && left ) {
		sregion(&regions::wallduo);
		rotate = 180;
	}
	else if ( left && top ) {
		sregion(&regions::wallduo);
		rotate = 270;
	}

	// opposite
	else if ( top && bottom ) {
		sregion(&regions::wallopposite);
		rotate = 0;
	}
	else if ( left && right ) {
		sregion(&regions::wallopposite);
		rotate = 90;
	}

	// unir
	else if ( top ) {
		sregion(&regions::walluni);
		rotate = 0;
	}
	else if ( right ) {
		sregion(&regions::walluni);
		rotate = 90;
	}
	else if ( bottom ) {
		sregion(&regions::walluni);
		rotate = 180;
	}
	else if ( left ) {
		sregion(&regions::walluni);
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