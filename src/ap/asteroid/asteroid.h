#ifndef apasteroid_H
#define apasteroid_H

#include "../../h.h"
#include "../sprite.h"
#include "../../en/fbo.h"

namespace ap {
	namespace asteroid {
		class Asteroid : public Sprite
		{
			public:
				Asteroid();
				~Asteroid();
				
				static int count;
				
				virtual void step();

				void fillerup();

			protected:
				en::FBO fbo;
				std::unordered_map <std::string, Draws *> tilesum;

		};
	}
}

#endif