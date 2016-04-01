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
					Texture *t;
					// int variation;
					Region **r;
				};

				static const Model single;
				static const Model uni;

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