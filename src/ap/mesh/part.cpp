#include "stdafx.h"

#include "part.h"

#include "../def.h"
#include "../world.h"

#include "mass.h"


using namespace ap::mesh;

ap::mesh::Part::Part(FIXTURE f, Tile &t, sort_t s) :
	ap::Sprite(s, nullptr, &en::regfluke) ,
	fixture(f),
	tile(t),
	SEETHROUGH(false)
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

void* ap::mesh::Part::reach() {
	// quad
	if (TOP && RIGHT && BOTTOM && LEFT) {
		static const Attitude attitude{ 0, QUAD };
		return (void*) &attitude;
	}

	// tri
	else if (TOP && RIGHT && BOTTOM) {
		static const Attitude attitude{ 0, TRI };
		return (void*) &attitude;
	}
	else if (RIGHT && BOTTOM && LEFT) {
		static const Attitude attitude{ 90, TRI };
		return (void*) &attitude;
	}
	else if (BOTTOM && LEFT && TOP) {
		static const Attitude attitude{ 180, TRI };
		return (void*) &attitude;
	}
	else if (LEFT && TOP && RIGHT) {
		static const Attitude attitude{ 270, TRI };
		return (void*) &attitude;
	}

	// duo
	else if (TOP && RIGHT) {
		static const Attitude attitude{ 0, DUO };
		return (void*) &attitude;
	}
	else if (RIGHT && BOTTOM) {
		static const Attitude attitude{ 90, DUO };
		return (void*) &attitude;
	}
	else if (BOTTOM && LEFT) {
		static const Attitude attitude{ 180, DUO };
		return (void*) &attitude;
	}
	else if (LEFT && TOP) {
		static const Attitude attitude{ 270, DUO };
		return (void*) &attitude;
	}

	// opposite
	else if (TOP && BOTTOM) {
		static const Attitude attitude{ 0, OPPOSITE };
		return (void*) &attitude;
	}
	else if (LEFT && RIGHT) {
		static const Attitude attitude{ 90, OPPOSITE };
		return (void*) &attitude;
	}

	// uni
	else if (TOP) {
		static const Attitude attitude{ 0, UNI };
		return (void*) &attitude;
	}
	else if (RIGHT) {
		static const Attitude attitude{ 90, UNI };
		return (void*) &attitude;
	}
	else if (BOTTOM) {
		static const Attitude attitude{ 180, UNI };
		return (void*) &attitude;
	}
	else if (LEFT) {
		static const Attitude attitude{ 270, UNI };
		return (void*) &attitude;
	}

	// single
	else {
		static const Attitude attitude{ 0, SINGLE };
		return (void*) &attitude;
	}
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