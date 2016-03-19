#ifndef apcraftgrid_H
#define apcraftgrid_H

#include "../../h.h"

#include "../sprite.h"
#include "tile.h"


namespace ap {
	
	namespace craft {
		class Grid : public Sprite {
		public:
			Grid(Craft &);
			~Grid();

			virtual void step();

			void expandfrom(Tile &);
			//void sgrid(int cols, int rows);

			std::unordered_map <std::string, Tile *> tilesum;

			Craft &craft;

			int gx2();
			int gy2();
			int gw2();
			int gh2();
			int *gdims();

			Tile &mtile(int,int);

			//Craft &gcraft();

		protected:
			int x2;
			int y2;
			int w2;
			int h2;
			int dims[4];
			
		};
	}
}

#endif