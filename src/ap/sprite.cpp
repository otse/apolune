#include "stdafx.h"

#include "sprite.h"
#include "ply.h"


int ap::Sprite::COUNT = 0;

ap::Sprite::Sprite(en::Group g, en::Texture *t, en::Region *r)
	: en::Draws(g, t, r) ,
	world(true)
	{
	COUNT ++;

	scale = 1;
	sw(gw()*scale);
	sh(gh()*scale);
}

ap::Sprite::~Sprite() {
	COUNT --;
	// overlay
}

void ap::Sprite::translate() {
	if (world) {
		int x = gx() - ply->gx();
		int y = gy() - ply->gy();

		glTranslatef(xof, yof, 0);

		glScalef(ap::scale, ap::scale, 1); // the aswer for all your scaling
		glRotatef(ply->orientation, 0, 0, 1);

		glTranslatef(x, y, 0);
	}
	else
		Draws::translate();
}

void ap::Sprite::step() { Draws::step(); }
void ap::Sprite::draw() { Draws::draw(); }

bool ap::Sprite::isinside(en::Region *t) {
	if ( gx() >= t->x &&
		 gy() >= t->y &&
		 gx()+r->w <= t->x+t->w &&
		 gy()+r->h <= t->y+t->h )
		return true;
	
	return false;
}

void ap::Sprite::click() {};
void ap::Sprite::hover(mou::Hover) { };


/* ###########################
   ## Getters & Setters
   ########################### */
void ap::Sprite::sworld(bool b) { world = b; }
void ap::Sprite::sx(double p) { ax = p; Draws::sx(int(ax)); }
void ap::Sprite::sy(double p) { ay = p; Draws::sy(int(ay)); }

double ap::Sprite::gx() const { return Draws::gx(); }
double ap::Sprite::gy() const { return Draws::gy(); }
double ap::Sprite::gw() const { return Draws::gw(); }
double ap::Sprite::gh() const { return Draws::gh(); }
int ap::Sprite::gscrx() const { return Draws::gx() + ap::xof - ply->gx(); }
int ap::Sprite::gscry() const { return Draws::gy() + ap::yof - ply->gy(); }


ap::Simpleanim::Simpleanim(en::Group g, en::Texture *t, en::Region *r, const en::Anim &a) :
	ap::Sprite::Sprite(g, t, r) ,
	anim(a) {
	
};

ap::Simpleanim::~Simpleanim() {
	
}

void ap::Simpleanim::step() {
	sregion( anim.progress(animi) );
}