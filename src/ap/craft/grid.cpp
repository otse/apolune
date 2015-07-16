#include "grid.h"
#include "all.h"

#include "../def.h"
#include "tile.h"


ap::craft::Grid::Grid(Craft &o, int c, int r) : ap::Sprite(en::GDEF, nullptr, &en::regfluke ) ,
	craft(o),
	cols(c),
	rows(r)
	{
	//
}

ap::craft::Grid::~Grid() {

}


void ap::craft::Grid::table() {
	craft.sx(gx());
	craft.sy(gy());
	craft.pose();

	int i = 50;
	for ( int y = 0; y < rows; y ++ ) {
		for ( int x = 0; x < cols; x ++ ) {
			i ++;
			Tile *t = new Tile(*this, i, x, y);
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
	}
}


void ap::craft::Grid::step() {

}


/* ###########################
   ## Getters & Setters
   ########################### */
//ap::craft::Craft &ap::craft::Grid::gcraft() {
//	return craft;
//}