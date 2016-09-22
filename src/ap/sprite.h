#ifndef apsprite_H
#define apsprite_H

#include "../h.h"
#include "../en/draws.h"
#include "world.h"

using namespace en;

namespace ap {

	class Sprite : public Draws {
	public:
		enum PASS {
			FOREGROUND_PASS,
			BACKGROUND_PASS,
			OUTLINE_PASS,
			SHADOW_PASS
		};

		struct Hitbox {
			int x;
			int y;
			int w;
			int h;
		};
		
		Sprite(sort_t, Texture *, Region *);
		//Sprite(const Model);
		virtual ~Sprite();
		
		virtual void click();
		virtual void hover(mou::Hover);
		
		virtual void step();
		
		virtual void translate();
		
		virtual double gx() const;
		virtual double gy() const;
		virtual double gw() const;
		virtual double gh() const;
		
		virtual int gscrx() const;
		virtual int gscry() const;
		
		virtual void sx(double);
		virtual void sy(double);
		
		bool world;
		
		void sworld(bool);
		bool isinside(en::Region *);
		
		static int GCOUNT() { return COUNT; }
	protected:
		double ax;
		double ay;
	private:
		static int COUNT;
		
		//bool 
		Hitbox hitbox;
		int bsx, bsy, bex, bey; // bounds
		
	};
	
	class Simpleanim : public Sprite {
	public:
		Simpleanim(sort_t, en::Texture *, en::Region *, const en::Anim &);
		virtual ~Simpleanim();
		
		const en::Anim &anim;
		virtual void step();
		//,
	};
}
#endif