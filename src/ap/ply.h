#ifndef apply_H
#define apply_H

#include "../h.h"

#include "def.h"
#include "mover.h"
#include "mesh/part.h"


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
		
		bool guse();
		
		speed_ps speed = 1;

		std::string partname;
		mesh::Part *part;
		
		double orientation;
		virtual void sx(double);
		virtual void sy(double);
	protected:
		//virtual void translate();

		Emitter *breath;
		Emitter *spawnplosion;

		double tbulb;
		void bulb();
		void muse();

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