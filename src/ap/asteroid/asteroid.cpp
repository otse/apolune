#include "asteroid.h"


// retard the hot flames
int ap::asteroid::Asteroid::count = 0;

ap::asteroid::Asteroid::Asteroid()
	: ap::Sprite(GDUMP, nullptr, &regfluke ) ,
	fbo(&BLACK, *(new Region{0,0,16,16}))
	{
	Asteroid::count ++;

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

	// LOG("gw " << ship->gw() << " " << ship->gh());

	//glPushMatrix();

	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo->gfbid() );

	glPushAttrib(GL_VIEWPORT_BIT);
	glViewport(0,0, fbo->gw(), fbo->gh() );

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, fbo->gw(), fbo->gh() , 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
	std::vector<Rock *>::iterator it;
	for ( it = parts.v.begin(); it < parts.v.end(); it ++) {
		Part *p = *it;
		p->draw();
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