#ifndef apcraftpart_H
#define apcraftpart_H

#include "../../h.h"

#include "../sprite.h"

namespace ap {
	
	namespace craft {

		class Part : public Sprite {
		public: enum TYPE {
				PART,
				TRUSS,
				WALL
			};

		protected:
			Part(Craft &, const Model, TYPE);

		public:

			~Part();

			virtual void click();
			virtual void hover(mou::Hover h);
			virtual void step();
			virtual void draw();

			TYPE gtype();
			Craft &gcraft();

			void scan();

		private:
			Craft &craft;
			TYPE type;

		protected:
			
		};
	}
}

#endif