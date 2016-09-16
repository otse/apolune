#include "stdafx.h"

#include "ship.h"

#include "../../en/fbo.h"

using namespace ap::ship;
using namespace ap::mesh;

ap::ship::Ship::Ship() : Mass() ,
	crosssection(true)
	{
	
	/*
	Truss *p = new Truss(t2);
	t2.attach(p);*/

	//crosssection = true;
}

ap::ship::Ship::~Ship() {

}

void ap::ship::Ship::step() {
	Mass::step();

	//sprite->rotate += 0.001;
}


void ap::ship::Ship::clicked(Tile &t) {
	
}


void ap::ship::Ship::click() {}
void ap::ship::Ship::hover(mou::Hover h) {}


/* ###########################
   ## Getters & Setters
   ########################### */


//float ap::Ply::gy() {
//	return .0;
//}