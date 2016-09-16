#include "stdafx.h"

#include "tile.h"

#include "../def.h"
#include "../ship/all.h" // until ship -> mesh refactor is done

using namespace ap;
using namespace mesh;

const Draws::Model Tile::eight = {
	&ap::textures::craftgrid,
	&ap::regions::tile
};

const Draws::Model Tile::sixteen = {
	&ap::textures::craftgrid,
	&ap::regions::tile16
};

ap::mesh::Tile::Tile(Grid &grid, Model m, int x, int y) :
	ap::Sprite(SORT_HIGH, m.t, m.r) ,
	x(x),
	y(y),
	grid(grid),
	part(nullptr),
	spawned(0),
	fitted(false),

	neighbors {nullptr}
	{

	sw(r->w);
	sh(r->h);

	sx(grid.gx() + (x*grid.gpoints()));
	sy(grid.gy() + (y*grid.gpoints()));

	// expand();
}

ap::mesh::Tile::~Tile() {
	
}


void ap::mesh::Tile::step() {
	Sprite::step();

	/*if (spawned != -1 ) {
		spawned += delta;
		if ( spawned > ((double) n/20)+0.2 ) {
			sregion(&regions::tile);
			spawned = -1;
			//nodraw = true;
		}
		else if ( spawned > (double) n/20 ) {
			//nodraw = false;
			sregion(&regions::tileover);
		}
	}*/

}

void ap::mesh::Tile::draw() {
	if (grid.enabled)
		Sprite::draw();
}

void ap::mesh::Tile::click() {
	if (grid.enabled)
		grid.gmass().clicked(*this);
}


void ap::mesh::Tile::attach(Part *p) {
	// refactorate
	part = p;
	grid.expandfrom(*this);
	p->connect();
	grid.gmass().add(p);
}


void ap::mesh::Tile::hasneighbor(int x, int y) {

}

void ap::mesh::Tile::sneighbor(Tile &t, int i) {
	neighbors[i] = &t;
}

int opposites[8] = {4,5,6,7,0,1,2,3};

void ap::mesh::Tile::link() {
	for (int i = 0; i < 8; i ++) {
		int x = this->x, y = this->y;

		switch(i) {
			case 0: y -= 1;			break;
			case 1: x += 1; y -= 1; break;
			case 2: x += 1; 		break;
			case 3: x += 1; y += 1; break;
			case 4: y += 1; 		break;
			case 5: x -= 1; y += 1; break;
			case 6: x -= 1; 		break;
			case 7: x -= 1; y -= 1; break;
		}

		std::string xy = std::to_string(x) + "," + std::to_string(y);
		std::unordered_map<std::string, Tile *>::const_iterator got = grid.tilesum.find(xy);
		
		if ( got != grid.tilesum.end() ) {
			got->second->sneighbor(*this, opposites[i]);
			this->sneighbor(*got->second, i);
		}
	}

	fitted = true;
}

void ap::mesh::Tile::hover(mou::Hover h) {
	if (!grid.enabled)
		return;

	if ( ! fitted )
		link();

	if ( mou::HOVER_IN == h ) {
		sregion(&regions::tileover);
		nodraw = false;
	} else {
		sregion(&regions::tile);
		if ( part )
			nodraw = true;
	}

}


/* ###########################
   ## Getters & Setters
   ########################### */
//Grid &ap::mesh::Tile::ggrid() {
//	return grid;
//}

Grid &ap::mesh::Tile::ggrid() { return grid; }
Part *ap::mesh::Tile::gpart() { return part; }

/*Tile *ap::mesh::Tile::gtop() { return top; }
Tile *ap::mesh::Tile::gtopleft() { return topleft; }
Tile *ap::mesh::Tile::gtopright() { return topright; }
Tile *ap::mesh::Tile::gbottom() { return bottom; }
Tile *ap::mesh::Tile::gbottomleft() { return bottomleft; }
Tile *ap::mesh::Tile::gbottomright() { return bottomright; }
Tile *ap::mesh::Tile::gleft() { return left; }
Tile *ap::mesh::Tile::gright() { return right; }*/

Tile **ap::mesh::Tile::gneighbors() { return neighbors; }

//Tile *ap::mesh::Tile::gright() { return right; }

int ap::mesh::Tile::gx() { return x; }
int ap::mesh::Tile::gy() { return y; }