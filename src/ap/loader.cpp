#include "stdafx.h"

#include <time.h>
#include <windows.h>
#include <math.h>
#include <sstream>
#include <iomanip>

#include "awesome.h"
#include "loader.h"

#include "../en/engine.h"
#include "../en/font.h"
#include "../en/text.h"

#include "start.h"
#include "def.h"


ap::Loader::Loader()
	: en::Draws(en::GDEF, nullptr, &en::regfluke) ,
	state(BEGIN),
	next(true),
	frame(0)
	{}

ap::Loader::~Loader() {
	LOG("~Loader")
}

void ap::Loader::draw() {}

bool ap::Loader::explain(const char *n) {
	if (frame>1)
		return false;

	std::string syringe = "explain(\"" + std::string(n) + "\");";

	LOG(syringe.c_str())

	as::view->ExecuteJavascript(WSLit(syringe.c_str()), WSLit(""));

	return true;
}

void ap::Loader::step() {
	if (as::view->IsLoading())
		return;

	frame++;

	switch(state) {
		case ERR :

			explain("ERRORRR");
            
            LOG("ERROR lol")
			
			break;

		case BEGIN :
			explain("System");

			// -~-~-~- LOADS
			if (frame == 2) {
				if (!commentary()) {
					state = ERR;
					return;
				}
			}
			// -~-~-~-

			if (frame < 30)
				break;

			frame = 0;
			next = true;
			state = SCRIPTS;
			break;

		case SCRIPTS :
			explain("Scripts");

			// -~-~-~- LOADS

			// -~-~-~-

			if (frame < 20)
				break;

			frame = 0;
			next = true;
			state = SOUNDS;
			break;

		case SOUNDS :
			explain("Sounds");

			// -~-~-~- LOADS

			// -~-~-~-

			if (frame < 10)
				break;

			frame = 0;
			next = true;
			state = TEXTURES;
			break;

		case TEXTURES :
			explain("Textures");

			// -~-~-~- LOADS
			if (frame == 2) {
				loadtex();
			}
			// -~-~-~-

			if (frame < 30)
				break;

			frame = 0;
			next = true;
			state = END;
			break;

		case END :
			if (frame == 2) {
				menu = new start::Menu();
			}
			
			break;

		default:
			break;
	}

}