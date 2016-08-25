#ifndef apcli_H
#define apcli_H

#include "../h.h"
#include "../en/draws.h"

#include <string>


using namespace en;


namespace ap {

	class CLI : public Draws {
	public:
		struct asd { int asdasd; };
		
		CLI();
		~CLI();

		void mention(const char *);
		void slide();
	private:
		Draws *pane;
		
		std::vector<Text *> texts;
	};
	
}
#endif