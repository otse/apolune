#ifndef apemitter_H
#define apemitter_H

#include "../h.h"

#include "sprite.h"


namespace ap {
	class Emitter : public Sprite {
		friend Particle;
	public:
		struct Model {
			const en::Draws::Model &m;
			double emit;
			double emitvary;
			double particlekill;
			double emitterkill;
			double waitforparticle;
			double fadein;
			double fadeout;
			float alpha;
			float alphavary;
			double spin;
			double spinvary;
			double move;
			double anglerange[2];
			double basesize;
			double sizevary;
			double grow;
			double pullangle;
			double pullangleforce;
			const en::Anim *anim;
		};
		static const Model breathbubbles;
		static const Model spawnplosion;
		static const Model ventfume;
		static const Model placesparks;
		
		Emitter(const Model &);
		virtual ~Emitter();
		
		std::vector<Particle *> p;
		
		virtual void step();
		virtual void draw();
		
		double kill;
		double timer;
		
		const Model &gm();
		
	protected:
		bool wantsout;
		
	private:
		const Model &m;
	};
	
	class Particle : public Sprite {
	public:
		Particle(Emitter *const);
		virtual ~Particle();
		
		double spawn;
		bool clockwise;
		double spin;
		float rotate;
		double kill;
		double timer;
		double angle;
		double alpha;
		
		virtual void step();
	private:
		Emitter *e;
	};
};

#endif