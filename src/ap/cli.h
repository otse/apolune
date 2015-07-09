#ifndef apcli_H
#define apcli_H

#include "../h.h"
#include "../en/draws.h"

using namespace en;


namespace ap {

	class CLI : public Draws {
	public:
		struct asd { int asd; };
		
		CLI();
		~CLI();

		void mention(const char *);
	private:
		Draws *pane;
		
		std::vector<Text *> texts;
	};
	
}
#endif