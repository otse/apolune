#include "stdafx.h"

#include "element.h"
#include "box.h"

#include "../def.h"

using namespace en;

ap::gui::Element::Element(Box *b) :
    en::Draws::Draws(en::GGUI, nullptr, &regfluke) ,
    box(b)
	//reposition(false)
{
	
}

ap::gui::Element::~Element() {}

void ap::gui::Element::step() {
	Draws::step();
}

void ap::gui::Element::rebuild() {
	if ( nullptr != box ) {
		int h = box->elementy;

		if ( gw() > box->gw() ) box->sw(gw());
		if ( h > box->gh() ) box->sh(h);
	}
}

// XxX_BakrexzzDE11IGHTZZ4201337_Xx
void ap::gui::Element::reposition() {
	sx(box->gx());
	sy(box->gy()+box->elementy);
}


void ap::gui::Element::draw() {}

void ap::gui::Element::click() {}
void ap::gui::Element::hover(mou::Hover h) {}

/* ###########################
   ## Getters & Setters
   ########################### */
ap::gui::Box *ap::gui::Element::gbox() {
	return box;
}