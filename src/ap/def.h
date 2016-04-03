#ifndef apdef_H
#define apdef_H

#include "../h.h"
#include "../en/draws.h"
#include "../ap/light.h"
#include "../en/texture.h"
#include "../en/anim.h"
#include "emitter.h"


namespace ap {
	
	extern const en::Font normal1;
	extern const en::Font normal2;
	extern const en::Font big1;
	extern const en::Font monospace1;
	extern const en::Font monospace2;
	
	extern const en::Font statfont;
	extern const en::Font valuefont;
	extern const en::Font buttonfont;
	extern const en::Font valuefontchangeable;
	extern const en::Font noticefont;
	extern const en::Font clifont;
	
	namespace textures {
		extern en::Texture spread;
		
		extern en::Texture normal1;
		extern en::Texture normal2;
		extern en::Texture big1;
		extern en::Texture monospace1;
		extern en::Texture monospace2;
		extern en::Texture statfont;
		extern en::Texture valuefont;
		extern en::Texture buttonfont;
		extern en::Texture valuefontchangeable;
		extern en::Texture noticefont;
		extern en::Texture clifont;
		
		extern en::Texture guipieces;
		
		extern en::Texture teacup;
		
		extern en::Texture hangar;
		extern en::Texture hangarlight;
		
		extern en::Texture sheet;
		extern en::Texture guy;
		extern en::Texture backdrop;
		extern en::Texture craftgrid;
		extern en::Texture parts;

		extern en::Texture rocks;		
		
		extern en::Texture apexcoolchair;
		extern en::Texture apexcooltable;
		extern en::Texture apexradio;
		extern en::Texture apexconsole;
		extern en::Texture apexbrainjar;
		extern en::Texture bonetable;
		extern en::Texture tier3switch;
		
		extern en::Texture chicken;
		extern en::Texture tentacle;
		
		extern en::Texture fireswirl;
		extern en::Texture groundmist;
		extern en::Texture ventfume;
		extern en::Texture spawnspark;
		extern en::Texture spacedust1;
		extern en::Texture healcloud;
		extern en::Texture playerdeath;
		extern en::Texture sparkle1;
		extern en::Texture bubbles;
	}
	
	namespace regions {
		extern en::Region spread;
		
		extern en::Region hangar;
		extern en::Region hangarlight;
		
		extern en::Region clipane;
		extern en::Region ply;
		extern en::Region backdrop;
		
		extern en::Region clawbase;
		extern en::Region asteroid;
		extern en::Region masteroid;

		extern en::Region trusssingle;
		extern en::Region trussuni;
		extern en::Region trussduo;
		extern en::Region trussopposite;
		extern en::Region trusstri;
		extern en::Region trussquad;
		extern en::Region trussjunction;

		extern en::Region trusssingle_shadow;
		extern en::Region trussuni_shadow;
		extern en::Region trussduo_shadow;
		extern en::Region trussopposite_shadow;
		extern en::Region trusstri_shadow;
		extern en::Region trussquad_shadow;
		extern en::Region trussjunction_shadow;
		
		extern en::Region walliris;
		extern en::Region wallsingle;
		extern en::Region walluni;
		extern en::Region wallduo;
		extern en::Region wallopposite;
		extern en::Region walltri;
		extern en::Region wallquad;
		extern en::Region walltri2;
		extern en::Region wallquad2;

		extern en::Region rocksingle1;
		extern en::Region rockuni1;
		extern en::Region rockuni2;
		extern en::Region rockuni3;

		extern en::Region rockcorner;
		extern en::Region rock;

		extern en::Region walliris_rear;
		extern en::Region wallsingle_rear;
		extern en::Region walluni_rear;
		extern en::Region wallduo_rear;
		extern en::Region wallopposite_rear;
		extern en::Region walltri_rear;
		extern en::Region wallquad_rear;
		extern en::Region walltri2_rear;
		extern en::Region wallquad2_rear;

		extern en::Region tilenew;
		extern en::Region tile;
		extern en::Region tileover;
		
		extern en::Region fluotube;
		extern en::Region fluotubelight;
		extern en::Region cursorlight;

		
		extern en::Region dust;
		extern en::Region groundmist;
		extern en::Region ventfume;
		extern en::Region fireswirl;
		extern en::Region spawnspark;
		extern en::Region spacedust1;
		extern en::Region healcloud;
		extern en::Region playerdeath;
		extern en::Region sparkle1;
		extern en::Region bubble;
		
		extern en::Region teacup;
		extern en::Region apexcoolchair;
		extern en::Region apexcooltable;
		extern en::Region apexradio;
		extern en::Region apexconsole;
		extern en::Region apexbrainjar;
		extern en::Region bonetable;
		extern en::Region tier3switch;
		
		extern en::Region chicken;
		extern en::Region tentacle;
		extern en::Region tentaclepopped;
		
		extern en::Region statl;
		extern en::Region statm;
		extern en::Region statr;
		
		extern en::Region valuel;
		extern en::Region valuem;
		extern en::Region valuer;
		
		extern en::Region buttonl;
		extern en::Region buttonm;
		extern en::Region buttonr;
		
		extern en::Region buttonlhover;
		extern en::Region buttonmhover;
		extern en::Region buttonrhover;
		
		extern en::Region buttonlpressed;
		extern en::Region buttonmpressed;
		extern en::Region buttonrpressed;
		
		extern en::Region booltrue;
		extern en::Region boolfalse;
		
		extern en::Region booll;
		extern en::Region boolm;
		extern en::Region boolr;
		
		extern en::Region noticel;
		extern en::Region noticem;
		extern en::Region noticer;
	}
	
	namespace anims {
		extern const en::Anim walk;
		extern const en::Anim chickenflap;
		extern const en::Anim chickenrun;
		//extern const en::Anim tentacleidle;
		extern const en::Anim tentacleblink;
		extern const en::Anim tentaclemove;
		extern const en::Anim tentaclepop;
		extern const en::Anim apexconsole;
		extern const en::Anim teacup;
		extern const en::Anim fireswirl;
		extern const en::Anim spacedust1;
		extern const en::Anim healcloud;
		extern const en::Anim playerdeath;
		extern const en::Anim sparkle1;
		extern const en::Anim bubbles;
	}
	
	namespace colors {
		extern en::Color RED;
		extern en::Color GREEN;
		extern en::Color BLUE;
		extern en::Color YELLOW;
		
		extern en::Color CLIPANE;
		
		extern en::Color BLUEISH;
		extern en::Color MENUGREY;
		extern en::Color TEXTOFF;
		extern en::Color OBJECTHOVER;
		extern en::Color TOOLTIP;
		extern en::Color GUIGRAY;
	}
	
	namespace lights {
		extern const Light::Model CURSOR;
		extern const Light::Model FLUOTUBE;
	}
	
	typedef float speed_ms_t;
	typedef float ms_t;
	typedef double speed_ps;
	extern int xof;
	extern int yof;
}

#endif