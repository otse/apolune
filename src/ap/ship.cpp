#include <iostream>
#include <cmath>

#include "../h.h"
#include "ship.h"

using namespace en;

ap::Ship::Ship(const char *n, Texture *t, Region *r)
	: ap::Mover::Mover(SHIP,en::GDEF,t,r) ,
	name(n)
	{
	
	
}

ap::Ship::~Ship() { // dtor
	
}

/* ###########################
   ## Getters & Setters
   ########################### */
//float ap::Ply::gx() {
//	return .0;
//}

//float ap::Ply::gy() {
//	return .0;
//}