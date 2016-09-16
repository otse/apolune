#include "stdafx.h"

#include "ship.h"

#include "../../en/fbo.h"

using namespace ap::ship;
using namespace ap::mesh;

ap::ship::Ship::Ship() : Mass() ,
	crosssection(true)
	{
	

	/*Tile &t = grid.mtile(0,0);
	Tile &t2 = grid2.mtile(0,0);

	grid.enabled = false;
	grid2.enabled = true;

	Truss *p = new Truss(t2);
	t2.attach(p);*/

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


void ap::ship::Ship::clicked(Tile &t) {
	
}

void ap::ship::Ship::draw() {
	// LOG("gw " << ship->gw() << " " << ship->gh());

		
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo->gfbid() );

	glPushAttrib(GL_VIEWPORT_BIT);
	glViewport(0,0, fbo->gw(), fbo->gh() );

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, fbo->gw(), fbo->gh() , 0, 0, 1);
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

	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, ap::world->foreground->gfbid() );

	sprite->draw();

	flat();
}


void ap::ship::Ship::click() {}
void ap::ship::Ship::hover(mou::Hover h) {}


/* ###########################
   ## Getters & Setters
   ########################### */


//float ap::Ply::gy() {
//	return .0;
//}