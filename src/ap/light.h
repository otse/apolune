#ifndef aplight_H
#define aplight_H

#include "../h.h"
#include "sprite.h"

namespace ap {
	/**
	 * creates and adds the light
	 * assumes ap::world is in play
	 */
	class Light : public Sprite {
	public:
		enum Type {
			None,
			CURSOR,
			FLUOTUBE,
		};
		
		struct Model {
			Light::Type t;
			const en::Region &r;
			const en::Region &lr;
		};
		
		Light(const Model &, int, int);
		~Light();
		
		//virtual void draw();
		
		Sprite *light;
		
		virtual void sx(double);
		virtual void sy(double);
	private:
		int ox;
		int oy;
		Model model;
	};
	
	
}

#endif