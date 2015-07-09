#include "tile.h"

#include "../def.h"


ap::craft::Tile::Tile() :
	ap::Sprite(en::GDEF, &textures::craftgrid, &regions::crafttile) ,
	asd(0)
	{
	scale = 1;
	sw(r->w);
	sh(r->h);
}

ap::craft::Tile::~Tile() {
	
}


void ap::craft::Tile::step() {
	Sprite::step();
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