#ifndef apcraftgrid_H
#define apcraftgrid_H

#include "../../h.h"

#include "../sprite.h"


namespace ap {
	
	namespace craft {
		class Grid : public Sprite {
		public:
			Grid(Craft &, int c, int r);
			~Grid();

			virtual void step();

			void table();
			//void sgrid(int cols, int rows);

			en::Vector<Tile *> tiles;

			Craft &craft;
			//Craft &gcraft();

		protected:
			
			int cols;
			int rows;
		};
	}
}

#endif