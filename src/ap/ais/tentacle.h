#ifndef apaistentacle_H
#define apaistentacle_H

#include "../ai.h"

namespace ap {
	namespace ais {
		class Tentacle : public AI {
		public:
			enum Next {
				NEXT_NONE,
				IDLE,
				BLINK,
				POP,
				UNPOP,
				MOVE,
				
				COUNT
			};
			
			enum Current {
				POPPING,
				UNPOPPING,
				BLINKING,
				GOINGLEFT,
				GOINGRIGHT,
				
				CURRENT_NONE
			};
			
			Tentacle(en::Region *);
			~Tentacle();
			
			virtual void step();
			
			en::Region *bounds;
		private:
			Next next;
			Current current;
			
			void donext();
			void docurrent();
			
			double timetonext;
		};
	}
}

#endif