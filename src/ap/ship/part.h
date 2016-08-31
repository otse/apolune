#ifndef apshippart_H
#define apshippart_H

#include "../../h.h"

#include "../sprite.h"

namespace ap {
	
	namespace ship {

		class Part : public Sprite {
		public: enum TYPE {
				PART,
				TRUSS,
				WALL
			};

		protected:

		public:
			Part(Tile &, const Model, TYPE);

			~Part();

			virtual void click();
			virtual void hover(mou::Hover h);
			virtual void step();
			virtual void draw();

			Tile &tile;
			Ship &craft;
			Emitter *em;

			//TYPE gtype();
			const TYPE type;

			virtual void connect();
			virtual void refit();

		private:

		protected:

		};
	}
}

#endif