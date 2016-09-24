#ifndef apmeshblock_H
#define apmeshblock_H

#include "../../h.h"

#include "../sprite.h"

#include "tile.h"

namespace ap {
	
	namespace mesh {

		class Block : public Part {
		public:
			struct Side {
				en::Region *r;
			};

			static en::Region variations[6];

			static en::Region outlinesingle;
			static en::Region outlineuni;
			static en::Region outlineduo;
			static en::Region outlineopposite;
			static en::Region outlinetri;
			static en::Region outlinequad;
			static en::Region outlinejunction;

			static en::Region blocksingle;
			static en::Region blockuni;
			static en::Region blockduo;
			static en::Region blockopposite;
			static en::Region blocktri;
			static en::Region blockquad;
			static en::Region blockjunction;

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

			//virtual void connect();
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