#include "tile.h"

#include "../def.h"


ap::craft::Tile::Tile(int i) :
	ap::Sprite(en::GDEF, &textures::craftgrid, &regions::crafttile) ,
	n(i),
	spawned(0),
	asd(0)
	{
	//nodraw = true;
	scale = 1;

	sw(r->w);
	sh(r->h);
}

ap::craft::Tile::~Tile() {
	
}


void ap::craft::Tile::step() {
	Sprite::step();

	if (spawned != -1 ) {
		spawned += delta;
		if ( spawned > ((double) n/20)+0.2 ) {
			sregion(&regions::crafttile);
			spawned = -1;
		}
		else if ( spawned > (double) n/20 ) {
			//nodraw = false;
			sregion(&regions::crafttileover);
		}
	}
		//LOG("WHAT")
}

void ap::craft::Tile::click() {

}


void ap::craft::Tile::hover(mou::Hover h) {
	
	if ( mou::HOVER_IN == h ) {
		sregion(&regions::crafttileover);
	} else {
		sregion(&regions::crafttile);
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