#include "stdafx.h"

#include "../../en/fbo.h"

#include "ship.h"
#include "truss.h"
#include "../mesh/block.h"

using namespace ap::ship;
using namespace ap::mesh;

ap::ship::Ship::Ship() : Mass() ,
	crosssection(true)
	{
	
	Tile &zero = *grid.gtile(0,0);
	Block *p = new Block(zero);
	zero.attach(p);

	//t2.attach(p);

	//crosssection = true;
}

ap::ship::Ship::~Ship() {

}

void ap::ship::Ship::step() {
	Mass::step();

	//sprite->rotate += 0.001;
}


void ap::ship::Ship::click() {}
void ap::ship::Ship::hover(mou::Hover h) {}


/* ###########################
   ## Getters & Setters
   ########################### */


//float ap::Ply::gy() {
//	return .0;
//}