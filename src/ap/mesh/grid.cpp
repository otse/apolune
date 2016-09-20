#include "stdafx.h"

#include "../def.h"

#include "mesh.h"
#include "grid.h"


ap::mesh::Grid::Grid(Mass &mass, int points, Draws::Model m) : ap::Sprite(SORT_UNIMPORTANT, nullptr, &en::regfluke),
	mass(mass),
	tilemodel(m),
	points(points),
	normal( {0,0,0,0} ),
	enabled(false)
	{
	mtile(0, 0);

	sx(0);
	sy(0);

	//LOG ( "is empty " << tilesum.size() )
}

ap::mesh::Grid::~Grid() {
	
}

ap::mesh::Tile *ap::mesh::Grid::gtile(int x, int y) {
	std::string xy = std::to_string(x) + "," + std::to_string(y);

	std::unordered_map<std::string, Tile *>::const_iterator got = tilesum.find(xy);

	if (got != tilesum.end())
		return got->second;
	else
		return nullptr;
}

ap::mesh::Tile &ap::mesh::Grid::mtile(int x, int y) {

	Tile *t = new Tile(*this, tilemodel, x, y);

	std::string xy = std::to_string(x) + "," + std::to_string(y);
	std::pair<std::string, Tile *> teddybear(xy, t);

	tilesum.insert(teddybear);

	ap::world->add(t);

	return *t;
}

void ap::mesh::Grid::expandfrom(Tile &t) {

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

	//t.link();
}


void ap::mesh::Grid::step() {

}


/* ###########################
   ## Getters & Setters
   ########################### */
const Region &ap::mesh::Grid::gnormal() const { return normal; }
int ap::mesh::Grid::gpoints() const { return points; }

//ap::mesh::Ship &ap::mesh::Grid::gcraft() {
//	return ship;
//}