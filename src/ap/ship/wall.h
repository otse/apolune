#ifndef apshipwall_H
#define apshipwall_H

#include "../../h.h"

#include "part.h"

namespace ap {
	
	namespace ship {
		class Wall : public Part {
		public:
			struct Model {
				Draws::Model m;
				Draws::Model rear;
				int asd;
			};

			static const Model iris;
			static const Model single;
			static const Model uni;
			static const Model duo;
			static const Model opposite;
			static const Model tri;
			static const Model quad;
			static const Model tri2;
			static const Model quad2;

			Wall(Tile &);
			~Wall();

			virtual void click();
			virtual void hover(mou::Hover h);

			virtual void step();
			void draw2(bool);

			virtual void refit();

			//Plate gplate();

		private:
			const Model *model;

			//Plate *plate;
			Sprite *outline;
		};
	}
}

#endif