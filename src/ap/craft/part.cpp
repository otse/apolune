#include "all.h"

#include "../def.h"

using namespace ap::craft;

ap::craft::Part::Part(Tile &t, const Model m, TYPE type) :
	ap::Sprite(en::GDEF, m.t, m.r) ,
	tile(t),
	craft(t.grid.craft),
	type(type)
	{
	sx(t.gx()*48);
	sy(t.gy()*48);
	world = false;

	em = new Emitter(Emitter::placesparks);
	em->sx(gx()+t.grid.gx()+16);
	em->sy(gy()+t.grid.gy()+16);
	ap::world->add(em);

	fbo = craft.gfbo();
}

ap::craft::Part::~Part() {
	
}

void ap::craft::Part::translate() {
	glTranslatef(
		gx() - (tile.grid.gx2()*48),
		gy() - (tile.grid.gy2()*48), 0.f); // </3
}

void ap::craft::Part::step() {
	Sprite::step();
}

void ap::craft::Part::draw() {
	Sprite::draw();
}

void ap::craft::Part::click() {
	
}

void ap::craft::Part::hover(mou::Hover h) {
	if ( mou::HOVER_IN == h ) {} else {}
}

void ap::craft::Part::connect () {}

void ap::craft::Part::refit () {}

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
/*Part::TYPE ap::craft::Part::gtype() {
	return type;
}*/

//float ap::Ply::gy() {
//	return .0;
//}