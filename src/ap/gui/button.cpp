#include "button.h"


#include "../../boilerplate.h"
#include "../../en/text.h"
#include "../def.h"
#include"box.h"


ap::gui::Button::Button(Box *b, const char *l, const char *v, t_click c) :
	ap::gui::Label::Label(b, l, v) ,
	bleft(nullptr) ,
	onclick(c)
{
	bleft = new en::Draws(en::GDEF, &textures::guipieces, &regions::buttonl);
	bmiddle = new en::Draws(en::GDEF, &textures::guipieces, &regions::buttonm);
	bright = new en::Draws(en::GDEF, &textures::guipieces, &regions::buttonr);
}

ap::gui::Button::~Button() {
	delete bleft;
	delete bmiddle;
	delete bright;
}

void ap::gui::Button::rebuild() {
	using namespace regions;
	
	tlabel->sx(gx()+4);
	tlabel->sy(gy()+2);
	tlabel->position();
	int lwidth = tlabel->gtextw() + 1;
	
	tvalue->sx(gx()+4+lwidth+4+3);
	tvalue->sy(gy()+3);
	tvalue->position();
	int vwidth = tvalue->gtextw();
	
	// label bg
	lleft->sx(gx());
	lleft->sy(gy());
	
	lmiddle->sx(gx()+statl.w);
	lmiddle->sy(gy());
	lmiddle->sw(4-statl.w+lwidth+4+3+vwidth+3+1-4);
	
	lright->sx(gx()+lwidth+2+vwidth+8+3-2);
	lright->sy(gy());
	
	// button bg
	bleft->sx(gx()+4+lwidth+4);
	bleft->sy(gy()+1);

	bmiddle->sx(gx()+4+lwidth+4+3);
	bmiddle->sy(gy()+1);
	bmiddle->sw(vwidth);

	bright->sx(gx()+4+lwidth+4+3+vwidth);
	bright->sy(gy()+1);
	
	sw(4+lwidth+4+3+vwidth+3+1);
	sh(20);

	Element::rebuild();
}

/**
 * shouldnt be called externally
 */
void ap::gui::Button::reposition() {
	Element::reposition();
	
	box->elementy += 20;
	
	if ( category ) {
		box->elementy += 10;
		sy(gy()+10);
	}
	
	rebuild();
}

void ap::gui::Button::step() {
	Draws::step();
}

void ap::gui::Button::draw() {
	//lleft->draw();
	//lmiddle->draw();
	//lright->draw();
	
	tlabel->draw();
	
	bleft->draw();
	bmiddle->draw();
	bright->draw();
	
	tvalue->draw();
}

void ap::gui::Button::click() {
	if ( &mou::left == mou::active ) {
		if ( mou::PRESSED == *mou::active ) {
			bleft->sregion(&regions::buttonlpressed);
			bmiddle->sregion(&regions::buttonmpressed);
			bright->sregion(&regions::buttonrpressed);
		}
		else if ( mou::RELEASED == *mou::active ) {
			if ( nullptr != this->onclick )
				this->onclick();
			
			bleft->sregion(&regions::buttonlhover);
			bmiddle->sregion(&regions::buttonmhover);
			bright->sregion(&regions::buttonrhover);
		}		
	}
}

void ap::gui::Button::hover(mou::Hover h) {
	Element::hover(h);
	
	if ( mou::HOVER_IN == h ) {
		if ( ! held ) {
			bleft->sregion(&regions::buttonlhover);
			bmiddle->sregion(&regions::buttonmhover);
			bright->sregion(&regions::buttonrhover);
		} else {
			bleft->sregion(&regions::buttonlpressed);
			bmiddle->sregion(&regions::buttonmpressed);
			bright->sregion(&regions::buttonrpressed);
		}
	} else {
		bleft->sregion(&regions::buttonl);
		bmiddle->sregion(&regions::buttonm);
		bright->sregion(&regions::buttonr);
	}
}

void ap::gui::Button::svalue(const char *q) {
	delete tvalue;
	value = q;
	
	//if ( changeable )
		//tvalue = new en::Text(en::GDEF, valuefontchangeable, &en::WHITE, value);
	//else
	
	tvalue = new en::Text(en::GDEF, buttonfont, &en::WHITE, value);
}

/* ###########################
   ## Getters & Setters
   ########################### */
/*void ap::gui::Button::sstate(int i) {
	state = i;
}

int ap::gui::Button::gstate() {
	return state;
}*/
//int ap::gui::Stat::s(bool b) {}