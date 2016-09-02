#ifndef entext_H
#define entext_H

#include "engine.h"


namespace en {	
	class Font;
	
	class Text : public Draws {
	public:
		Text(group_t g, const Font &, Color *, const char *);
		virtual ~Text();
		/*@ovr*/ virtual void draw();
		
		void position();
		int gtextw();
		//int smaxw();
		const char *gquote();
		double scale;
	private:
		signed char bs = 127;
		int width;
		const Font &f;
		std::vector<Draws *> draws;
		const char *q;
		//void addglyph();
		//void move();
	};
}
#endif