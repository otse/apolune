#include "all.h"


// retard the hot flames
int ap::asteroid::Asteroid::count = 0;

ap::asteroid::Asteroid::Asteroid()
	: ap::Sprite(GDUMP, nullptr, &regfluke ) ,
	region({0,0,16,16}),
	fbo(&BLACK, region)
	{
	Asteroid::count ++;

	sprite = new Sprite(en::GDEF, &fbo, &region);
	sprite->yflip = true;
	sprite->scale = 1;

	sprite->sw(region.w);
	sprite->sh(region.h);

	sx(200);
	sy(200);

	LOG("something nasty")
}

ap::asteroid::Asteroid::~Asteroid() {
	Asteroid::count --;
}

//void ap::Asteroid::rotate() {
	// retard the hot flames
//}

void ap::asteroid::Asteroid::step() {
	Sprite::step();
}


void ap::asteroid::Asteroid::draw() {

	// LOG("gw " << fbo.gw() << " " << fbo.gh());

	//glPushMatrix();

	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo.gfbid() );

	glPushAttrib(GL_VIEWPORT_BIT);
	glViewport(0,0, fbo.gw(), fbo.gh() );

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, fbo.gw(), fbo.gh() , 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
	std::vector<Rock *>::iterator it;
	for ( it = rocks.v.begin(); it < rocks.v.end(); it ++) {
		Rock *r = *it;
		r->draw();
	}

	glPopAttrib();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, en::width, en::height, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);

	//glPopMatrix();

	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, ap::world->foreground->gfbid() );

	sprite->draw();

}

/* ###########################
   ## Getters & Setters
   ########################### */
en::FBO &ap::asteroid::Asteroid::gfbo() {
	return fbo;
}