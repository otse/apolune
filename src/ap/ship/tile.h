#ifndef apshiptile_H
#define apshiptile_H

#include "../../h.h"

#include "../sprite.h"

namespace ap {
	
	namespace ship {
		class Tile : public Sprite {
		public:
			Tile(Grid &, int, int);
			~Tile();

			virtual void click();
			virtual void hover(mou::Hover h);

			virtual void step();

			void attach(Part *);
			void sneighbor(Tile &, int);
			void hasneighbor(int,int);
			void link();

			Grid &grid;

			int gx();
			int gy();

			Part *gpart();
			Tile **gneighbors();

		protected:
			void expand();

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