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

lau::Bar::~Bar() {}

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
	static bool starting = false;
	static int wait = 0;
	// make progress
	
	// this needs delta timing looooool
	if ( progress < 500 ) {
		progress += en::delta * 60;
	}


	
	if (1==wait) {
		using namespace sf;
		
		sleep( seconds(.5) );
		
		spawnl(P_NOWAIT, "apolune.exe", "apolune.exe", NULL, 0, NULL);
		
		sleep( seconds(1) );
		
		wait = 2;
		
		exit(0);
	}
	
	if (!starting && progress >= 500) {
		progress = 500;
		rewit("launching game");
		//system("apolune.exe &");
		wait = 1;
		starting = true;
	}
	
	
	// set bar	
	starsr->sx( (int) progress -2);
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