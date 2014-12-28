#ifndef endraws_H
#define endraws_H

#include <iostream>

//#include <algorithm>

#include "engine.h"
#include "texture.h"
#include "anim.h"


namespace en {
	
	struct Drawscmp;
	class Anim;
	struct animinstance;
	
	/**
	 * represents an 'interactable' 2d image
	 * @see dominoes it's a great game
	 */
	class Draws {
	public:
		struct Model {
			Texture *t;
			Region *r;
		};
		
		//Draws(Group, Texture *);
		//Draws(void);
		Draws(Group, Texture *, Region *);
		virtual ~Draws();
		
		animinstance animi;
		
		bool nodraw;
		bool remove;
		bool delete_;
		
		Group group;
		order_t order;
		void sorder(order_t);
		void stackorder();
		
		const char *name;
		float angle;
		
		void mousetrigger();
		
		virtual void click(en::Button, en::Click);
		virtual void hover(en::Hover);
		
		virtual void step();
		virtual void draw();
		virtual void translate();
		virtual bool onscreen();
		
		
		virtual double gx() const;
		virtual double gy() const;
		virtual double gw() const;
		virtual double gh() const;
		
		virtual int gscrx() const;
		virtual int gscry() const;
		
		void sall(double, double, double, double);
		virtual void sx(double);
		virtual void sy(double);
		void sw(double);
		void sh(double);
		
		void stexture(Texture *);
		void sregion(Region *);
		void sa(float);
		//void sxflip(bool);
		//void syflip(bool);
		void scolor(Color *);
		void sprogram(GLuint *);
		
		static int GCOUNT() { return COUNT; }
		//void sanim(Anim *);
		
		bool xflip;
		bool yflip;
		
		float rotate;
	protected:
		bool hovering;
		bool held;
		
		Region *r;
		
		double scale;
		en::Color *color;
		
		double x;
		double y;
		double w;
		double h;
	private:
		static int COUNT;
		
		Texture *texture;
		GLuint *program;
		float a;
		
		int tx;
		int ty;
		int tw;
		int th;
		
	};
	
	typedef Draws::Model dmodel_t;
	
	/*struct Drawscmp
	{
		bool operator()(const Draws * a, const Draws * b) const {
		   return a->order < b->order;
		}
	};*/
	
}
#endif