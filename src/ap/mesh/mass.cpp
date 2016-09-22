#include "stdafx.h"


#include <SFML/Audio/Sound.hpp>

#include "../../en/fbo.h"
#include "../def.h"

#include "mass.h"
#include "part.h"
#include "block.h"

#include "../ply.h"
#include "../ship/truss.h"



ap::mesh::Mass::Mass() : ap::Sprite(SORT_UNIMPORTANT, nullptr, &en::regfluke ) ,
	r({ 0,0,16,16 }),
	grid(*this, 8, Tile::eight)
	{

	Draws::r = &r;
	stexture(fbo = obf = new en::FBO(&en::BLACK, r));
	//contiguous = new en::FBO(&en::BLACK, r);

	yflip = true;

	sw(r.w);
	sh(r.h);

	sx(0);
	sy(0);

	grid.enabled = true;

	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			Tile &t = grid.mtile(x, y);
		}
	}

	// cube
	for (int y = 1; y < 8; y++) {
		for (int x = 1; x < 8; x++) {
			Tile &t = *grid.gtile(x, y);
			
			if ( (x == 1 || y == 1 || x == 7 || y == 7) ) {
				Block *p = new Block(t);
				t.attach(p);
			}
		}
	}

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


void ap::mesh::Mass::clicked(Tile &t) {

	if ( nullptr != t.gpart() )
		return; // invoke partclick?

	if (&mou::left == mou::active && mou::PRESSED == *mou::active) {
		
		if ( Part *p = partfactory(t, ply->partname) ) {
			LOG("ATTACHING")
			t.attach(p);
			LOG("AFTER ATTACH")

			sf::Sound *bep = new sf::Sound(*sounds::torquewrench);
			bep->play();
			en::sounds.push_back(bep);
		}
	}
}

void ap::mesh::Mass::add(Part *p) {

	parts.v.push_back(p);

	// re fbo;

	const Region normal = grid.gnormal();

	LOG("gnormal " << normal.x << " " << normal.y << " " << normal.w << " " << normal.h)

	int x = normal.x - 1;
	int y = normal.y - 1;
	int w = normal.w + 3;
	int h = normal.h + 3;

	if (normal.x < 0) w += -normal.x;
	if (normal.y < 0) h += -normal.y;

	int factor = 8;

	w *= factor;
	h *= factor;

	obf->x = x * factor;
	obf->y = y * factor;

	sx(x * factor);
	sy(y * factor);
	sw(w);
	sh(h);

	obf->resize(w, h);
	//contiguous->resize(w, h);

}

void ap::mesh::Mass::draw() {
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, obf->gfbid());

	glPushAttrib(GL_VIEWPORT_BIT);
	glViewport(0, 0, obf->gw(), obf->gh());

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, obf->gw(), obf->gh(), 0, 0, 1);
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

	Sprite::draw();

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// flat(); // tsts
}

/* ###########################
   ## Getters & Setters
   ########################### */
FBO *ap::mesh::Mass::gobf() const { return obf; }