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
	
}

// XxX_BakrexzzDE11IGHTZZ4201337_Xx
void ap::gui::Element::reposition() {
	sx(box->gx());
	sy(box->gy()+box->elementy);
}

void ap::gui::Element::draw() {}

void ap::gui::Element::click(en::Button b, en::Click c) {}
void ap::gui::Element::hover(en::Hover h) {}