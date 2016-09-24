#ifndef appartspiston_H
#define appartspiston_H

#include "../../h.h"

#include "../mesh/block.h"
#include "../mesh/tile.h"


namespace ap {
	
	namespace mesh {

		class Piston : public Part {
		public:
			static en::Region PISTONS[6];

			Piston(Tile &);
			~Piston();

			virtual void step();
			virtual void draw(PASS);

			virtual void refit();
			virtual const Attitude* entangle();

			int asd;

		protected:

		private:

		};
	}
}

#endif