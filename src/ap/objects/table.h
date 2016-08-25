#include "../../h.h"

#include "../object.h"

namespace ap {
	namespace objects {
		
		class Table : public Object {
		public:
		
			struct Model {
				Draws::Model m;
			};
			static const Model bone;
			static const Model apexcool;
			
			Table(const Model);
			virtual ~Table();
			
			virtual void step();
			virtual void activate();
			
			const Model &m;
		};
		
	}
}