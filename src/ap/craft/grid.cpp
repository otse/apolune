#include "grid.h"


ap::craft::Grid::Grid() : ap::Sprite(en::GDEF, nullptr, &en::regfluke ) ,
	asd(0)
	{
	//LOG("planet ctor")
	//this->world = true;
}

ap::craft::Grid::~Grid() {}

//void ap::craft::Grid::size() {}

void ap::craft::Grid::step() {
	// check mice things
}


/* ###########################
   ## Getters & Setters
   ########################### */
//ap::craft::Grid::Type ap::craft::Grid::gtype(){ return type; }

//float ap::Ply::gy() {
//	return .0;
//}