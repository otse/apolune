/* 
 * File:   bar.h
 * Author: Petrus
 *
 * Created on January 10, 2015, 11:59 PM
 */

#ifndef BAR_H
#define	BAR_H

#include "h.h"

namespace lau {
	class Bar : public en::Draws {
	public:
		Bar();
		virtual ~Bar();
		
		virtual void step();
		virtual void draw();
		
		void rewit(const char *);
		
		std::string wit;
		
		en::Region rbar;
		en::FBO *barfbo;
		en::Text *lowtext;
		en::Text *text;
		
		en::Draws *stars;
		en::Draws *starsl;
		en::Draws *starsr;
		
		int progress;
	};
}

#endif	/* BAR_H */

