#ifndef aploader_H
#define aploader_H

#include "../h.h"

#include "../en/draws.h"

namespace ap {
	class Loader : public en::Draws {
	public:
		enum State {
			BEGIN,
			LUA,
			SOUND,
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
		bool flush;
		double elap;
		LARGE_INTEGER timer;
		double dtimer;
		//en::animinstance cup;
		en::Draws *teacup;
		
		en::Text *top;
		en::Text *wit;
		en::Text *stat;
		en::Draws *spread;
		
	};
}

#endif