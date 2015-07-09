#include "cli.h"

#include "../en/font.h"
#include "../en/text.h"

#include "def.h"



ap::CLI::CLI() : en::Draws(en::GDUMP, nullptr, &en::regfluke) ,
	pane(nullptr)
	{
	sy(440);
	pane = new Draws(en::GDUMP, nullptr, &regions::clipane);
	pane->scolor(&colors::CLIPANE);
	pane->sy(gy());
	add(pane);

	mention("cli");
	mention("did i mention you were pretty? loooooool");
}

ap::CLI::~CLI() {

	pane->remove = true;

	{std::vector<Text *>::iterator it;
	for ( it = texts.begin(); it != texts.end(); it ++) {
		Text *t = *it;
		t->remove = true;
	}}
}

void ap::CLI::mention(const char *q) {
	const Font &f = clifont; // alias

	Text *t = new en::Text(en::GDUMP, f, &en::WHITE, q);
	t->sy(gy()+10+(texts.size()*f.gh()));
	t->sx(10);
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