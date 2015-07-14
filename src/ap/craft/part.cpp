#include "part.h"

#include "../def.h"


ap::craft::Part::Part(const Model m) :
	ap::Sprite(en::GDEF, m.t, m.r) ,
	x(0)
	{
	world = false;
	//nodraw = true;

}

ap::craft::Part::~Part() {
	
}


void ap::craft::Part::step() {
	Sprite::step();
}

void ap::craft::Part::click() {
	
}


void ap::craft::Part::hover(mou::Hover h) {
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