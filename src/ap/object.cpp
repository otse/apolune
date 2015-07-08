#include "object.h"
#include "../en/font.h"
#include "../en/text.h"
#include "ply.h"
#include "def.h"

ap::Object::Object(en::Group g, en::Texture *t, en::Region *r) :
	ap::Sprite::Sprite(g, t, r) ,
	activaterange(0),
	tooltip(nullptr),
	thovering(0),
	tip(nullptr)
	{
		
}

ap::Object::~Object() {

}

void ap::Object::step() {
	Sprite::step();

	if ( hovering )
		tooltipping();

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
	
	if ( mou::HOVER_IN == h ) { 
		scolor(&colors::OBJECTHOVER);
	} else {
		scolor(&en::WHITE);
	}

	thovering = 0;
	
	if ( tooltip ) {
		rm(tooltip);
		delete tooltip;
		tooltip = nullptr;
		LOG("destroyed tooltip");
	}
}

void ap::Object::tooltipping() {
	thovering += en::delta;
	
	if ( thovering >= 0.35 ) {
		if ( ! tooltip ) {
			LOG("making tooltip")
			tooltip = new en::Text(en::GDUMP, monospace2, &en::WHITE, tip);
			tooltip->scale = 2;
			tooltip->position();

			tooltip->sx( gscrx() + (monospace2.gh()) );
			tooltip->sy( gscry() - (monospace2.gh()*2) );
			tooltip->position();
			add( tooltip );
		}
		else {
			tooltip->sx( gscrx() + (monospace2.gh()) );
			tooltip->sy( gscry() -(monospace2.gh()*2) );
			tooltip->position();
		}
	}
}