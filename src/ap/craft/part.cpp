#include "part.h"

#include "../def.h"


ap::craft::Part::Part(int i) :
	ap::Sprite(en::GDEF, &textures::craftgrid, &regions::crafttile) ,
	asd(0)
	{
	//nodraw = true;

}

ap::craft::Part::~Part() {
	
}


void ap::craft::Part::step() {
	Sprite::step();

	if (spawned != -1 ) {
		spawned += delta;
		if ( spawned > ((double) n/20)+0.2 ) {
			sregion(&regions::crafttile);
			spawned = -1;
		}
		else if ( spawned > (double) n/20 ) {
			//nodraw = false;
			sregion(&regions::crafttilenew);
		}
	}
		//LOG("WHAT")
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