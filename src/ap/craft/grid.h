#ifndef apcraftgrid_H
#define apcraftgrid_H

#include "../../h.h"

#include "../sprite.h"


namespace ap {
	
	namespace craft {
		class Grid : public Sprite {
		public:
			Grid(Craft &);
			~Grid();

			virtual void step();

			void expandfrom(Tile &);
			//void sgrid(int cols, int rows);

			en::Vector<Tile *> tiles;
			//std::unordered_map <std::string, Tile *> umap;

			Craft &craft;

			int gtop();
			int gleft();

			Tile &single(int,int);

			//Craft &gcraft();

		protected:
			int beh;

			
		};
	}
}

#endif