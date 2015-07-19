#ifndef apcraftpart_H
#define apcraftpart_H

#include "../../h.h"

#include "../sprite.h"

namespace ap {
	
	namespace craft {

		class Part : public Sprite {
		public: enum TYPE {
				PART,
				TRUSS,
				WALL
			};

		protected:
			Part(Tile &, const Model, TYPE);

		public:

			~Part();

			virtual void click();
			virtual void hover(mou::Hover h);
			virtual void step();
			virtual void draw();

			Tile &tile;
			Craft &craft;
			Emitter *em;

			TYPE gtype();

			virtual void refit();

		private:
			TYPE type;

		protected:

		};
	}
}

#endif