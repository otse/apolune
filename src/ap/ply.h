#ifndef apply_H
#define apply_H

#include "../h.h"
#include "mover.h"
#include "def.h"


namespace ap {

	typedef bool HEADING;
	#define HEADING_RIGHT false
	#define HEADING_LEFT true

	class Ply : public Mover {
	public:
		Ply();
		~Ply();
		
		void key(void);
		virtual void step();
		
	//protected:
		virtual void translate();
		
		bool guse();
		
		speed_ps speed = 1.D;
		
		virtual void sx(double);
		virtual void sy(double);
	protected:
		Emitter *breath;
		Emitter *spawnplosion;

		double tbulb;
		void bulb();
		void muse();
		en::Text *wisdom = nullptr;

	private:
		bool use;
		bool useing;
		HEADING heading;
		int hp;

		void move(); // ?
		//speed_ps inline floor();
	};
}
#endif