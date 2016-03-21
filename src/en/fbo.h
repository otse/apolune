#ifndef enfbo_H
#define enfbo_H

#include "engine.h"
#include "draws.h"
#include "texture.h"


namespace en {
	class FBO : public Texture {
	public:
		FBO(Color *, Region &r);
		virtual ~FBO();
		
		Color *clear;
		
		//void reset();
		void resize(int,int);
		
		Region &gr();
		GLuint gfbid();
		Draws &gdraws();

		int x;
		int y;

	private:
		Region &region;
		Draws draws;
		GLuint fb;
	};
}

#endif