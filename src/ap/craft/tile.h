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
			void hasneighbour(int,int);

			Grid &grid;

			int gx();
			int gy();

			Part *gpart();

			Tile *gtop();
			Tile *gtopleft();
			Tile *gtopright();
			Tile *gbottom();
			Tile *gbottomleft();
			Tile *gbottomright();
			Tile *gleft();
			Tile *gright();

		protected:
			void expand();

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