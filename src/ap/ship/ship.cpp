#include "stdafx.h"

#include "ship.h"

#include "../../en/fbo.h"

using namespace ap::ship;
using namespace ap::mesh;

ap::ship::Ship::Ship() : Mass() ,
	r({0,0,16,16}),
	grid(*this, 8, Tile::eight),
	grid2(*this, 16, Tile::sixteen),
	crosssection(true)
	{
	fbo = new en::FBO(&en::BLACK, r);

	sprite = new Sprite(SORT_UNIMPORTANT, fbo, &r);
	sprite->yflip = true;
	sprite->scale = 3;

	sprite->sw(r.w);
	sprite->sh(r.h);
	pose();

	Tile &t = grid.mtile(0,0);
	Tile &t2 = grid2.mtile(0,0);

	grid.enabled = false;
	grid2.enabled = true;

	Truss *p = new Truss(t2);
	t2.attach(p);

	//crosssection = true;
}

ap::ship::Ship::~Ship() {

}

void ap::ship::Ship::step() {
	std::vector<Part *>::iterator it;
	for ( it = parts.v.begin(); it < parts.v.end(); it ++) {
		Part *p = *it;
		p->step();
	}

	//sprite->rotate += 0.001;
}

void ap::ship::Ship::pose() {
	sprite->sx(gx());
	sprite->sy(gy());
}

void ap::ship::Ship::draw() {
	// LOG("gw " << ship->gw() << " " << ship->gh());

		
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
	std::vector<Part *>::iterator it;
	for ( it = parts.v.begin(); it < parts.v.end(); it ++) {
		Part *p = *it;
		p->draw();
	}

	glPopAttrib();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, en::width, en::height, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);

	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, ap::world->foreground->gfbid() );

	sprite->draw();

	flat();
}

void ap::ship::Ship::add(Part *p) {
	parts.v.push_back(p);

	// re fbo;

	const Region normal = grid.gnormal();

	LOG("gnormal " << normal.x << " " << normal.y << " " << normal.w << " " << normal.h)

	int w = normal.w + 1;
	int h = normal.h + 1;

	if (normal.x < 0) w += -normal.x;
	if (normal.y < 0) h += -normal.y;

	int factor = 16;

	w *= factor;
	h *= factor;

	fbo->x = normal.x * factor;
	fbo->y = normal.y * factor;

	sprite->sx(normal.x * factor);
	sprite->sy(normal.y * factor);
	sprite->sw(w);
	sprite->sh(h);

	fbo->resize(w,h);

}

void ap::ship::Ship::refbo() {
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

}

void ap::ship::Ship::click() {}
void ap::ship::Ship::hover(mou::Hover h) {}


/* ###########################
   ## Getters & Setters
   ########################### */
FBO *ap::ship::Ship::gfbo() const { return fbo; }
Grid &ap::ship::Ship::ggrid() { return grid; }
Grid &ap::ship::Ship::ggrid2() { return grid2; }

//float ap::Ply::gy() {
//	return .0;
//}