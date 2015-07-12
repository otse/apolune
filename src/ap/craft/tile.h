#ifndef apcrafttile_H
#define apcrafttile_H

#include "../../h.h"

#include "../sprite.h"

namespace ap {
	
	namespace craft {
		class Tile : public Sprite {
		public:
			Tile(Grid &, int);
			~Tile();

			virtual void click();
			virtual void hover(mou::Hover h);

			virtual void step();

			void attach(Part *);

		protected:
			Grid &grid;
			Part *part;

			int n;
			int x;
			int y;

			double spawned;
		};
	}
}

#endif