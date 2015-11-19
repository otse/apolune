#include "grid.h"
#include "all.h"

#include "../def.h"
#include "tile.h"


ap::craft::Grid::Grid(Craft &o) : ap::Sprite(en::GDEF, nullptr, &en::regfluke ) ,
	craft(o)
	{
	sx(craft.gx());
	sy(craft.gy());
}

ap::craft::Grid::~Grid() {

}

ap::craft::Tile &ap::craft::Grid::single(int x, int y) {
	Tile *t = new Tile(*this, x, y);
	t->sx(gx() + (x*32));
	t->sy(gy() + (y*32));
	tiles.v.push_back(t);
	ap::world->add(t);
	return *t;
}

void ap::craft::Grid::expandfrom(int x, int y) {
	int i = 0;

	for (int i = 0; i < 3; i ++) {
		LOG(i)

		int X = x;
		int Y = y;

		switch(i) {
			case 0: Y -= 1; break; // top
			case 1: X += 1; break; // right
			case 2: Y += 1; break; // bottom
			case 3: X -= 1; break; // left
		}

		Tile *t = new Tile(*this, X, Y);
		t->sx(gx() + (X*32));
		t->sy(gy() + (Y*32));
		tiles.v.push_back(t);
		ap::world->add(t);
	}
	
	/*if (t.gx() == x && t.gy() == y-1)
		top = &t;
	else if (t.gx() == x-1 && t.gy() == y+1)
		topleft = &t;
	else if (t.gx() == x+1 && t.gy() == y+1)
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
		right = &t;*/

	
}

//void ap::craft::Grid::table() {

	/*for ( int y = 0; y < rows; y ++ ) {
		for ( int x = 0; x < cols; x ++ ) {
			Tile *t = new Tile(*this, x, y);
			t->sx(gx() + (x*32));
			t->sy(gy() + (y*32));
			tiles.v.push_back(t);
			ap::world->add(t);
		}
	}

	std::vector<Tile *>::iterator it;
	for ( it = tiles.v.begin(); it < tiles.v.end(); it ++) {
		Tile *t = *it;

		std::vector<Tile *>::iterator it2;
		for ( it2 = tiles.v.begin(); it2 < tiles.v.end(); it2 ++) {
			Tile *t2 = *it2;
			if ( t != t2)
				t->neighbour(*t2);
		}
	}*/
//}


void ap::craft::Grid::step() {

}


/* ###########################
   ## Getters & Setters
   ########################### */
//ap::craft::Craft &ap::craft::Grid::gcraft() {
//	return craft;
//}