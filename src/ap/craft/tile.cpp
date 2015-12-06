#include "tile.h"
#include "all.h"

#include "../def.h"

using namespace ap::craft;

ap::craft::Tile::Tile(Grid &grid, int x, int y) :
	ap::Sprite(en::GDEF, &textures::craftgrid, &regions::tile) ,
	x(x),
	y(y),
	grid(grid),
	part(nullptr),
	spawned(0),
	fitted(false),

	top(nullptr),
	topleft(nullptr),
	topright(nullptr),
	bottom(nullptr),
	bottomleft(nullptr),
	bottomright(nullptr),
	left(nullptr),
	right(nullptr)
	{
	nodraw = true;
	scale = 1;

	sw(r->w);
	sh(r->h);

	sx(grid.gx() + (x*32));
	sy(grid.gy() + (y*32));

	// expand();
}

ap::craft::Tile::~Tile() {
	
}


void ap::craft::Tile::step() {
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

void ap::craft::Tile::click() {
	if ( nullptr != part )
		return;

	if ( &mou::left == mou::active && mou::PRESSED == *mou::active ) {
		Truss *p = new Truss(*this, Truss::single);
		attach(p);
	}
}


void ap::craft::Tile::attach(Part *p) {
	part = p;
	grid.craft.add(p);
	grid.expandfrom(*this);
}


void ap::craft::Tile::hasneighbor(int x, int y) {

}

void ap::craft::Tile::neighbor(Tile &t) {
	if (t.gx() == x && t.gy() == y-1)
		top = &t;
	else if (t.gx() == x-1 && t.gy() == y-1)
		topleft = &t;
	else if (t.gx() == x+1 && t.gy() == y-1)
		topright = &t;
	else if (t.gx() == x && t.gy() == y+1)
		bottom = &t;
	else if (t.gx() == x-1 && t.gy() == y+1)
		bottomleft = &t;
	else if (t.gx() == x+1 && t.gy() == y+1)
		bottomright = &t;
	else if (t.gx() == x-1 && t.gy() == y)
		left = &t;
	else if (t.gx() == x+1 && t.gy() == y)
		right = &t;
}

void ap::craft::Tile::link() {
	for (int i = 0; i < 8; i ++) {
		int x = this->x, y = this->y;

		switch(i) {
			case 0: y -= 1; 		break;
			case 1: x -= 1; y -= 1; break;
			case 2: x += 1; y -= 1; break;
			case 3: y += 1; 		break;
			case 4: x -= 1; y += 1; break;
			case 5: x += 1; y += 1; break;
			case 6: x -= 1; 		break;
			case 7: x += 1; 		break;
		}

		Tile *hit = nullptr;

		std::string xy = std::to_string(x) + "," + std::to_string(y);

		std::unordered_map<std::string, Tile *>::const_iterator got = grid.tilesum.find(xy);
		
		if ( got != grid.tilesum.end() ) {
			got->second->neighbor(*this);
			this->neighbor(*got->second);
		}
	}

	fitted = true;
}

void ap::craft::Tile::hover(mou::Hover h) {

	if ( ! fitted ) link();

	if ( mou::HOVER_IN == h ) {
		sregion(&regions::tileover);
		nodraw = false;
	} else {
		sregion(&regions::tile);
		// if ( part )
			nodraw = true;
	}

}


/* ###########################
   ## Getters & Setters
   ########################### */
//Grid &ap::craft::Tile::ggrid() {
//	return grid;
//}

Part *ap::craft::Tile::gpart() { return part; }

Tile *ap::craft::Tile::gtop() { return top; }
Tile *ap::craft::Tile::gtopleft() { return topleft; }
Tile *ap::craft::Tile::gtopright() { return topright; }
Tile *ap::craft::Tile::gbottom() { return bottom; }
Tile *ap::craft::Tile::gbottomleft() { return bottomleft; }
Tile *ap::craft::Tile::gbottomright() { return bottomright; }
Tile *ap::craft::Tile::gleft() { return left; }
Tile *ap::craft::Tile::gright() { return right; }

//Tile *ap::craft::Tile::gright() { return right; }

int ap::craft::Tile::gx() { return x; }
int ap::craft::Tile::gy() { return y; }