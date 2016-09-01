#include "stdafx.h"

#include "all.h"

#include "../../en/fbo.h"


ap::ship::Ship::Ship() : ap::Sprite(en::GDEF, nullptr, &en::regfluke) ,
	r({0,0,16,16}),
	grid(*this),
	crosssection(true)
	{
	ship = new en::FBO(&en::BLACK, r);

	sprite = new Sprite(en::GDEF, ship, &r);
	sprite->yflip = true;
	sprite->scale = 1;

	sprite->sw(r.w);
	sprite->sh(r.h);
	pose();

	Tile &t = grid.mtile(0,0);
	Truss *p = new Truss(t);
	t.attach(p);

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

	//glPushMatrix();

	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, ship->gfbid() );

	glPushAttrib(GL_VIEWPORT_BIT);
	glViewport(0,0, ship->gw(), ship->gh() );

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, ship->gw(), ship->gh() , 0, 0, 1);
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

	//glPopMatrix();

	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, ap::world->foreground->gfbid() );

	sprite->draw();

	en::s2d();
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

	w *= 16;
	h *= 16;

	ship->x = normal.x * 16;
	ship->y = normal.y * 16;

	sprite->sx(normal.x*16);
	sprite->sy(normal.y*16);
	sprite->sw(w);
	sprite->sh(h);

	ship->resize(w,h);

}

void ap::ship::Ship::refbo() {
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

}

void ap::ship::Ship::click() {}
void ap::ship::Ship::hover(mou::Hover h) {}


/* ###########################
   ## Getters & Setters
   ########################### */
en::FBO *ap::ship::Ship::gfbo() {
	return ship;
}

//float ap::Ply::gy() {
//	return .0;
//}