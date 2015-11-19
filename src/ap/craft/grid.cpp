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


void ap::craft::Grid::table() {

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
}


void ap::craft::Grid::step() {

}


/* ###########################
   ## Getters & Setters
   ########################### */
//ap::craft::Craft &ap::craft::Grid::gcraft() {
//	return craft;
//}