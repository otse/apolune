#ifndef apcrafttile_H
#define apcrafttile_H

#include "../../h.h"

#include "../sprite.h"

namespace ap {
	
	namespace craft {
		class Tile : public Sprite {
		public:
			Tile(int);
			~Tile();

			virtual void click();
			virtual void hover(mou::Hover h);

			virtual void step();

		protected:
			int n;
			double spawned;

			int x;
			int y;

			int asd;
		};
	}
}

#endif