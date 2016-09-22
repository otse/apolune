#ifndef apmeshblock_H
#define apmeshblock_H

#include "../../h.h"

#include "../sprite.h"

#include "tile.h"

namespace ap {
	
	namespace mesh {

		class Block : public Part {
		public:
			enum TYPE { // hm bad
				PART,
				TRUSS,
				WALL
			};

			struct Side {
				en::Region *r;
			};

			static const Side single;
			static const Side uni;
			static const Side duo;
			static const Side opposite;
			static const Side tri;
			static const Side quad;
		protected:

		public:
			Block(FIXTURE f, Tile &);
			~Block();

			int asd;

			virtual void click();
			virtual void hover(mou::Hover h);
			virtual void step();
			virtual void draw(PASS);

			//Ship &craft;
			Emitter *em;

			//TYPE gtype();
			//const TYPE type;

			virtual void connect();
			virtual void refit();

		private:
			Draws outline;
			Draws shadow;

			const Side *side;

			void junction(int, int);
			Sprite *junctions[4];


		protected:

		};
	}
}

#endif