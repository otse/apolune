#include "../h.h"
#include "draws.h"
#include "fbo.h"

#define ZERO 0

using namespace en;
int en::Draws::COUNT = 0;

/*en::Draws::Draws(Group g, Texture *t ) {
	region *r = new region;
	*r = {(0,0,t->gw(),t->gh())};
	bclearr = true;
	Draws(g, t, r);
}*/

//en::Draws::Draws(void) {}

en::Draws::Draws(Group g, Texture *t, Region *r) :
	group(g),
	texture(t),
	r(r),
	x(0),
	y(0),
	w(r->w),
	h(r->h),
	program(ZERO),
	color(&en::WHITE),
	a(1.f),
	rotate(0),
	xflip(false),
	yflip(false),
	name(nullptr),
	hovering(false),
	held(false),
	animi({0,0.D,false}),
	order(0),
	remove(false),
	delete_(true),
	nodraw(false),
	fbo(nullptr)
	{
		//stackorder();
		COUNT ++;
	}
	
en::Draws::~Draws() {
	COUNT --;
	
	//if ( bclearr)
		//delete r;
}

/**
 * @deprecated groups work a litle different now
 */
void en::Draws::stackorder() {
	//if ( GNONE == group ) return;
	
	//if ( ++ en::groups[group] == ((group+1) * GROUP_SATURATION) )
		//en::groups[group] = group * GROUP_SATURATION;
	
	//order = en::groups[group];
}

void en::Draws::translate() {
if ( nullptr == fbo ) {
		glTranslatef(x, y, 0);
	} else {
		glTranslatef(x-fbo->x, y-fbo->y, 0);
	}
}

void en::Draws::sall(double x, double y, double w, double h) {
	sx(x);
	sy(y);
	sw(w);
	sh(h);
}

bool en::Draws::onscreen() {
	const int W = en::width;
	const int H = en::height;
	
	if ( // inside
		!(
		x + w <= W  &&  x >= 0  &&
		y + h <= H  &&  y >= 0
		))
		return true;
	
	return false;
}

void en::Draws::step() {
	mousetrigger();
}

//glActiveTexture
void en::Draws::draw() {
	if ( nodraw )
		return;
	
	glPushMatrix();
	translate();
	
	if ( texture ) {
		float ntx = 0;
		float nty = 0;
		float ntw = 0;
		float nth = 0;
		
		ntx = (float) r->x / texture->gw();
		nty = (float) r->y / texture->gh();
		ntw = ( ((float) r->w / texture->gw()) + ntx );
		nth = ( ((float) r->h / texture->gh()) + nty );
		
		texture->bind();
		
		if ( program )
			glUseProgram(*program);
		
		glColor4f(color->r, color->g, color->b, a);
		
		if ( rotate ) {
			glTranslatef(w/2, h/2, 0);
			glRotatef(rotate, 0,0,1);
			glTranslatef(-w/2, -h/2, 0);
		}
		
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);

		//glTexCoord2f(0, 0);
		//glTexCoord2f(1, 0);
		//glTexCoord2f(1, 1);
		//glTexCoord2f(0, 1);
		
		float w_ = gw();
		float h_ = gh();
				
		// no flippage today
		if ( ! xflip && ! yflip ) {
			glTexCoord2f(ntx, nty); // left top
			glVertex2f(0, 0);

			glTexCoord2f(ntw, nty); // right top
			glVertex2f(w_, 0);

			glTexCoord2f(ntw, nth); // right bottom
			glVertex2f(w_, h_);

			glTexCoord2f(ntx, nth); // left bottom
			glVertex2f(0, h_);
		}
		else if ( xflip ) {
			glTexCoord2f(ntw, nty); // right top
			glVertex2f(0, 0);

			glTexCoord2f(ntx, nty); // left top
			glVertex2f(w_, 0);

			glTexCoord2f(ntx, nth); // left bottom
			glVertex2f(w_, h_);

			glTexCoord2f(ntw, nth); // right bottom
			glVertex2f(0, h_);
			
		} else if ( yflip ) {
			glTexCoord2f(ntx, nth); // left bottom
			glVertex2f(0, 0);

			glTexCoord2f(ntw, nth); // right bottom
			glVertex2f(w_, 0);

			glTexCoord2f(ntw, nty); // right top
			glVertex2f(w_, h_);

			glTexCoord2f(ntx, nty); // left top
			glVertex2f(0, h_);
		}
		
		glDisable(GL_TEXTURE_2D);
		
		glEnd();
		
		glColor4f(1, 1, 1, 1);
			
		if ( program )
			glUseProgram(0);
		
		if ( texture )
			texture->unbind();
			
	} else { // no texture
		glDisable(GL_TEXTURE_2D);
		glColor4f(color->r, color->g, color->b, a);
		
		glBegin(GL_QUADS);
		
		glVertex2d(0, 0);
		glVertex2d(w, 0);
		glVertex2d(w, h);
		glVertex2d(0, h);
		
		glEnd();
		
		glColor4f(1, 1, 1, 1);
		
		glEnable(GL_TEXTURE_2D);
	}
	
	glPopMatrix();
}

void en::Draws::click() { }
void en::Draws::hover(mou::Hover) { }

void en::Draws::mousetrigger() {
	
	using namespace mou;
		
	if (held&&MOURELEASED)
		held = false;
	
	if (
		!(MOUISIDLE) &&
		(MOUPRESSED||MOURELEASED) &&
		
		pmx >= gscrx() && pmx <= gscrx() + gw() &&
		pmy >= gscry() && pmy <= gscry() + gh() &&
		
		mx >= gscrx() && mx < gscrx() + gw() &&
		my >= gscry() && my < gscry() + gh()
		) {
		
		if ( MOUPRESSED )
			held = true;
		
		if ( MOURELEASED )
			held = false;
		
		
		if (IDLE!=left||IDLE!=right)
			click();
	}
	else if (
		mx >= gscrx() && mx < gscrx() + gw() &&
		my >= gscry() && my < gscry() + gh()
	) {
		if ( ! hovering ) {
			hover(HOVER_IN);
			hovering = true;
		}
	}
	else if ( hovering ) {
		hover(HOVER_OUT);
		hovering = false;
	}
	//bout = true;
}

/* ###########################
   ## Getters & Setters
   ########################### */

double en::Draws::gx() const { return x; }
double en::Draws::gy() const { return y; }
double en::Draws::gw() const { return w; }
double en::Draws::gh() const { return h; }

int en::Draws::gscrx() const { return x; }
int en::Draws::gscry() const { return y; }


void en::Draws::sx(double p) { x = p;}
void en::Draws::sy(double p) { y = p; }
void en::Draws::sw(double p) { w = p; }
void en::Draws::sh(double p) { h = p; }

void en::Draws::sorder(order_t p) { order = p; }
void en::Draws::stexture(en::Texture *t) { texture = t; }
Region *en::Draws::gregion() { return r; }
void en::Draws::sregion(Region *r) { this->r = r; }
//void en::Draws::sxflip(bool b) { xflip = b; }
//void en::Draws::syflip(bool b) { yflip = b; }
void en::Draws::scolor(Color *c) { color = c; }
void en::Draws::sa(float f) { a = f; }
void en::Draws::sprogram(GLuint *a) { program = a; }