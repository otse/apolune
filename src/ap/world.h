#ifndef apworld_H
#define apworld_H

#include <vector>

#include "../h.h"
#include "../en/draws.h"
#include "../en/shader.h"


namespace ap {

	class Asteroid;
	class Hangar;

	class World {
	public:		
		World();
		~World();
		
		void load();
		void step();
		void resize();
		void fbos();
		
		void add(Sprite *);
		void rm(Sprite *);
		
		void lighting();
		void makestars();
		
		//void rm(Sprite *);
		//en::FBO *stars;
		
		Light *cursorlight;
		
		en::Vector<Sprite *> lights;
		std::vector<std::list<Sprite *>::iterator> group;
		en::List<Sprite *> sprites;
		
		en::Shader *lightshader;
		//bool resort;
		//void sort();
	
	protected:
		en::Region fboreg;
	
	private:
		//inline void sresort() { resort = true; }
		
		void steroids();
		en::Draws *backdrop;
		
		Hangar *mom;
		//void asd;
	};
}

#endif