#include "stdafx.h"

#include "../../en/fbo.h"
#include "../def.h"

#include "mass.h"
#include "part.h"


ap::mesh::Mass::Mass() : ap::Sprite(SORT_UNIMPORTANT, nullptr, &en::regfluke ) ,
	r({ 0,0,16,16 }),
	grid(*this, 8, Tile::eight),
	grid2(*this, 16, Tile::sixteen)
	{
	/*this->fbo = new en::FBO(&en::BLACK, r);

	Draws::fbo = nullptr;*/

	yflip = true;
	//scale = 3; // ?

	sw(r.w);
	sh(r.h);

	pose();

	sx(0);
	sy(0);

	grid2.enabled = true;
}

ap::mesh::Mass::~Mass() {

}

void ap::mesh::Mass::step() {

	std::vector<Part *>::iterator it;
	for (it = parts.v.begin(); it < parts.v.end(); it++) {
		Part *p = *it;
		p->step();
	}
}

void ap::mesh::Mass::pose() {
	sx(gx());
	sy(gy());
}

void ap::mesh::Mass::clicked(Tile &t) {
	if ( nullptr != t.gpart() )
		return; // invoke partclick?

	if (&mou::left == mou::active && mou::PRESSED == *mou::active) {
		// todo: are we within radius?
		/*ship::Truss *p = new ship::Truss(*this);
		t.attach(p);*/
	}
}

void ap::mesh::Mass::add(Part *p) {
	return;

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

	fbo->resize(w, h);

}

void ap::mesh::Mass::draw() {
	return;

	// LOG("gw " << ship->gw() << " " << ship->gh());

	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo->gfbid());

	glPushAttrib(GL_VIEWPORT_BIT);
	glViewport(0, 0, fbo->gw(), fbo->gh());

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, fbo->gw(), fbo->gh(), 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
	std::vector<Part *>::iterator it;
	for (it = parts.v.begin(); it < parts.v.end(); it++) {
		Part *p = *it;
		p->draw();
	}

	glPopAttrib();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, en::width, en::height, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);

	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, ap::world->foreground->gfbid());

	sprite->draw();

	flat();
}
/* ###########################
   ## Getters & Setters
   ########################### */
FBO *ap::mesh::Mass::gfbo() const { return fbo; }
ap::mesh::Grid &ap::mesh::Mass::ggrid() { return grid; }
ap::mesh::Grid &ap::mesh::Mass::ggrid2() { return grid2; }
//const Region &ap::mesh::Grid::gnormal() const { return normal; }
//int ap::mesh::Grid::gpoints() const { return points; }

//ap::mesh::Ship &ap::mesh::Grid::gcraft() {
//	return ship;
//}