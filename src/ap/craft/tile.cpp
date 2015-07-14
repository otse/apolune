#include "tile.h"
#include "all.h"

#include "../def.h"


ap::craft::Tile::Tile(Grid &grid, int n, int x, int y) :
	ap::Sprite(en::GDEF, &textures::craftgrid, &regions::craft::tile) ,
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
			sregion(&regions::craft::tile);
			spawned = -1;
			nodraw = true;
		}
		else if ( spawned > (double) n/20 ) {
			nodraw = false;
			sregion(&regions::craft::tileover);
		}
	}
		//LOG("WHAT")
}

void ap::craft::Tile::click() {
	if ( nullptr != part )
		return;

	if ( &mou::left == mou::active && mou::PRESSED == *mou::active ) {
		Truss *p = new Truss(Truss::metal);
		p->sx(x*32);
		p->sy(y*32);
		grid.gcraft()->add(p);
		attach(p);
	}
}

void ap::craft::Tile::attach(Part *p) {
	part = p;
}

void ap::craft::Tile::hover(mou::Hover h) {
	
	if ( mou::HOVER_IN == h ) {
		sregion(&regions::craft::tileover);
		nodraw = false;
	} else {
		sregion(&regions::craft::tile);
		nodraw = true;
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