#include "stdafx.h"

#include <iostream>

#include "engine.h"
//#include "shaders.h"
#include "texture.h"
#include "../ll/stb_image.h"
#include <cstring>
#include <fstream> // for roaming

#include "../boilerplate.h"

bool en::Texture::NOBIND = false;
en::Texture *en::Texture::bound = nullptr;


en::Texture::Texture(int w, int h) :
	w(w),
	h(h) {
	
	// protected fbo overrider
}

en::Texture::Texture(const char *f) :
	file(f),
	w(0),
	h(0),
	n(0),
	success(false)
	{
	
}

en::Texture::~Texture() {
	glDeleteTextures(1, &tid);
}

void en::Texture::bind() {
	if ( NOBIND )
		return;

	if (bound == this)
		return;
		
	//glEnable(GL_TEXTURE_2D);
	//glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	glBindTexture( GL_TEXTURE_2D, tid );

	bound = this;
}

void en::Texture::unbind() {
	if ( NOBIND )
		return;

	bound = nullptr;
		
	glBindTexture(GL_TEXTURE_2D, 0);
}

void en::Texture::create() {
	glGenTextures(1, &tid);
	glBindTexture(GL_TEXTURE_2D, tid);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // minecraft
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
}

bool en::Texture::load() {
	using namespace boilerplate;
	
	unsigned char *data;
	
	const char *basename = strrchr(this->file, '/');
	basename = (basename) ? basename+1 : file;
	
	//LOG("basename is " << basename)
	
	std::string tmp = *extraction + '\\' + basename;
	
	// write to a temporary file
	std::ofstream myfile;
	myfile.open(tmp, std::ios::out | std::ios::trunc | std::ios::binary);
	
	basefile bf = gbasefile(file);
	if ( ! bf.read )
		return false;
		
	myfile.write(bf.buf, bf.len);
	myfile.close();
	
	//LOG("opening " << tmp)
	
	data = stbi_load(tmp.c_str(), &w, &h, &n, 4);
	remove(tmp.c_str()); // destroy "tmp file"
	
	if ( ! data ) {
		//LOG("stbi data err");
		return false;
	}
	
	glGenTextures(1, &tid);
	glBindTexture(GL_TEXTURE_2D, tid);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // minecraft
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);
	data = 0;
	
	//PL_GL_TELL_ERROR("texture->load()");
	
	success = true;
	
	return true;
}


/* ###########################
   ## Getters & Setters
   ########################### */
GLuint en::Texture::gtid() { return tid; }
int en::Texture::gn() { return n; }
int en::Texture::gw() { return w; }
int en::Texture::gh() { return h; }
void en::Texture::sw(int a) { w = a; }
void en::Texture::sh(int a) { h = a; }