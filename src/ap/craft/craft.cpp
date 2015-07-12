#include "craft.h"


ap::craft::Craft::Craft() : ap::Sprite(en::GDEF, nullptr, &en::regfluke ) ,
	asd(0)
	{
	
}

ap::craft::Craft::~Craft() {

}

void ap::craft::Craft::step() {}

void ap::craft::Craft::click() {}

void ap::craft::Craft::hover(mou::Hover h) {
	
	if ( mou::HOVER_IN == h ) {
		//sregion(&regions::craft::tileover);
	} else {
		//sregion(&regions::craft::tile);
	}

}


/* ###########################
   ## Getters & Setters
   ########################### */
//void ap::craft::Grid::sgrid(int c, int r) {
	//cols = c;
	//rows = r;

	//table();
//}

//float ap::Ply::gy() {
//	return .0;
//}