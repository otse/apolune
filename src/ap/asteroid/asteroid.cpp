#include "stdafx.h"

#if 0
#include "all.h"

#include "../sprite.h"
#include "../../en/fbo.h"

// retard the hot flames
int ap::asteroid::Asteroid::count = 0;

ap::asteroid::Asteroid::Asteroid()
	: ap::Sprite(GDUMP, nullptr, &regfluke ) ,
	region({0,0,16,16}),
	fbo(&BLACK, region)
	{
	Asteroid::count ++;

	sprite = new Sprite(SORT_UNIMPORTANT, &fbo, &region);
	sprite->yflip = true;
	sprite->scale = 1;

	sprite->sw(region.w);
	sprite->sh(region.h);

	sx(200);
	sy(200);

	fillerup();

	LOG("something nasty")
}

ap::asteroid::Asteroid::~Asteroid() {
	Asteroid::count --;
}

//void ap::Asteroid::rotate() {
	// retard the hot flames
//}

void ap::asteroid::Asteroid::fillerup() {
	for (int y = 0; y < 20; y ++ ) {
		for (int x = 0; x < 20; x ++) {
			Rock *r = new Rock(*this, x,y);
			rocks.v.push_back(r);
		}
	}
}

void ap::asteroid::Asteroid::add(Rock *r) {
	int ww = dims[0]*16;
	int hh = dims[1]*16;

	r.w = ww;
	r.h = hh;

	sprite->sx(gx2()*16);
	sprite->sy(gy2()*16);

	sprite->sw(ww);
	sprite->sh(hh);

	ship->resize(ww,hh);
}

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
#endif