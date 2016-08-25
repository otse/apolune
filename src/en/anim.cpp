#include "stdafx.h"

#include <iostream>

#include "anim.h"

using namespace en;


en::Anim::Anim(Texture *t, double spd, bool b, std::initializer_list<Region> f, int) :
	texture(t),
	tween(spd),
	back(b),
	frames(f) {
	
}

en::Anim::~Anim() { }


/*Region *en::Anim::getframe(int i) const {
	return const_cast<Region *>(&frames[i]);
}*/

Region &en::Anim::rgetframe(int i) const {
	return (Region &) frames[i];
}

// comment under construction
Region *en::Anim::progress(animinstance &i) const {
	i.time += delta;
	
	if ( i.time >= tween ) {
		//LOG(i.time << " >= " << tween)
		
		if ( ! back && ! i.reverse ) {
			if ( ++ i.pos == frames.size() )
				i.pos = 0;
		}
		else {
			if ( ! i.reverse  &&  ++ i.pos > ((int)frames.size())-2 ) {
				i.reverse = true;
			} else if ( i.reverse  &&  --i.pos < 1 ) {
				i.reverse = false;
			}
			//LOG(i.pos)
		}
		
		i.time = 0;
	}
	
	return const_cast<Region *>(&frames[i.pos]);
}


/* ###########################
   ## Getters & Setters
   ########################### */
//Texture *en::Anim::gtexture() {
//	return texture;
//}

int en::Anim::gcount() const {
	return frames.size();
}
//Anim::animframes_t* en::Anim::getframes() {
//	return &frames;
//}

//int en::Anim::gtexture() {
//	return texture;
//}