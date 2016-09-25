#ifndef apworld_H
#define apworld_H

#include "../h.h"


namespace ap {
	
	class Hangar;

	class World {
	public:		
		World();
		~World();
		
		void load();
		void step();
		void resize();
		void rescale();
		void fbos();
		
		void add(Sprite *);
		void rm(Sprite *);
		
		void lighting();
		void makestars();
		
		en::FBO *foreground;
		en::FBO *lightmap;
		en::FBO *stars;

		mesh::Mass *ship;
		
		Sprite *cursorlight;

		std::vector<Sprite *> sprites;
		std::vector<Sprite *> lights;
		
		en::Shader *lightshader;
	
		en::Region fboreg;
	protected:
	
	private:
		//inline void sresort() { resort = true; }
		
		void steroids();
		en::Draws *backdrop;
		
		Hangar *hangar;
		//void asd;
	};
}

#endif