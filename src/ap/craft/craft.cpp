#include "craft.h"
#include "all.h"

#include "../../en/fbo.h"


ap::craft::Craft::Craft() : ap::Sprite(en::GDEF, nullptr, &en::regfluke ) ,
	r({0,0,256,256})
	{
	ship = new en::FBO(&en::BLACK, r);
}

ap::craft::Craft::~Craft() {

}

void ap::craft::Craft::step() {
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, ship->gfbid() );
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
	std::vector<Part *>::iterator it;
	for ( it = parts.v.begin(); it < parts.v.end(); it ++) {
		Part *p = *it;
		p->draw();
	}

	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
}

void ap::craft::Craft::click() {}

void ap::craft::Craft::hover(mou::Hover h) {
	
	if ( mou::HOVER_IN == h ) {
		//sregion(&regions::craft::tileover);
	} else {
		//sregion(&regions::craft::tile);
	}

}


/* ###########################
   ## Getters & Setters
   ########################### */
//void ap::craft::Grid::sgrid(int c, int r) {
	//cols = c;
	//rows = r;

	//table();
//}

//float ap::Ply::gy() {
//	return .0;
//}