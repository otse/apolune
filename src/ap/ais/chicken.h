#ifndef apaischicken_H
#define apaischicken_H

#include "../ai.h"

namespace ap {
	namespace ais {
		class Chicken : public AI {
		public:
			enum Next {
				IDLE,
				RUN,
				
				COUNT
			};
			
			enum Current {
				FLAPPING,
				GOINGLEFT,
				GOINGRIGHT,
				
				NONE
			};
			
			Chicken(en::Region *);
			~Chicken();
			
			virtual void step();
			
			en::Region *bounds;
		private:
			Next next;
			Current current;
			Emitter *feathers;
			
			void donext();
			void docurrent();
			
			double timetonext;
		};
	}
}

#endif