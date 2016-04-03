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
					Region **r;
					int variations;
				};

				static const Model single;
				static const Model uni;

				Rock(Asteroid &, int, int);
				~Rock();
				
				static int count;

				virtual void connect();
				virtual void refit();

				int gx();
				int gy();

				Rock **gneighbors();

			protected:
				int x;
				int y;

				Asteroid &asteroid; // nullptr

				Rock *neighbors[8];

			private:
				const Model *model;

		};
	}
}

#endif