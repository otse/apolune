#ifndef apai_H
#define apai_H

#include "../h.h"

#include "object.h"
#include "../en/anim.h"

namespace ap {
	/**
	 * this is the base class for any artificial intelligence
	 * such as an npc or a monster
	 */
	 class AI : public Object {
	 public:
		AI(en::Texture *, en::Region *);
		~AI();
		
		virtual void step();
	 };
	
}

#endif