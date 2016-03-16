#include "label.h"
#include"box.h"

#include "../../en/text.h"
#include "../def.h"
#include "../../boilerplate.h"


using namespace ap::gui;

// ####################
// ## BOX
// ####################

ap::gui::Label::Label(Box *b, const char *l, const char *v, bool button) :
	ap::gui::Element::Element(b) ,
    label(l),
    value(v),
	button(button),

	tlabel(nullptr),
	tvalue(nullptr),
	category(false),
	changeable(false)
{
	slabel(label);
	svalue(value);
	
	lleft = new en::Draws(en::GDEF, &textures::guipieces, &regions::statl);
	lmiddle = new en::Draws(en::GDEF, &textures::guipieces, &regions::statm);
	lright = new en::Draws(en::GDEF, &textures::guipieces, &regions::statr);
	
	vleft = new en::Draws(en::GDEF, &textures::guipieces, &regions::valuel);
	vmiddle = new en::Draws(en::GDEF, &textures::guipieces, &regions::valuem);
	vright = new en::Draws(en::GDEF, &textures::guipieces, &regions::valuer);

	if ( button ) {
		bleft = new en::Draws(en::GDEF, &textures::guipieces, &regions::buttonl);
		bmiddle = new en::Draws(en::GDEF, &textures::guipieces, &regions::buttonm);
		bright = new en::Draws(en::GDEF, &textures::guipieces, &regions::buttonr);
	}
}

ap::gui::Label::~Label() {
	delete tlabel;
	delete tvalue;
	
	delete lleft;
	delete lmiddle;
	delete lright;
	
	if ( button ) {
		delete bleft;
		delete bmiddle;
		delete bright;
	}
	else {
		delete vleft;
		delete vmiddle;
		delete vright;
	}
}

void ap::gui::Label::slabel(const char *q) {
	delete tlabel;
	label = q;
	
	tlabel = new en::Text(en::GDEF, statfont, &en::WHITE, label);
}

void ap::gui::Label::svalue(const char *q) {
	delete tvalue;
	value = q;
	
	//if ( changeable )
		//tvalue = new en::Text(en::GDEF, valuefontchangeable, &en::WHITE, value);
	//else
	
	if ( button )
		tvalue = new en::Text(en::GDEF, buttonfont, &en::WHITE, value);
	else
		tvalue = new en::Text(en::GDEF, valuefont, &en::WHITE, value);
}

void ap::gui::Label::rebuild() {
	using namespace regions;
	
	tlabel->sx(gx()+4);
	tlabel->sy(gy()+3);
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
	
	// value bg
	if ( changeable ) {
		vleft->sx(gx()+4+lwidth+4);
		vleft->sy(gy()+1);

		vmiddle->sx(gx()+4+lwidth+4+3);
		vmiddle->sy(gy()+1);
		vmiddle->sw(vwidth);

		vright->sx(gx()+4+lwidth+4+3+vwidth);
		vright->sy(gy()+1);
	}

	if ( button ) {
		// button bg
		bleft->sx(gx()+4+lwidth+4);
		bleft->sy(gy()+1);

		bmiddle->sx(gx()+4+lwidth+4+3);
		bmiddle->sy(gy()+1);
		bmiddle->sw(vwidth);

		bright->sx(gx()+4+lwidth+4+3+vwidth);
		bright->sy(gy()+1);
	}
	
	sw(4+lwidth+4+3+vwidth+3+1);
	sh(20);

	Element::rebuild();
}

/**
 * shouldnt be called externally
 */
void ap::gui::Label::reposition() {
	Element::reposition();
	
	box->elementy += 20;
	
	if ( category ) {
		box->elementy += 10;
		sy(gy()+10);
	}
	
	rebuild();
}

void ap::gui::Label::step() {
	Element::step();
}

void ap::gui::Label::draw() {
	lleft->draw();
	lmiddle->draw();
	lright->draw();
	
	tlabel->draw();
	
	if ( changeable ) {
		vleft->draw();
		vmiddle->draw();
		vright->draw();
	}

	if ( button ) {
		bleft->draw();
		bmiddle->draw();
		bright->draw();
	}
	
	tvalue->draw();
}

void ap::gui::Label::click() {
	if ( ! button ) return;
	
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

void ap::gui::Label::hover(mou::Hover h) {
	Element::hover(h);
	
	if ( ! button ) return;

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


/* ###########################
   ## Getters & Setters
   ########################### */
/*void ap::gui::Label::sstate(int i) {
	state = i;
}

int ap::gui::Label::gstate() {
	return state;
}*/
//int ap::gui::Stat::s(bool b) {}