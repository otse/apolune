#include "stdafx.h"

#include "object.h"

#include "ply.h"
#include "def.h"

ap::Object::Object(en::sort_t g, en::Texture *t, en::Region *r) :
	ap::Sprite::Sprite(g, t, r) ,
	activaterange(0),
	thovering(0),
	tip(nullptr)
	{

}

ap::Object::~Object() {

}

void ap::Object::step() {
	Sprite::step();

	if ( ply->guse() )
		tryactivate();
}

void ap::Object::tryactivate() {

	int px = ply->gx();
	int py = ply->gy();
	int pw = ply->gw();
	int ph = ply->gh();
	
	if (
		gx() >= px && gx() < px+pw &&
		gy() >= py && gy() < py+ph
	) {
		activate();
	}
}

void ap::Object::activate() {
	// loooooool
}

void ap::Object::click() { /*Sprite::left();*/ }

void ap::Object::hover(mou::Hover h) {

}