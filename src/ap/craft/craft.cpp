#include "all.h"

#include "../../en/fbo.h"


ap::craft::Craft::Craft() : ap::Sprite(en::GDEF, nullptr, &en::regfluke) ,
	r({0,0,48,48}),
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
}

void ap::craft::Craft::add(Part *p) {
	parts.v.push_back(p);

	// re fbo;

	int *dims = grid.gdims();

	LOG("added part, new grid dims are " << dims[0] << " " << dims[1])

	int ww = dims[0]*48;
	int hh = dims[1]*48;

	r.w = ww;
	r.h = hh;

	sprite->sx(grid.gx2()*48);
	sprite->sy(grid.gy2()*48);

	sprite->sw(ww);
	sprite->sh(hh);

	ship->resize(ww,hh);

}

void ap::craft::Craft::refbo() {
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

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