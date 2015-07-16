#include "tile.h"
#include "all.h"

#include "../def.h"

using namespace ap::craft;

ap::craft::Tile::Tile(Grid &grid, int n, int x, int y) :
	ap::Sprite(en::GDEF, &textures::craftgrid, &regions::tile) ,
	n(n),
	x(x),
	y(y),
	grid(grid),
	part(nullptr),
	spawned(0)
	{
	nodraw = true;
	scale = 1;

	sw(r->w);
	sh(r->h);
}

ap::craft::Tile::~Tile() {
	
}


void ap::craft::Tile::step() {
	Sprite::step();

	if (spawned != -1 ) {
		spawned += delta;
		if ( spawned > ((double) n/20)+0.2 ) {
			sregion(&regions::tile);
			spawned = -1;
			nodraw = true;
		}
		else if ( spawned > (double) n/20 ) {
			nodraw = false;
			sregion(&regions::tileover);
		}
	}
		//LOG("WHAT")
}

void ap::craft::Tile::click() {
	if ( nullptr != part )
		return;

	if ( &mou::left == mou::active && mou::PRESSED == *mou::active ) {
		Truss *p = new Truss(grid.gcraft(), Truss::metal, x*32, y*32);
		ggrid().gcraft().add(p);
		attach(p);
	}
}


void ap::craft::Tile::attach(Part *p) {
	part = p;
}

void ap::craft::Tile::neighbour(Tile &t) {
	if (t.x == x && t.y == y-1)
		top = &t;
	else if (t.x == x && t.y == y+1)
		bottom = &t;
	else if (t.x == x-1 && t.y == y)
		left = &t;
	else if (t.x == x+1 && t.y == y)
		right = &t;
}

void ap::craft::Tile::hover(mou::Hover h) {
	
	if ( mou::HOVER_IN == h ) {
		sregion(&regions::tileover);
		nodraw = false;
	} else {
		sregion(&regions::tile);
		nodraw = true;
	}

}


/* ###########################
   ## Getters & Setters
   ########################### */
Grid &ap::craft::Tile::ggrid() {
	return grid;
}

//float ap::Ply::gy() {
//	return .0;
//}