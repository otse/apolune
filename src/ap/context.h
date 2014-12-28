#ifndef apcontext_H
#define apcontext_H

#include "../h.h"
#include "../en/draws.h"


namespace ap {
	class Context : en::Draws {
		Context();
		~Context();
		
		void rebuild();
		int active;
	};
}

#endif