#include "sprite.h"
#include "ply.h"


int ap::Sprite::COUNT = 0;

ap::Sprite::Sprite(en::Group g, en::Texture *t, en::Region *r)
	: en::Draws(g, t, r) ,
	world(true),
	ax(0),
	ay(0)
	{
	COUNT ++;
	scale = 2;
	sw(gw()*scale);
	sh(gh()*scale);
}

ap::Sprite::~Sprite() {
	COUNT --;
	// overlay
}

void ap::Sprite::translate() {
	if ( world )
		glTranslatef(
			gx() + ap::xof - ply->gx(),
			gy() + ap::yof - ply->gy(), 0.f);
	else
		glTranslatef(gx(), gy(), 0);
}

void ap::Sprite::step() {
	
}

void ap::Sprite::draw() {
	Draws::draw();
}

bool ap::Sprite::isinside(en::Region *t) {
	if ( gx() >= t->x &&
		 gy() >= t->y &&
		 gx()+r->w <= t->x+t->w &&
		 gy()+r->h <= t->y+t->h )
		return true;
	
	return false;
}


/* ###########################
   ## Getters & Setters
   ########################### */
void ap::Sprite::sworld(bool b) {
	world = b;
}

double ap::Sprite::gax() const { return ax; }
double ap::Sprite::gay() const { return ay; }

void ap::Sprite::click(mou::Button, mou::Click) {};
void ap::Sprite::hover(mou::Hover) {};

void ap::Sprite::sx(double p) { ax = p; Draws::sx(int(ax)); }
void ap::Sprite::sy(double p) { ay = p; Draws::sy(int(ay)); }

double ap::Sprite::gx() const { return Draws::gx(); }
double ap::Sprite::gy() const { return Draws::gy(); }
double ap::Sprite::gw() const { return Draws::gw(); }
double ap::Sprite::gh() const { return Draws::gh(); }
int ap::Sprite::gscrx() const { return Draws::gx() + ap::xof - ply->gx(); } // for tooltipping
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