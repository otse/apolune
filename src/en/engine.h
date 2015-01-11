#ifndef enengine_H
#define enengine_H


//#define FREEGLUT_STATIC
//#define GLEW_STATIC
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#include "Q:/glew-1.11.0/include/GL/glew.h"
#include "Q:/glew-1.11.0/include/GL/wglew.h"
#include <SFML/Graphics.hpp>
//#include "Q:/freeglut/include/GL/freeglut.h"
//#include "../../../DEPS/openal-soft-1.16.0-bin/include/AL/al.h"

typedef long clock_t;

namespace en {

	class FBO;
	class Font;
	class Text;
	class Draws;
	class Texture;
	class Shader;
	class Anim;
	
	struct Region {int x, y, w, h;};
	struct Color {float r;float g;float b;};
	
	struct animinstance {
		int pos;
		double time;
		bool reverse;
	};
	
	enum Group {GNONE = -1,GDEF = 0,GPLAYER,GGUI,GDUMP,COUNT};
	
	namespace mou {
		enum Button {LEFT,MIDDLE,RIGHT};
		enum Click {PRESSED,RELEASED,DRAG,IDLE};
		enum Hover {HOVER_IN,HOVER_OUT};
		
		extern Click left;
		extern Click right;
		extern Click *active;
#define MOUISLEFT &en::mou::left == en::mou::active
#define MOUISRIGHT &en::mou::right == en::mou::active
#define MOUPRESSED en::mou::PRESSED == *en::mou::active
#define MOURELEASED en::mou::RELEASED == *en::mou::active
#define MOUISIDLE nullptr==en::mou::active
		
		void mice(const sf::RenderWindow &);
		
		extern int pmx;
		extern int pmy;
		extern int mx;
		extern int my;

		extern sf::Vector2i pos;
	}
	
	namespace oar {
		enum KEY_STATE {UP, DOWN, STILL_DOWN};
		extern KEY_STATE keys[];
	}
	
	extern const int GROUP_SATURATION;
	extern Draws *groups[];
	typedef int order_t;

	extern Color BLACK;
	extern Color WHITE;

	extern int width;
	extern int height;
	
	extern int WindowHandle;
	
	void window();
	void resize(int, int);
	void render();
	void cleanup();
	void idle();
	
	extern bool twdd;
	void s2d();
	void s3d();
	extern en::Region regfluke;
	
	extern std::string *extraction;
	extern LARGE_INTEGER frequency;
	extern LARGE_INTEGER deltatime;
	extern LARGE_INTEGER now;
	extern double dnow;
	void cdelta();
	
	void mdelta();
	extern double delta;
	
#include "stltempl.h"
}

#define PL_GL_TELL_ERROR(QUOTE) \
	{ \
	GLenum e = glGetError(); \
	const GLubyte *err; \
	if ( GL_NO_ERROR != e ) { \
		err = gluErrorString(e); \
		LOG("err: " << err << " @'" << QUOTE << "':" << __LINE__ << " in " << __FILE__) \
	} \
	}


// ### INCLUDED FOR LOGGING PREPROCESSOR
// ### AND ALSO FOR SOME ENGINE DEFINES
#ifdef APOLUNE
#include "../h.h"
#else
#include "../../lau/h.h"
#endif

#endif