#include "stdafx.h"


#include <SFML/Audio/Sound.hpp>

#include "../../en/fbo.h"
#include "../def.h"

#include "mass.h"
#include "part.h"
#include "block.h"

#include "../world.h"
#include "../ply.h"
#include "../ship/truss.h"


ap::mesh::Mass::Mass() : ap::Sprite(SORT_UNIMPORTANT, nullptr, &en::regfluke ) ,
	r({ 0,0,16,16 }),
	grid(*this, 8, Tile::eight)
	{

	Draws::r = &r;
	stexture(fbo = obf = new en::FBO(&en::BLACK, r));
	
	shadow = new en::FBO(&en::BLACK, r);
	shadow->gdraws().sa(.25);

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

	//Sprite *light = new Sprite(SORT_HIGH, &textures::cursorlight, &regions::cursorlight);
	//ap::world->add(light);

	Sprite *fud = new Sprite(SORT_HIGH, &textures::cursorlight, &regions::cursorlight);
	ap::world->lights.v.push_back(fud);

	// cube
	for (int y = 1; y < 8; y++) {
		for (int x = 1; x < 8; x++) {
			Tile &t = *grid.gtile(x, y);
			
			Block *p = new Block(AFT, t);
			t.attach(*p);

			if ( (x == 1 || y == 1 || x == 7 || y == 7) ) {
				Block *p = new Block(FORE, t);
				t.attach(*p);
			}
		}
	}

}

ap::mesh::Mass::~Mass() {

}

void ap::mesh::Mass::step() {
	std::vector<Part *>::iterator it;
	for (it = fores.begin(); it < fores.end(); it++) {
		Part *p = *it;
		p->step();
	}
}

void ap::mesh::Mass::clicked(Tile &t) {

	// todo: the amount of duplication is unfunny
	if (&mou::left == mou::active && mou::PRESSED == *mou::active) {

		if (t.gpart(FORE) && !t.seethrough) return;
		
		if ( Part *p = partfactory(FORE, t, ply->partname) ) {

			if (FORE == p->fixture && t.seethrough) {
				t.detach(FORE);
				delete t.seethrough;
				t.seethrough = nullptr;
			}

			t.attach(*p);
			t.grid.expandfrom(t);

			sf::Sound *bep = new sf::Sound(*sounds::torquewrench);
			bep->play();
			en::sounds.push_back(bep);
		}
	}
	else if (&mou::right == mou::active && mou::PRESSED == *mou::active) {

		if (t.gpart(AFT)) return;

		if (Part *p = partfactory(AFT, t, ply->partname)) {
			t.attach(*p);
			t.grid.expandfrom(t);

			sf::Sound *bep = new sf::Sound(*sounds::torquewrench);
			bep->play();
			en::sounds.push_back(bep);
		}
	}
}

void ap::mesh::Mass::add(Part *p) {

	(FORE == p->fixture ? fores : afts).push_back(p);

	// re fbo;

	const Region normal = grid.gnormal();

	// LOG("gnormal " << normal.x << " " << normal.y << " " << normal.w << " " << normal.h)

	int x = normal.x - 1;
	int y = normal.y - 1;
	int w = normal.w + 3;
	int h = normal.h + 3;

	if (normal.x < 0) w += -normal.x;
	if (normal.y < 0) h += -normal.y;

	int factor = 8;

	w *= factor;
	h *= factor;

	shadow->x = obf->x = x * factor;
	shadow->y = obf->y = y * factor;

	sx(x * factor);
	sy(y * factor);
	sw(w);
	sh(h);

	obf->resize(w, h);
	shadow->resize(w, h);
	//contiguous->resize(w, h);

}

void ap::mesh::Mass::remove(Part *p) {
	auto& vec = (FORE == p->fixture ? fores : afts);

	std::vector<Part*>::iterator pos = std::find(vec.begin(), vec.end(), p);

	if (vec.end() != pos)
		vec.erase(pos);
}

void ap::mesh::Mass::draw() {
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, shadow->gfbid());

	glPushAttrib(GL_VIEWPORT_BIT);
	glViewport(0, 0, obf->gw(), obf->gh());

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, obf->gw(), obf->gh(), 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

	{std::vector<Part *>::iterator it;
	for (it = fores.begin(); it < fores.end(); it++) {
		Part *p = *it;
		p->draw(SHADOW_PASS);
	}}

	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, obf->gfbid());

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	{std::vector<Part *>::iterator it;
	for (it = afts.begin(); it < afts.end(); it++) {
		Part *p = *it;
		p->draw(BACKGROUND_PASS);
	}}

	shadow->gdraws().draw();

	{std::vector<Part *>::iterator it;
	for (it = fores.begin(); it < fores.end(); it++) {
		Part *p = *it;
		p->draw(FOREGROUND_PASS);
	}}

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
FBO *ap::mesh::Mass::gshadow() const { return shadow; }