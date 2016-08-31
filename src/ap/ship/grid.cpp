#include "stdafx.h"

#include "grid.h"
#include "all.h"

#include "../def.h"
#include "tile.h"



ap::ship::Grid::Grid(Ship &o) : ap::Sprite(en::GDEF, nullptr, &en::regfluke ) ,
	craft(o),
	normal( {0,0,0,0} )
	{
	sx(craft.gx());
	sy(craft.gy());

	//LOG ( "is empty " << tilesum.size() )
}

ap::ship::Grid::~Grid() {
	
}

ap::ship::Tile &ap::ship::Grid::mtile(int x, int y) {

	Tile *t = new Tile(*this, x, y);

	std::string xy = std::to_string(x) + "," + std::to_string(y);
	std::pair<std::string, Tile *> teddybear(xy, t);

	tilesum.insert(teddybear);

	ap::world->add(t);

	return *t;
}

void ap::ship::Grid::expandfrom(Tile &t) {
	for (int i = 0; i < 8; i ++) {
		int x = t.gx(), y = t.gy();

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

		std::unordered_map<std::string, Tile *>::const_iterator got = tilesum.find(xy);
		
		if ( got == tilesum.end() )
			mtile(x, y);

	}

	const Region &n = normal; // alias

	if ( t.gx() < normal.x ) normal.x = t.gx();
	if ( t.gy() < normal.y ) normal.y = t.gy();
	if ( t.gx() > normal.w ) normal.w = t.gx();
	if ( t.gy() > normal.h ) normal.h = t.gy();

	t.link();
}


void ap::ship::Grid::step() {

}


/* ###########################
   ## Getters & Setters
   ########################### */
const Region &ap::ship::Grid::gnormal() { return normal; }

//ap::ship::Ship &ap::ship::Grid::gcraft() {
//	return ship;
//}