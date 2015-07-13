#include "truss.h"

#include "../def.h"


ap::craft::Truss::Truss(const Model m) :
	Part(m) ,
	x(0)
	{
	LOG("new part")
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