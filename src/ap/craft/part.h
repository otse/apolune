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

		public:
			Part(Tile &, const Model, TYPE);

			~Part();

			virtual void click();
			virtual void hover(mou::Hover h);
			virtual void step();
			virtual void draw();

			virtual void translate();	

			Tile &tile;
			Craft &craft;
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