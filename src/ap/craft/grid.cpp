#include "grid.h"
#include "all.h"

#include "../def.h"
#include "tile.h"



ap::craft::Grid::Grid(Craft &o) : ap::Sprite(en::GDEF, nullptr, &en::regfluke ) ,
	craft(o),
	normal( {0,0,0,0} )
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

	const Region &n = normal; // alias

	if ( t.gx() < normal.x ) normal.x = t.gx();
	if ( t.gy() < normal.y ) normal.y = t.gy();
	if ( t.gx() > normal.w ) normal.w = t.gx();
	if ( t.gy() > normal.h ) normal.h = t.gy();

	craft.gfbo()->x = x2*48;
	craft.gfbo()->y = y2*48;

	int ww = w2;
	int hh = h2;

	if ( x2 < 0 ) ww += -x2;
	if ( y2 < 0 ) hh += -y2;

	normal[0] = ww+1;
	normal[1] = hh+1;

	//LOG("grid expands to x:" << x2 << ", y:" << y2 << ", w:" << w2 << ", h:" << h2)

	t.link();
}


void ap::craft::Grid::step() {

}


/* ###########################
   ## Getters & Setters
   ########################### */
const Region &ap::craft::Grid::gnormal() { return normal; }

//ap::craft::Craft &ap::craft::Grid::gcraft() {
//	return craft;
//}