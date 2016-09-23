#include "stdafx.h"

#include "part.h"

#include "../def.h"
#include "../world.h"

#include "mass.h"


using namespace ap::mesh;

ap::mesh::Part::Part(FIXTURE f, Tile &t) :
	ap::Sprite(SORT_UNIMPORTANT, nullptr, &en::regfluke) ,
	fixture(f),
	tile(t)
	{
	std::fill_n(bools, 8, false);

	sx(t.gx()*t.grid.gpoints());
	sy(t.gy()*t.grid.gpoints());

	world = false;

	em = new Emitter(Emitter::placesparks);
	em->sx(gx()+t.grid.gx()+ (t.grid.gpoints()/2));
	em->sy(gy()+t.grid.gy()+ (t.grid.gpoints()/2));
	ap::world->add(em);

	fbo = t.grid.mass.gobf();

	// t.attach(this); // commented out until we change Wall to not extend Part, or make a special rule for background-parts

}

ap::mesh::Part::~Part() {
	
}

void ap::mesh::Part::step() {
	Sprite::step();
}

void ap::mesh::Part::draw(PASS p) {
	if (FORE == fixture && p == FOREGROUND_PASS || AFT == fixture && p == BACKGROUND_PASS )
		Sprite::draw();
}

void ap::mesh::Part::click() {
	
}

void ap::mesh::Part::hover(mou::Hover h) {
	if ( mou::HOVER_IN == h ) {} else {}
}

void ap::mesh::Part::connect () {
	Tile **all = tile.gneighbors();

	for (int i = 0; i < 8; i++) {
		Tile *t = all[i];

		if (nullptr == t)
			continue;

		_ASSERT(t);

		if (auto p = t->gpart(fixture))
			p->refit();
	}

	refit();
}

void ap::mesh::Part::refit () {

}

/* ###########################
   ## Getters & Setters
   ########################### */
/*Part::TYPE ap::mesh::Part::gtype() {
	return type;
}*/

//float ap::Ply::gy() {
//	return .0;
//}