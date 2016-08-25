#include "stdafx.h"

#include "cli.h"

#include "../en/font.h"
#include "../en/text.h"

#include "def.h"



ap::CLI::CLI() : en::Draws(en::GDUMP, nullptr, &en::regfluke) ,
	pane(nullptr)
	{

	en::Region *rr = new (en::Region) {0,0,en::width,160};
	r = rr;

	sy(en::height-r->h);
	sh(r->h);
	pane = new Draws(en::GDUMP, nullptr, r);
	pane->scolor(&colors::CLIPANE);
	pane->sy(gy());
	add(pane);

	mention( "-~=\\ apolune /=~-" );
	mention( "| running world" );
	mention( "| doing stuff..." );
}

ap::CLI::~CLI() {
	delete r;
	pane->remove = true;
	
	{std::vector<Text *>::iterator it;
	for ( it = texts.begin(); it != texts.end(); it ++) {
		Text *t = *it;
		t->remove = true;
	}}
}

void ap::CLI::slide() {

}

void ap::CLI::mention(const char *q) {
	std::string* str = new std::string(q);

	const Font &f = clifont; // alias

	Text *t = new en::Text(en::GDUMP, f, &en::WHITE, str->c_str());
	int l = texts.size();
	int s = (str->at(0)=='|')?11:0;
	t->sy(gy()+10+(l*f.gh())+l);
	t->sx(7+s);
	t->position();
	add(t);

	texts.push_back(t);
}

/*void ap::CLI::aa() {

}*/

/* ###########################
   ## Getters & Setters
   ########################### */
//void ap::CLI::get(bool b) {
//	world = b;
//}