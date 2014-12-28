#ifndef enshader_H
#define enshader_H

#include "engine.h"


namespace en {
	class Shader {
	public:
		Shader(const char *, const char *);
		~Shader();
		
		void create();
		void link();
		
		const char *vertex;
		const char *fragment;
		
		GLuint vid, fid, pid;
	};
	
	bool shadererrors(GLuint &);
	
}

#endif