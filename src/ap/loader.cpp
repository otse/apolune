#include "stdafx.h"

#include <time.h>
#include <windows.h>
#include <math.h>
#include <sstream>
#include <iomanip>

#include "loader.h"

#include "../en/engine.h"
#include "../en/font.h"
#include "../en/text.h"

#include "lua.h"
#include "start.h"
#include "def.h"


ap::Loader::Loader()
	: en::Draws(en::GDEF, nullptr, &en::regfluke) ,
	state(BEGIN),
	spread(nullptr),
	top(nullptr),
	wit(nullptr),
	teacup(nullptr),
	dtimer(0),
	flush(true),
	stat(nullptr),
	elap(0)
	{}

ap::Loader::~Loader() {
	LOG("~Loader")
}

void ap::Loader::draw() {}

bool ap::Loader::explain(const char *q) {
	if ( ! flush )
		return false;
	
	mark();
	
	//LOG(q)
	
	if ( nullptr != wit )
		wit->remove = true; 

	const en::Font &f = ap::normal1;
	en::Color &c = ap::colors::BLUEISH;
	
	wit = new en::Text(en::GDUMP, f, &c, q);
	wit->position();
	wit->sx( (en::width/2) - (wit->gtextw()/2) );
	wit->sy( (en::height/2) - (f.gh()/2) + 25 );
	wit->position();
	
	//en::later(wit);
	flush = false;
	
	return true;
}

void ap::Loader::mark() {
	QueryPerformanceCounter(&timer);
	dtimer = (timer.QuadPart) * 1000.0 / en::frequency.QuadPart;
	
	/*if ( nullptr != stat ) {
		rm(stat);
		
		delete stat;
	}*/
	
	//std::ostringstream strs;
	//LOG(std::setprecision(1) << (float) elap);
	//strs << std::setprecision(5) << (float) elap;
	
	/*std::string thing = std::string("timer ");
	thing.append(strs.str());
	
	stat = new en::Text(monospace, &colors::BLUEISH, thing.c_str() );
	stat->sx(5);
	stat->sy(5);
	stat->position();
	
	later(stat);*/
}

void ap::Loader::step() {
	
	if ( nullptr != teacup )
		teacup->sregion( anims::teacup.progress(teacup->animi) );
	
	static const double TWEEN = 300;
	
	QueryPerformanceCounter(&en::now);
	
	elap = (en::now.QuadPart) * 1000.0 / en::frequency.QuadPart;
	
	if ( BEGIN != state  &&  elap < dtimer + TWEEN )
		return;
		
	switch(state) {
		case ERR :
			if ( ! explain("ERRORRR") )
				return;
            
            LOG("ERROR lol")
			
			break;

		case BEGIN :
			if ( flush ) {
				
				en::roaming();
				
				if ( ! commentary() ) {
					state = ERR;
					return;
				}
				
				textures::sheet.load();
				textures::normal1.load();
				textures::spread.load();
				textures::teacup.load();
				
				const int s = 5;
				teacup = new en::Draws(
						en::GDEF,
						&textures::teacup,
						&regions::teacup);
				teacup->sx( (en::width/2)  - ((teacup->gh()*s)/2) );
				teacup->sy( (en::height/2) - ((teacup->gw()*s)/2) - 70 );
				teacup->sw((teacup->gw()*s));
				teacup->sh((teacup->gh()*s));
				
				spread = new en::Draws(
						en::GPLAYER,
						&textures::spread,
						&regions::spread);
				spread->sw(en::width);
				spread->sh(en::height);
				
				en::later(spread);
				en::later(teacup);
				
				top = new en::Text(en::GGUI, normal1, &colors::BLUEISH, "This might take a whi-- Never mind.");
				top->position();
				top->sx( (en::width/2) - (top->gtextw()/2) );
				top->sy( (en::height/2) - (normal2.gh()/2) - 25 );
				top->position();
				
				en::later(top);
			}
			
			if ( flush ) {
				flush = false;
				mark();
				//dtimer += 1000;
				//mark();
				return;
			}
			/*if ( explain("basic things...") )
				return;*/
			
			
			// İyi akşamlar
			
			
			//teacup = new en::Draws(en::GNONE, &textures::teacup, &regions::teacup);
			
			/*{
			en::Text *wit2 = new en::Text(f, &c, "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
			wit2->sx(20);
			wit2->sy(30);
			wit2->position();
			add(wit2);
			}*/
			
			flush = true;
			state = LUA;
			break;

		case LUA :
			if ( explain("lua...") ) {
				en::later(wit);
				return;
			}
			
			flush = true;
			state = SOUND;
			break;

		case SOUND :
			
			if ( explain("sound...") )
				return;
			
			flush = true;
			state = TEXTURES;
			break;

		case TEXTURES :
			
			if ( explain("textures...") )
				return;
			
			loadtex();
			//bulk(); // TODO: bulk doesn't do annything.
			
			flush = true;
			state = END;
			break;

		case END :
			LOG("END")
			
			top->remove = true;
			wit->remove = true;
			teacup->remove = true;
			spread->remove = true;
			
			menu = new start::Menu();
			en::later(menu);
			
			flush = true;
			state = COUNT;
			break;

		default:
			break;
	}
}