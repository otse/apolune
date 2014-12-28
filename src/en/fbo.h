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
		
		void reset();
		//virtual void bind();
		//virtual void unbind();
		
		GLuint gfbid();
		Draws &gdraws();
	private:
		Region &region;
		Draws draws;
		GLuint fb;
	};
}

#endif