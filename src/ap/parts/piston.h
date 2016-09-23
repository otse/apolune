#ifndef appartspiston_H
#define appartspiston_H

#include "../../h.h"

#include "../mesh/block.h"
#include "../mesh/tile.h"


namespace ap {
	
	namespace mesh {

		class Piston : public Part {
		public:
			static en::Region single;
			static en::Region uni;
			static en::Region duo;
			static en::Region opposite;
			static en::Region tri;
			static en::Region quad;
			static en::Region junction;

			Piston(Tile &);
			~Piston();

			virtual void step();
			virtual void draw(PASS);

			virtual void connect();
			virtual void refit();

			en::Region* face;

		protected:

		private:

		};
	}
}

#endif