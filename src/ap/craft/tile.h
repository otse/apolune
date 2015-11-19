#ifndef apcrafttile_H
#define apcrafttile_H

#include "../../h.h"

#include "../sprite.h"

namespace ap {
	
	namespace craft {
		class Tile : public Sprite {
		public:
			Tile(Grid &, int, int);
			~Tile();

			virtual void click();
			virtual void hover(mou::Hover h);

			virtual void step();

			void attach(Part *);
			void neighbour(Tile &);

			Grid &grid;

			int gx();
			int gy();

			Part *gpart();

			Tile *gtop();
			Tile *gbottom();
			Tile *gleft();
			Tile *gright();

		protected:
			Part *part;

			Tile *top;
			Tile *topleft;
			Tile *topright;
			Tile *bottom;
			Tile *bottomleft;
			Tile *bottomright;
			Tile *left;
			Tile *right;

			int x;
			int y;

			double spawned;
		};
	}
}

#endif