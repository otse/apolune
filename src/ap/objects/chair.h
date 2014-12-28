#include "../../h.h"

#include "../object.h"

namespace ap {
	namespace objects {
		
		class Chair : public Object {
		public:
		
			struct Model {
				Draws::Model m;
				int sx;
				int sy;
			};
			static const Model apexcool;
			
			
			Chair(const Model);
			virtual ~Chair();
			
			virtual void step();
			virtual void activate();
			
			const Model &m;
		
		};
		
	}
}