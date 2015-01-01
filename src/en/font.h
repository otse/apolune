#ifndef enfont_H
#define enfont_H

#include <map>

#include "draws.h"



namespace en {
	struct glyph {
		char c;
		int x;
		int y;
		int w;
		int sb;
		int sf;
		Region r;
	};
	
	extern glyph badglyph;

	class Font {
	public:
		int CURX;
		Font(char *, int, int, bool, glyph[], int, Texture &);
		~Font();
		
		virtual void draw();
		char *name;
		void addglyph(bool, glyph &);
		const glyph &getglyph(char) const;
		int gh() const;
		int gb() const;
		Texture &gtexture() const;
	private:
		Texture &texture;
		int baseline;
		int height;
		glyph glyphs[255] = {};
		//std::map<char, glyph> glyphs;
		//void move();
	};
}
#endif