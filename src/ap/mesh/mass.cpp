#include "stdafx.h"

#include "mass.h"

#include "../def.h"


ap::mesh::Mass::Mass() : ap::Sprite(SORT_UNIMPORTANT, nullptr, &en::regfluke )
	{
	sx(0);
	sy(0);
}

ap::mesh::Mass::~Mass() {

}

void ap::mesh::Mass::step() {

}


/* ###########################
   ## Getters & Setters
   ########################### */
//const Region &ap::mesh::Grid::gnormal() const { return normal; }
//int ap::mesh::Grid::gpoints() const { return points; }

//ap::mesh::Ship &ap::mesh::Grid::gcraft() {
//	return ship;
//}