#ifndef apcrafttruss_H
#define apcrafttruss_H

#include "../../h.h"

#include "all.h"

namespace ap {
	
	namespace craft {
		class Truss : public Part {
		public:
			struct Model {
				Draws::Model m;
				int strength;
				int weight;
			};

			static const Model metal;
			static const Model angledmetal;

			Truss(Craft &, const Model m, int x, int y);
			~Truss();			

			virtual void click();
			virtual void hover(mou::Hover h);

			virtual void step();
			virtual void draw();

			Wall *gwall();

		protected:
			Wall *wall;
			Sprite *outline;
		};
	}
}

#endif