#ifndef apobjectsconsole_H
#define apobjectsconsole_H

#include "../../h.h"

#include "../object.h"

namespace ap {
	namespace objects {
		
		class Console : public Object {
		public:
			Console();
			virtual ~Console();
			
			const en::Anim &anim;
			
			virtual void step();
			//virtual void activate();
		};
		
	}
}

#endif