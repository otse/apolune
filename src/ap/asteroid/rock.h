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
<<<<<<< HEAD
				std::vector<Region *> r;
=======
				Region **r;
>>>>>>> ad92b5e523892a8971ccc3709474c1f4556c1e1f
				int variations;
			};

			
			static const Model single;
			static const Model uni;
			static const Model duo;
			static const Model opposite;
			static const Model tri;
			static const Model quad;

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
			int variation;

			Asteroid &asteroid; // nullptr

			Rock *neighbors[8];

		private:
			const Model *model;

		};
	}
}

#endif