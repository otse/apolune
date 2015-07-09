#include "grid.h"

#include "../def.h"
#include "tile.h"


ap::craft::Grid::Grid(int c, int r) : ap::Sprite(en::GDEF, nullptr, &en::regfluke ) ,
	asd(0),
	cols(c),
	rows(r)
	{
	
}

ap::craft::Grid::~Grid() {

}


void ap::craft::Grid::table() {

	for ( int y = 0; y < rows; y ++ ) {
		for ( int x = 0; x < cols; x ++ ) {

			Tile *t = new Tile();
			t->sx(gx() + (x*32));
			t->sy(gy() + (y*32));
			tiles.v.push_back(t);
			ap::world->add(t);
		}
	}
}


void ap::craft::Grid::step() {

}


/* ###########################
   ## Getters & Setters
   ########################### */
//void ap::craft::Grid::sgrid(int c, int r) {
	//cols = c;
	//rows = r;

	//table();
//}

//float ap::Ply::gy() {
//	return .0;
//}