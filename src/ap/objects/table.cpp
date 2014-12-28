#include "../def.h"

#include "table.h"


using namespace ap::objects;
const Table::Model Table::bone = {
		(en::Draws::Model) {
			&textures::bonetable,
			&regions::bonetable
		}};

const Table::Model Table::apexcool = {
		(en::Draws::Model) {
			&textures::apexcooltable,
			&regions::apexcooltable
		}};
		
ap::objects::Table::Table(const Table::Model m) :
	ap::Object::Object(en::GDEF, m.m.t, m.m.r) ,
	m(m)
	{
	//tip = "It looks comfy.";
}

ap::objects::Table::~Table() {}

/*
void ap::objects::Table::left() { Object::left(); }
void ap::objects::Table::right() { Object::right(); }
void ap::objects::Table::in() { Object::in(); }
void ap::objects::Table::out() { Object::out(); }
*/

void ap::objects::Table::step() {
	Object::step();
	
	//if ( ) {}
}

void ap::objects::Table::activate() {
	Object::activate();
}