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
				struct Model {
					Draws::Model m;
				};

				Rock(Asteroid &, int, int);
				~Rock();
				
				static int count;

			protected:
				int x;
				int y;
				Asteroid &asteroid; // nullptr

		};
	}
}

#endif