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

			const Region &gnormal();

			Tile &mtile(int,int);

			//Craft &gcraft();
			int x;
			int y;

		protected:
			Region normal;

		};
	}
}

#endif