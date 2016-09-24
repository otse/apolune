#ifndef apmeshblock_H
#define apmeshblock_H

#include "../../h.h"

#include "../sprite.h"

#include "tile.h"

namespace ap {
	
	namespace mesh {

		class Block : public Part {
		public:

			// todo: make unmutable
			static en::Region BLOCKS[6];
			static en::Region OUTLINES[6];
			static en::Region SHADOWS[6];

			static en::Region variations[6];

		protected:

		public:
			Block(FIXTURE f, Tile &);
			~Block();

			int asd;

			virtual void click();
			virtual void hover(mou::Hover h);
			virtual void step();
			virtual void draw(PASS);

			//virtual void connect();
			virtual void refit();
			virtual bool preprefit();

		protected:

			virtual const Attitude* entangle() const;

			Draws outline;
			Draws shadow;

		};
	}
}

#endif