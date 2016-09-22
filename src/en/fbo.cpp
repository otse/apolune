#include "stdafx.h"

#include "fbo.h"

// uses protected texture fbo-ctor
en::FBO::FBO(Color *c, Region &r) : en::Texture(r.w, r.h) ,
	region(r),
	clear(c),
	fb(0),
	draws(0, this, &r),
	x(0),
	y(0)
	{
	draws.yflip = true;
	
	glDisable(GL_TEXTURE_2D); // necessary?
	glGenFramebuffersEXT( 1, &fb );
	glBindFramebufferEXT( GL_FRAMEBUFFER_EXT, fb );
	
	Texture::create();
	glBindTexture(GL_TEXTURE_2D, tid);
	//glActiveTexture(GL_TEXTURE0);
	
	glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, tid, 0);
	
	//GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
	//glDrawBuffers(1, DrawBuffers);
	glDrawBuffer(GL_COLOR_ATTACHMENT0_EXT);

	if (
			GL_FRAMEBUFFER_COMPLETE_EXT !=
			glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT) ) {
		//LOG("fbo error")
		std::cout << "fbo error" << std::endl;
	}
	
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	
	unbind();
}

en::FBO::~FBO() {
	glDeleteFramebuffers(1, &fb);
}

/*void en::FBO::bind() {
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fb);
	glPushAttrib(GL_VIEWPORT_BIT);
	glViewport(0,0, w, h);
	//Texture::bind();
	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture( GL_TEXTURE_2D, tid );
}

void en::FBO::unbind() {
	//LOG("fbo unbind");
	glPopAttrib();
	//glViewport(0,0, en::WIDTH, en::HEIGHT);
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
}*/

void en::FBO::resize(int w, int h) {
	region.w = w;
	region.h = h;
	sw(w);
	sh(h);
	draws.sw(w);
	draws.sh(h);
	glBindTexture(GL_TEXTURE_2D, tid);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
}

/* ###########################
   ## Getters & Setters
   ########################### */
GLuint en::FBO::gfbid() { return fb; }

en::Draws &en::FBO::gdraws() {
	return draws;
}

en::Region &en::FBO::gr() {
	return region;
}