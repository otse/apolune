#ifndef aprock_H
#define aprock_H

#include "../../h.h"
#include "../sprite.h"
#include "../../en/fbo.h"

namespace ap {
	namespace asteroid {
		class Rock : public Sprite
		{
			public:
				Rock(Asteroid &);
				~Rock();
				
				static int count;

			protected:
				Asteroid &asteroid;

		};
	}
}

#endif