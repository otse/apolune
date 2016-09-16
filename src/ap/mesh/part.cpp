#include "stdafx.h"

#include "part.h"

#include "../def.h"
#include "../world.h"
#include "../ship/all.h"

using namespace ap::mesh;

ap::mesh::Part::Part(Tile &t, const Model m, TYPE type) :
	ap::Sprite(SORT_UNIMPORTANT, m.t, m.r) ,
	tile(t),
	type(type)
	{
	sx(t.gx()*t.grid.gpoints());
	sy(t.gy()*t.grid.gpoints());
	world = false;

	em = new Emitter(Emitter::placesparks);
	em->sx(gx()+t.grid.gx()+ (t.grid.gpoints()/2));
	em->sy(gy()+t.grid.gy()+ (t.grid.gpoints()/2));
	ap::world->add(em);

	// refactorate
	fbo = t.grid.mass.gobf();

	t.attach(this);
}

ap::mesh::Part::~Part() {
	
}

void ap::mesh::Part::step() {
	Sprite::step();
}

void ap::mesh::Part::draw() {
	Sprite::draw();
}

void ap::mesh::Part::click() {
	
}

void ap::mesh::Part::hover(mou::Hover h) {
	if ( mou::HOVER_IN == h ) {} else {}
}

void ap::mesh::Part::connect () {}

void ap::mesh::Part::refit () {}

	/*Part *top = (tile.gtop() && tile.gtop()->gpart()) ? tile.gtop()->gpart() : nullptr;
	Part *bottom = (tile.gbottom() && tile.gbottom()->gpart()) ? tile.gbottom()->gpart() : nullptr;
	Part *left = (tile.gleft() && tile.gleft()->gpart()) ? tile.gleft()->gpart() : nullptr;
	Part *right = (tile.gright() && tile.gright()->gpart()) ? tile.gright()->gpart() : nullptr;*/

	/*if ( !(top && top->gtype() == TRUSS && dynamic_cast<Truss *>(top)->gwall()) ) top = nullptr;
	if ( !(bottom && bottom->gtype() == TRUSS && dynamic_cast<Truss *>(bottom)->gwall()) ) bottom = nullptr;
	if ( !(left && left->gtype() == TRUSS && dynamic_cast<Truss *>(left)->gwall()) ) left = nullptr;
	if ( !(right && right->gtype() == TRUSS && dynamic_cast<Truss *>(right)->gwall()) ) right = nullptr;*/


/* ###########################
   ## Getters & Setters
   ########################### */
/*Part::TYPE ap::mesh::Part::gtype() {
	return type;
}*/

//float ap::Ply::gy() {
//	return .0;
//}