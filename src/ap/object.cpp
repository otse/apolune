#include "object.h"
#include "../en/font.h"
#include "../en/text.h"
#include "ply.h"
#include "def.h"

ap::Object::Object(en::Group g, en::Texture *t, en::Region *r) :
	ap::Sprite::Sprite(g, t, r) ,
	activaterange(0)//,
	//tooltip(nullptr),
	//thovering(0)
	{
	//tip = "It's an object";
}

ap::Object::~Object() {

}

void ap::Object::step() {
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
	
	
	/*thovering = 0;
	
	if ( tooltip ) {
		rm(tooltip);
		delete tooltip;
		tooltip = nullptr;
		//LOG("destroyed tooltip");
	}*/
}

/*
void ap::Object::tooltipping() {
	thovering += en::delta;
	
	if ( thovering >= 0.35 ) {
		if ( ! tooltip ) {
			//LOG("making tooltip");
			tooltip = new en::Text(&monospace, &en::WHITE, tip);
			tooltip->sscale(2.D);
			tooltip->sx( gscrx() + (monospace.gh()) );
			tooltip->sy( gscry() - (monospace.gh()*2) );
			tooltip->position();
			ap::add( tooltip );
		}
		else {
			tooltip->sx( gscrx() + (monospace.gh()) );
			tooltip->sy( gscry() -(monospace.gh()*2) );
			tooltip->position();
		}
	}
}
*/