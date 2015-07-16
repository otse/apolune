#ifndef apcrafttile_H
#define apcrafttile_H

#include "../../h.h"

#include "../sprite.h"

namespace ap {
	
	namespace craft {
		class Tile : public Sprite {
		public:
			Tile(Grid &, int, int, int);
			~Tile();

			virtual void click();
			virtual void hover(mou::Hover h);

			virtual void step();

			Grid &ggrid();
			
			void attach(Part *);
			void neighbour(Tile &);

		protected:
			Grid &grid;
			Part *part;

			Tile *top;
			Tile *bottom;
			Tile *left;
			Tile *right;

			int n;
			int x;
			int y;

			double spawned;
		};
	}
}

#endif