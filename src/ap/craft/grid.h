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

			int gtop();
			int gleft();

			Tile &mtile(int,int);

			//Craft &gcraft();

		protected:
			int beh;

			
		};
	}
}

#endif