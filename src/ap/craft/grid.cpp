#include "grid.h"
#include "all.h"

#include "../def.h"
#include "tile.h"



ap::craft::Grid::Grid(Craft &o) : ap::Sprite(en::GDEF, nullptr, &en::regfluke ) ,
	craft(o),
	x2(0),
	y2(0),
	w2(0),
	h2(0)
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

	if ( t.gx() < x2 ) x2 = t.gx();
	if ( t.gy() < y2 ) y2 = t.gy();
	if ( t.gx() > w2 ) w2 = t.gx();
	if ( t.gy() > h2 ) h2 = t.gy();

	craft.gfbo()->x = x2*48;
	craft.gfbo()->y = y2*48;

	//LOG("grid expands to x:" << x2 << ", y:" << y2 << ", w:" << w2 << ", h:" << h2)

	t.link();
}


void ap::craft::Grid::step() {

}


/* ###########################
   ## Getters & Setters
   ########################### */
int ap::craft::Grid::gx2() { return x2; }
int ap::craft::Grid::gy2() { return y2; }
int ap::craft::Grid::gw2() { return w2; }
int ap::craft::Grid::gh2() { return h2; }

int *ap::craft::Grid::gdims() {
	int ww = w2;
	int hh = h2;

	if ( x2 < 0 )
		ww += -x2;

	if ( y2 < 0 )
		hh += -y2;

	dims[0] = ww+1;
	dims[1] = hh+1;

	return dims;
}

//ap::craft::Craft &ap::craft::Grid::gcraft() {
//	return craft;
//}