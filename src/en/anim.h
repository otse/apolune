#ifndef enanim_H
#define enanim_H

#include "engine.h"
#include "draws.h"
#include "texture.h"
#include "anim.h"


namespace en {
	
	struct animinstance;

	class Anim {
	public:
		
		Anim(Texture *, double sp, bool, const Region[], int);
		~Anim();
		
		const Region *frames;
		//const Region framesr[];
		
		//Texture gtexture();
		
		Region *getframe(int) const;
		Region &rgetframe(int) const;
		Region *progress(animinstance &) const;
		
		int gcount() const;
		//void getframe(counter_t);
		//animframes_t *getframes();
	private:
		double tween;
		Texture *texture;
		int count;
		const bool back;
		//gstart();
		//gend();
	};
}
	


#endif