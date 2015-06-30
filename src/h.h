#ifndef h_H
#define h_H

//#warning building apolune

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "Q:/jsoncpp-master/include/json/json.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <random>

#define EN_WINDOWNAME "Apolune"
#include "en/engine.h"

#define APOLUNESTR "apolune"
#define LOGFILE "log.txt"
#define BASESTR "base"
#define LFCR "\r\n"
#define DEBUGBUILD
#define LOGGING
//#define JSON_DLL

#ifdef LOGGING
	#define LOG(QUOTE) \
	std::cout << QUOTE << std::endl; \
	ap::log << QUOTE << LFCR; \
	ap::log.flush();
#else
	#define LOG(QUOTE) ;
#endif


#define RANDRANGE(base, var) \
	((ap::ilrand() * var) + base) \

typedef struct PHYSFS_File PHYSFS_File; // 'forward declaration'



namespace ap {
	void react();

	class Loader;
	class Menu;
	class Lua;
	class World;
	class Sprite;
	class Emitter;
	class Particle;
	class Object;
	class Light;
	class Mover;
	class Ply;
	class AI;
	class Asteroid;
	
	namespace gui {
		class Box;
		class Element;
		class Label;
		class Button;
	}
	
	namespace ais {
		class Chicken;
		class Tentacle;
	}
	
	namespace start {
		class Menu;
		class Button;
	}
	
	namespace craft {
		class Grid;
	}
	
	extern double zoom;
	extern double zoomto;
	extern double zoomspeed;
	extern bool pointingcoords;
	
	extern bool timeresize;
	void timedresize();
	extern ais::Chicken *chicken;
	
	extern std::ofstream log;
	
	extern std::random_device rd;
	extern std::default_random_engine e1;
	extern std::mt19937 rng;
	extern std::uniform_real_distribution<double> randy;
	inline float ilrand() { return randy(rng); }
	
	extern Loader *loader;
	extern start::Menu *menu;
	
	extern double dresize;
	
	
	extern en::FBO *foreground;
	extern en::FBO *lightmap;
	extern en::FBO *stars;
	
	extern Lua *lua;
	char const VERSION[] = "0.12";
	void roaming();
	extern PHYSFS_File *base;
	bool commentary();
	extern Json::Value midrash;
	
	extern World *world;
	extern Ply *ply;
	
	extern int frameCount;
	extern int fps;
	extern en::Text *overlay;
	
	void loadtex();
	void bulk();
	
	void launchworld();
}

#endif