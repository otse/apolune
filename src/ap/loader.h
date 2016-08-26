#ifndef aploader_H
#define aploader_H

#include "../h.h"

#include "../en/draws.h"

namespace ap {
	class Loader : public en::Draws {
	public:
		enum State {
			BEGIN,
			SCRIPTS,
			SOUNDS,
			TEXTURES,
			END,
			
			COUNT,
			ERR
		} state;
		
		Loader();
		~Loader();
		
		virtual void draw();
		virtual void step();
		
	private:
		bool explain(const char *);
		void mark();

		int frame;
		bool next;
	};
}

#endif