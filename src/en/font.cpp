#include <stdlib.h>
//#include <array>
#include <iostream>

#include "../h.h"
#include "engine.h"
#include "font.h"


using namespace en;
glyph en::badglyph = (glyph) {' ', 0, 0, 0, 0, 0, (Region) {0,0,0,0} };


en::Font::Font(char *q, int h, int b, bool absolute, en::glyph g[], int l, en::Texture &t) :
	name(q),
	height(h),
	baseline(b),
	texture(t)
{
	CURX = 0;
	
	for ( int i = 0; i < l; i ++ )
		addglyph(absolute, g[i]);
}

en::Font::~Font() {}

void en::Font::addglyph(bool absolute, glyph &g) {
	char c = g.c;
	
	if ( ! absolute ) {
		if ( '\0' == c ) {
			CURX = 0;
			return;
		}
		else g.x = CURX + g.x;
		
		CURX += g.w - (CURX-g.x);
	}
	g.r = {g.x, g.y, g.w, height};
	
	glyphs[c] = g;
}

const en::glyph &en::Font::getglyph(char c) const {
	if ( glyphs.count(c) ) {
		//glyph *g = nullptr;
		auto g = glyphs.find(c);
		//if ( glyphs.end() != g )
			//return nullptr;
		return g->second;
	}
	else return badglyph;
}

void en::Font::draw() {
	
}


/* ###########################
   ## Getters & Setters
   ########################### */
Texture &en::Font::gtexture() const {
	return texture;
}

int en::Font::gh() const {
	return height;
}

int en::Font::gb() const {
	return baseline;
}