#include "stdafx.h"

#include "all.h"

#include "../def.h"

using namespace ap::ship;

ap::ship::Part::Part(Tile &t, const Model m, TYPE type) :
	ap::Sprite(en::GDEF, m.t, m.r) ,
	tile(t),
	craft(t.grid.craft),
	type(type)
	{
	sx(t.gx()*16);
	sy(t.gy()*16);
	world = false;

	em = new Emitter(Emitter::placesparks);
	em->sx(gx()+t.grid.gx()+16);
	em->sy(gy()+t.grid.gy()+16);
	ap::world->add(em);

	fbo = craft.gfbo();
}

ap::ship::Part::~Part() {
	
}

void ap::ship::Part::step() {
	Sprite::step();
}

void ap::ship::Part::draw() {
	Sprite::draw();
}

void ap::ship::Part::click() {
	
}

void ap::ship::Part::hover(mou::Hover h) {
	if ( mou::HOVER_IN == h ) {} else {}
}

void ap::ship::Part::connect () {}

void ap::ship::Part::refit () {}

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
/*Part::TYPE ap::ship::Part::gtype() {
	return type;
}*/

//float ap::Ply::gy() {
//	return .0;
//}