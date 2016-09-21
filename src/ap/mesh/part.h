#ifndef apmeshpart_H
#define apmeshpart_H

#include "../../h.h"

#include "../sprite.h"

#include "tile.h"

namespace ap {
	
	namespace mesh {

		class Part : public Sprite {
		public: enum TYPE {
				PART,
				TRUSS,
				WALL
			};

		protected:

		public:
			Part(Tile &);

			~Part();

			virtual void click();
			virtual void hover(mou::Hover h);
			virtual void step();
			virtual void draw();

			Tile &tile;
			//Ship &craft;
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