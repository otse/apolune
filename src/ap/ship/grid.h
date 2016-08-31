#ifndef apshipgrid_H
#define apshipgrid_H

#include "../../h.h"

#include "../sprite.h"
#include "tile.h"


namespace ap {
	
	namespace ship {
		class Grid : public Sprite {
		public:
			Grid(Ship &);
			~Grid();

			virtual void step();

			void expandfrom(Tile &);
			//void sgrid(int cols, int rows);

			std::unordered_map <std::string, Tile *> tilesum;
			
			Ship &craft;

			const Region &gnormal();

			Tile &mtile(int,int);

			//Ship &gcraft();
			int x;
			int y;

		protected:
			Region normal;

		};
	}
}

#endif