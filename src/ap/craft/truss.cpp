#include "truss.h"

#include "../def.h"

using namespace ap::craft;
const Truss::Model Truss::metal = {
		(en::Draws::Model) {
			&textures::truss,
			&regions::craft::trussmetal
		}, /* strength */ 100, /* weight */ 100};


ap::craft::Truss::Truss(const Model m) : Part(m.m) ,
	x(0)
	{
	LOG("new truz, region " << m.m.r->x << m.m.r->y << m.m.r->w << m.m.r->h)
	//nodraw = true;

}

ap::craft::Truss::~Truss() {
	
}


void ap::craft::Truss::step() {
	Part::step();


}

void ap::craft::Truss::click() {
	
}


void ap::craft::Truss::hover(mou::Hover h) {
	if ( mou::HOVER_IN == h ) {
		
	} else {
		
	}
}


/* ###########################
   ## Getters & Setters
   ########################### */
//void ap::craft::Tile::sgrid(int c, int r) {
	//cols = c;
	//rows = r;

	//table();
//}

//float ap::Ply::gy() {
//	return .0;
//}