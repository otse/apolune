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

void ap::craft::Grid::expandfrom(Tile &t) {
	for (int i = 0; i < 8; i ++) {
		//next:
		int x = t.gx(), y = t.gy();

		switch(i) {
			case 0: y -= 1; 		break; // top
			case 1: x -= 1; y -= 1; break; // topleft
			case 2: x += 1; y -= 1; break; // topright
			case 3: y += 1; 		break; // bottom
			case 4: x -= 1; y += 1; break; // bottomleft
			case 5: x += 1; y += 1; break; // bottomright
			case 6: x -= 1; 		break; // left
			case 7: x += 1; 		break; // right
		}

		Tile *hit = nullptr;

		std::vector<Tile *>::iterator it;
		for ( it = tiles.v.begin(); it < tiles.v.end(); it ++) {
			Tile *c = *it;
			if (c->gx() == x && c->gy() == y) {
				hit = c;
				t.neighbour(*c);
				c->neighbour(t);
				//goto next;
			}
		}

		if ( hit != nullptr) continue;

		Tile *t2 = new Tile(*this, x, y);
		t.neighbour(*t2);
		t2->neighbour(t);

		tiles.v.push_back(t2);
		ap::world->add(t2);
	}

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