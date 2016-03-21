#ifndef apasteroid_H
#define apasteroid_H

#include "../../h.h"
//#include "font.h"
#include "../mover.h"

namespace ap {
	namespace asteroid {
		class Asteroid : public Mover
		{
			public:
			Asteroid(en::Texture *, en::Region *);
			~Asteroid();
			
			static int count;
			
			virtual void step();
			//void rotation();
			
			int smthng;
			char *elsee;
		};
	}
}

#endif