#ifndef apmeshtile_H
#define apmeshtile_H

#include "../../h.h"

#include "../sprite.h"

#include "grid.h"

namespace ap {
	
	namespace mesh {
		class Tile : public Sprite {
		public:

			static const Draws::Model eight;
			static const Draws::Model sixteen;

			Tile(Grid &, Model m, int, int);
			~Tile();

			virtual void click();
			virtual void hover(mou::Hover h);
			virtual void draw();

			virtual void step();

			void attach(Part *);
			void sneighbor(Tile &, int);
			void hasneighbor(int,int);
			void link();

			int gx();
			int gy();

			Grid &ggrid();
			Part *gpart();
			Tile **gneighbors();

		protected:
			void expand();

			Grid &grid;
			Part *part;
			Tile *neighbors[8];

			int x;
			int y;

			double spawned;

		private:
			bool fitted;
		};
	}
}

#endif