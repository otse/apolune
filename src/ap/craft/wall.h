#ifndef apcraftwall_H
#define apcraftwall_H

#include "../../h.h"

#include "part.h"

namespace ap {
	
	namespace craft {
		class Wall : public Part {
		public:
			struct Model {
				Draws::Model m;
				int asd;
			};

			static const Model iris;
			static const Model single;
			static const Model uni;
			static const Model duo;
			static const Model opposite;
			static const Model tri;
			static const Model quad;

			Wall(Craft &, const Model m);
			~Wall();			

			virtual void click();
			virtual void hover(mou::Hover h);

			virtual void step();

			//Plate gplate();

		protected:
			//Plate *plate;
			Sprite *outline;
		};
	}
}

#endif