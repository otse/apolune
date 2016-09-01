#ifndef enengine_H
#define enengine_H


#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#include "Q:/glew-1.11.0/include/GL/glew.h"
#include "Q:/glew-1.11.0/include/GL/wglew.h"
#include <SFML/Graphics.hpp>
#include "Q:/physfs-2.0.3/physfs.h"

//#include "Q:/freeglut/include/GL/freeglut.h"
//#include "../../../DEPS/openal-soft-1.16.0-bin/include/AL/al.h"

typedef long clock_t;
typedef struct PHYSFS_File PHYSFS_File; // 'forward declaration'

#define DEGTORAD 0.0174532925199432957
#define RADTODEG 57.295779513082320876

namespace envars {
	void resize(int, int);
	void make();
	void frame();
	extern const char *windowname;
	extern int /*sf::Style*/ windowstyle;
}

namespace en {

	class FBO;
	class Font;
	class Text;
	class Draws;
	class Texture;
	class Shader;
	class Anim;
	
	struct Region {public: int x, y, w, h;};
	struct Color {float r, g, b;};
	
	struct animinstance {
		int pos;
		double time;
		bool reverse;
	};

	#include "stltempl.h"
	
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

		extern int wheel;

		extern sf::Vector2i pos;
	}
	
	namespace oar {
		void poll();
		enum KEY_STATE {UP, DOWN, STILL_DOWN};
		extern KEY_STATE keys[];
	}
	
	extern const int GROUP_SATURATION;
	extern Draws *groups[];

	void roaming();
	extern PHYSFS_File *base;

	extern bool focus;
	extern List<Draws*> draws;
	void drawsstep();
	void add(Draws *);
	void rm(Draws *);

	extern Vector<Draws*> late;
	void later(Draws *);

	typedef int order_t;

	extern Color BLACK;
	extern Color WHITE;

	extern int width;
	extern int height;
	extern float scale;
	
	extern int WindowHandle;
	
	void boot(int, wchar_t* []);
	void resize(int, int);
	void render();
	void cleanup();
	void idle();
	
	void flat();
	void threed();
	extern bool pixels;

	extern en::Region regfluke;
	
	extern std::string *extraction;
	extern LARGE_INTEGER frequency;
	extern LARGE_INTEGER deltatime;
	extern LARGE_INTEGER now;
	extern double dnow;
	void cdelta();
	
	void mdelta();
	extern double delta;
	extern bool ppi;
}

/*
#define PL_GL_TELL_ERROR(QUOTE) \
	{ \
	GLenum e = glGetError(); \
	const GLubyte *err; \
	if ( GL_NO_ERROR != e ) { \
		err = gluErrorString(e); \
		//LOG("err: " << err << " @'" << QUOTE << "':" << __LINE__ << " in " << __FILE__) \
	} \
	}
*/

// ### INCLUDED FOR LOGGING PREPROCESSOR
// ### AND ALSO FOR SOME ENGINE DEFINES
#ifdef APOLUNE
#include "../../lau/h.h"
#else
#include "../h.h"
#endif

#endif