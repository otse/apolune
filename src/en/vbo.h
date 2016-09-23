#ifndef envbo_H
#define envbo_H

#include "engine.h"

namespace en {
	class VBO {
	public:
		VBO();
		virtual ~VBO();

		int x;
		int y;
		GLuint id;

		void bind();
		void modify();

	private:
	

	};
}

#endif