#include "box.h"

#include "all.h"
#include "../def.h"

ap::gui::Box::Box() :
	en::Draws::Draws(en::GGUI, nullptr, &en::regfluke) ,
	reposition(true),
	elementy(0)
{
	r = new en::Region;
	scolor(&colors::GUIGRAY);
	//r = new (en::Region) {0,0,0,0};
}

ap::gui::Box::~Box() {
	delete r;
}

void ap::gui::Box::resize(int w, int h) {
	sw(w);
	sh(h);
	
	//int W = textures::apexbrainjar.gw();
	//int H = textures::apexbrainjar.gh();
	//*r = (en::Region) {0,0,W,H};
}

void ap::gui::Box::add(Element *p) {
	e.push_back(p);
	elementy = 0;
	reposition = true;
}

void ap::gui::Box::rm(Element *p) {
	if ( nullptr == p )
		return;
	
	std::vector<Element *>::iterator it = e.begin();
	for ( ; it < e.end(); it ++) {
		if ( *it == p ) {
			e.erase(it);
			break;
		}
	}
}

void ap::gui::Box::step() {
	std::vector<Element *>::iterator it = e.begin();
	for ( ; it < e.end(); it ++) {
		Element *e = *it;
		if ( reposition )
			e->reposition();
		e->step();
	}
	reposition = false;
	elementy = 0;
}

void ap::gui::Box::draw() {
	Draws::draw();
	
	std::vector<Element *>::iterator it;
	for ( it = e.begin(); it < e.end(); it ++) {
		Element *e = *it;
		e->draw();
	}
}