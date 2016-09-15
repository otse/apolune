#ifndef apmeshgrid_H
#define apmeshgrid_H

#include "../../h.h"

#include "../sprite.h"
#include "mesh.h"


namespace ap {
	
	namespace mesh {
		class Grid : public Sprite {
		public:
			Grid(int, Draws::Model);
			~Grid();

			virtual void step();

			void expandfrom(Tile &);
			//void sgrid(int cols, int rows);

			std::unordered_map <std::string, Tile *> tilesum;

			int gpoints() const;
			const Region &gnormal() const;

			Tile &mtile(int,int);

			//Ship &gcraft();
			int x;
			int y;
			bool enabled;

		protected:
			int points;
			Region normal;
			const Draws::Model tilemodel;

		};
	}
}

#endif