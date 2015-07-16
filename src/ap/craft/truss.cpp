#include "truss.h"

#include "../def.h"

using namespace ap::craft;
const Truss::Model Truss::metal = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::trussmetal
		}, /* strength */ 100, /* weight */ 100};

const Truss::Model Truss::angledmetal = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::trussangledmetal
		}, 100, 100};


ap::craft::Truss::Truss(Craft &c, const Model m, int x, int y) : Part(c, m.m, TRUSS) ,
	wall(nullptr),
	outline(nullptr)
	{
	sx(x);
	sy(y);
	// LOG("new truz, region " << m.m.r->x << m.m.r->y << m.m.r->w << m.m.r->h)
	wall = new Wall(gcraft(), Wall::duo);
	wall->sx(x);
	wall->sy(y);

	LOG("our x y is " << gx() << ", " << gy())
	LOG("wall x y is " << wall->gx() << ", " << wall->gy())

}

ap::craft::Truss::~Truss() {
	
}

void ap::craft::Truss::step() {
	Part::step();
}

void ap::craft::Truss::draw() {
	Part::draw();

	if ( nullptr != wall )
		wall->draw();
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
Wall *ap::craft::Truss::gwall() {
	return wall;
}

//float ap::Ply::gy() {
//	return .0;
//}