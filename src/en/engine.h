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
#include "Q:/freeglut/include/GL/freeglut.h"
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
	
	enum Button {LEFT,MIDDLE,RIGHT};
	enum Click {PRESSED = GLUT_DOWN,RELEASED = GLUT_UP,STILL_PRESSED,DRAG,IDLE};
	enum Hover {HOVER_IN,HOVER_OUT};
	
	// American Beauty VIP
	
	extern en::Region regfluke;
	
	extern Click left;
	extern Click right;
	
	extern int pmx;
	extern int pmy;
	extern int mx;
	extern int my;
	
	void click(int, int, int, int);
	void motion(int, int);
	void passivemotion(int, int);
	
	void down(unsigned char, int, int);
	void up(unsigned char, int, int);
	
	enum KEY_STATE {UP, DOWN, STILL_DOWN};
	extern KEY_STATE keys[];
	
	extern const int GROUP_SATURATION;
	extern Draws *groups[];
	typedef int order_t;

	extern Color BLACK;
	extern Color WHITE;

	extern int width;
	extern int height;
	
	extern int WindowHandle;
	
	void window();
	void glut(int, char*[]);
	void resize(int, int);
	void render(void);
	void timer(int);
	void cleanup(void);
	void idle(void);
	
	extern bool twdd;
	void s2d();
	void s3d();
	
	extern std::string *extraction;
	extern LARGE_INTEGER frequency;
	extern LARGE_INTEGER deltatime;
	extern LARGE_INTEGER now;
	extern double dnow;
	void cdelta();
	
	void mdelta();
	extern double delta;
	
	template<class T> struct Reorder;
	
	template<class T> struct Vector {
	public:
		std::vector<T> v;
		bool resort = false;
		void sort() {
			if ( resort ) {
				std::sort(v.begin(), v.end(), en::Reorder<T>());
				
				resort = false;
			}
		}
	};
	
	template<class T> struct List {
	public:
		std::list<T> l;
		bool resort = false;
	};
	
	template<typename T> struct Reorder
	{
		bool operator()(const T a, const T b) const {
		   return a->order < b->order;
		}
	};
	
	// Functor for deleting pointers in vector.
	template<class T> class DeleteVector
	{
		public:
		// Overloaded () operator.
		// This will be called by for_each() function.
		bool operator()(T x) const
		{
			// Delete pointer.
			delete x;
			return true;
		}
	};
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

#ifdef APOLUNE
#include "../h.h"
#else
#include "../../lau/h.h"
#endif

#endif