#ifndef apmeshblock_H
#define apmeshblock_H

#include "../../h.h"

#include "../sprite.h"

#include "tile.h"

namespace ap {
	
	namespace mesh {

		class Block : public Part {
		public:
			struct Type {
				en::Texture& t;
			};

			static const Type Aluminium;
			static const Type Rock;
			static const Type Rusty;

			// todo: make unmutable
			static en::Region BLOCKS[6];
			static en::Region OUTLINES[6];
			static en::Region SHADOWS[6];

			static en::Region variations[6];

			Block(FIXTURE f, Tile &, const Type &);
			~Block();

			int asd;
			const Type &type;

			virtual void step();
			virtual void draw(PASS);

			virtual void refit();
			virtual const Attitude* entangle();

		protected:
			Draws outline;
			Draws shadow;

		};
	}
}

#endif