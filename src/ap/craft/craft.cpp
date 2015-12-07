#include "all.h"

#include "../../en/fbo.h"


ap::craft::Craft::Craft() : ap::Sprite(en::GDEF, nullptr, &en::regfluke ) ,
	r({0,0,300,568}),
	grid(*this),
	top(0),
	left(0),
	crosssection(false)
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

	crosssection = true;
}

ap::craft::Craft::~Craft() {

}

void ap::craft::Craft::step() {
	std::vector<Part *>::iterator it;
	for ( it = parts.v.begin(); it < parts.v.end(); it ++) {
		Part *p = *it;
		p->step();
	}
}

void ap::craft::Craft::pose() {
	sprite->sx(gx());
	sprite->sy(gy());
}

void ap::craft::Craft::draw() {
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, ship->gfbid() );
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
	std::vector<Part *>::iterator it;
	for ( it = parts.v.begin(); it < parts.v.end(); it ++) {
		Part *p = *it;
		p->draw();
	}

	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, ap::world->foreground->gfbid() );

	sprite->draw();
}

void ap::craft::Craft::add(Part *p) {
	parts.v.push_back(p);

	//p->refit();

	std::vector<Part *>::iterator it;
	for ( it = parts.v.begin(); it < parts.v.end(); it ++) {
		Part *p = *it;
		p->refit();
	}
}


void ap::craft::Craft::click() {}
void ap::craft::Craft::hover(mou::Hover h) {}


/* ###########################
   ## Getters & Setters
   ########################### */
en::FBO *ap::craft::Craft::gfbo() {
	return ship;
}

int ap::craft::Craft::gtop() {
	return top;
}

int ap::craft::Craft::gleft() {
	return left;
}

//float ap::Ply::gy() {
//	return .0;
//}