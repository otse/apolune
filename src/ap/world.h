#ifndef apworld_H
#define apworld_H


#include "../h.h"


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
		
		en::FBO *foreground;
		en::FBO *lightmap;
		en::FBO *stars;

		craft::Craft *craft;
		
		Light *cursorlight;

		std::vector<std::list<Sprite *>::iterator> group;
		en::List<Sprite *> sprites;
		en::Vector<Sprite *> lights;
		
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