#include "craft.h"
#include "all.h"

#include "../../en/fbo.h"


ap::craft::Craft::Craft() : ap::Sprite(en::GDEF, nullptr, &en::regfluke ) ,
	r({0,0,300,568})
	{
	ship = new en::FBO(&en::BLACK, r);

	sprite = new Sprite(en::GDEF, ship, &r);
	sprite->yflip = true;
	sprite->scale = 1;

	sprite->sw(r.w);
	sprite->sh(r.h);
	pose();
}

ap::craft::Craft::~Craft() {

}

void ap::craft::Craft::step() { }

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

	std::vector<Part *>::iterator it;
	for ( it = parts.v.begin(); it < parts.v.end(); it ++) {
		Part *p = *it;
		p->scan();
	}

	// LOG(parts.v.size())
}


void ap::craft::Craft::click() {}
void ap::craft::Craft::hover(mou::Hover h) {}


/* ###########################
   ## Getters & Setters
   ########################### */
en::FBO *ap::craft::Craft::gfbo() {
	return ship;
}

//float ap::Ply::gy() {
//	return .0;
//}