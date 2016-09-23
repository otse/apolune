#ifndef apmeshtile_H
#define apmeshtile_H

#include "../../h.h"

#include "../sprite.h"

#include "mesh.h"
#include "part.h"
#include "grid.h"

namespace ap {
	
	namespace mesh {
		class Tile : public Sprite {
		public:
			typedef int variation_t;
			
			const variation_t variation;

			static const Draws::Model eight;
			static const Draws::Model sixteen;

			Tile(Grid &, Model m, int, int);
			~Tile();

			virtual void click();
			virtual void hover(mou::Hover h);
			virtual void draw();

			virtual void step();

			void attach(Part &);
			void detach(FIXTURE);

			void sneighbor(Tile &, int);
			void hasneighbor(int,int);
			void link();

			int gx();
			int gy();

			Grid &grid;
			Part *gpart(FIXTURE);
			Part *gfore();
			Part *gaft();

			Part *seethrough;

			Tile **gneighbors();

		protected:
			void expand();
			
			Part *fore;
			Part *aft;
			Tile *neighbors[8];

			int x;
			int y;

			double spawned;

		};
	}
}

#endif