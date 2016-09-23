#include "stdafx.h"

#include "vbo.h"

// uses protected texture fbo-ctor
en::VBO::VBO() :
	id(0)
	{
	glGenBuffersARB(1, &id);
	
}

en::VBO::~VBO() {
	glDeleteBuffersARB(1, &id);
}

void en::VBO::bind() {
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, id);
}

void en::VBO::modify() {
	bind();
	
	float* ptr = (float*) glMapBufferARB(GL_ARRAY_BUFFER_ARB, GL_READ_WRITE_ARB);

	if (ptr) {
		// change here...
		glUnmapBufferARB(GL_ARRAY_BUFFER_ARB);
	}
}



/* ###########################
   ## Getters & Setters
   ########################### */
//GLuint en::VBO::gfbid() { return fb; }