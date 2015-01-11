#include "bar.h"

using namespace en;

lau::Bar::Bar() : en::Draws(GDEF, nullptr, &en::regfluke) ,
	progress(0),
	rbar( {0, 0, 100, 74} ),
	wit(""),
	lowtext(nullptr),
	text(nullptr)
	{
		
	stars = new Draws(GDEF, &lau::stars, &lau::rstars);
	starsl = new Draws(GDEF, &lau::starssides, &lau::rstarsl);
	starsr = new Draws(GDEF, &lau::starssides, &lau::rstarsr);
	
	barfbo = new en::FBO(&BLACK, rbg);
	barfbo->gdraws().sregion(&rbar);
	
	rewit("moored in space 0km/h");
	
}

lau::Bar::~Bar() {
	
}

void lau::Bar::rewit(const char *q) {
	wit.assign(q);
	delete lowtext;
	delete text;
	
	lowtext = new Text(GDEF, backfont, &WHITE, q);
	lowtext->sx(30);
	lowtext->sy(30);
	lowtext->position();
	
	text = new Text(GDEF, barfont, &WHITE, q);
	text->sx(30);
	text->sy(30);
	text->position();
}

void lau::Bar::step() {
	
	// make progress
	progress += 2;
	
	if ( progress > 500 ) {
		progress = 500;
		rewit("running apolune.exe");
		system("apolune.exe");
		
		exit(0);
	}
	
	// set bar	
	starsr->sx( progress -2);
	barfbo->gdraws().sw( progress );
	rbar.w = progress;
}

void lau::Bar::draw() {
	lowtext->draw();
	
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, barfbo->gfbid() );
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
	
	stars->draw();
	starsl->draw();
	starsr->draw();
	text->draw();
	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // revert to standard blending
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	
	barfbo->gdraws().draw();
}