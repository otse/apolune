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

			static const Model single;
			static const Model uni;
			static const Model duo;
			static const Model opposite;
			static const Model tri;
			static const Model quad;

			Truss(Tile &);
			~Truss();

			virtual void click();
			virtual void hover(mou::Hover h);

			virtual void step();
			virtual void draw();

			virtual void refit();

			Model &gmodel();
			Wall *gwall();

		private:
			const Model *model;
			Wall *wall;
			Sprite *outline;

		};
	}
}

#endif