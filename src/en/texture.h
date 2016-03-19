#ifndef entexture_H
#define entexture_H

#include "engine.h"


namespace en {
	class Texture {
	protected:
		Texture(int, int);
	public:
		Texture(const char *);
		virtual ~Texture();
		
		static bool NOBIND;
		
		void create();
		bool load();
		
		virtual void bind();
		virtual void unbind();
		
		GLuint gtid();
		int gw();
		int gh();
		int gn();
		bool gsuccess();
		
	protected:
		GLuint tid;
		bool success;

		void sw(int);
		void sh(int);
		
		int w;
		int h;
		int n;
		
	private:
		const char *file;
	};
}
#endif