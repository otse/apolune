#include "grid.h"
#include "all.h"

#include "../def.h"
#include "tile.h"



ap::craft::Grid::Grid(Craft &o) : ap::Sprite(en::GDEF, nullptr, &en::regfluke ) ,
	craft(o)
	{
	sx(craft.gx());
	sy(craft.gy());

	//LOG ( "is empty " << tilesum.size() )
}

ap::craft::Grid::~Grid() {

}

ap::craft::Tile &ap::craft::Grid::mtile(int x, int y) {

	Tile *t = new Tile(*this, x, y);

	std::string xy = std::to_string(x) + "," + std::to_string(y);
	std::pair<std::string, Tile *> teddybear(xy, t);

	tilesum.insert(teddybear);

	ap::world->add(t);

	return *t;
}

void ap::craft::Grid::expandfrom(Tile &t) {
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

	t.link();

}


void ap::craft::Grid::step() {

}


/* ###########################
   ## Getters & Setters
   ########################### */
//ap::craft::Craft &ap::craft::Grid::gcraft() {
//	return craft;
//}