#ifndef h_H
#define h_H

//#warning building apolune
// mingw32-make in /src

// #pragma GCC diagnostic ignored "-Wwrite-strings"

#include <cmath>

#include "Q:/jsoncpp-master/include/json/json.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <random>
#include <unordered_map>


#define EN_WINDOWNAME "Apolune"
#include "en/engine.h"

#define APOLUNESTR "apolune"
#define LOGFILE "log.txt"
#define LFCR "\r\n"
#define LOGGING
//#define JSON_DLL

#ifdef LOGGING
	#define LOG(QUOTE) \
	{ \
	std::cout << QUOTE << std::endl; \
	ap::log << QUOTE << LFCR; \
	ap::log.flush(); \
	}
#else
	#define LOG(QUOTE) ;
#endif


#define RANDRANGE(base, var) \
	((ap::ilrand() * var) + base) \

using namespace en;


namespace ap {
	class CLI;
	class Loader;
	class Menu;
	class World;
	class Sprite;
	class Emitter;
	class Particle;
	class Object;
	class Light;
	class Mover;
	class Ply;
	class AI;

	namespace asteroid {
		class Asteroid;
		class Rock;
	}
	
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

	namespace mesh {
		class Mass;
		class Grid;
		class Tile;
		class Part;
		class Block;

	}
	
	namespace ship {
		class Ship;
		class Truss;
		class Wall;
	}

	extern ais::Chicken *chicken;
	
	extern std::ofstream log;
	
	extern std::random_device rd;
	extern std::default_random_engine e1;
	extern std::mt19937 rng;
	extern std::uniform_real_distribution<double> randy;
	inline double ilrand() { return randy(rng); }
	
	extern CLI *cli;
	extern Loader *loader;
	extern start::Menu *menu;
	
	char const VERSION[] = "0.12";
	
	bool commentary();
	extern Json::Value midrash;
	
	extern World *world;
	extern Ply *ply;
	
	extern int frameCount;
	extern int fps;

	extern int scale;

	extern double zoom;
	extern double zoomto;
	extern double zoomspeed;

	extern int camerax;
	extern int cameray;

	extern bool pointingcoords; // niy
	
	void loadtex();
	void bulk();
	
	void launchworld();

	const static en::sort_t SORT_PLAYER = 11;
	const static en::sort_t SORT_HIGH = 10;
	const static en::sort_t SORT_UNIMPORTANT = 5;
	const static en::sort_t SORT_BACKGROUND = 4;
}

#endif