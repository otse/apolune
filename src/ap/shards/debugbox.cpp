#include "../gui/all.h"
#include "../ais/chicken.h"

using namespace en;

namespace ap {
	namespace debugbox {
		extern gui::Box *box;
		void init();
		
		extern bool bpet;
		extern gui::Button *pet;
		void petcb();
		
		extern bool bfs;
		extern gui::Button *fs;
		void fscb();
		
	}
}

gui::Box *ap::debugbox::box;

gui::Button *ap::debugbox::pet;
bool ap::debugbox::bpet = true;

gui::Button *ap::debugbox::fs;
bool ap::debugbox::bfs = false;

// XxX_BakrexzzDE11IGHTZZ4201337_Xx
void ap::debugbox::petcb() {
	LOG("pet cb")
	if ( MOUISLEFT  &&  mou::RELEASED == *mou::active ) {
		if ( bpet ) {
			chicken->remove = true;
			pet->svalue("off");
		} else {
			world->add(chicken);
			pet->svalue("on");
		}
		
		bpet = ! bpet;
		pet->rebuild();
	}
}

void ap::debugbox::fscb() {
	if ( MOUISLEFT  &&  mou::RELEASED == *mou::active ) {
		if ( bfs ) {
			fs->svalue("on");
			//glutReshapeWindow(en::width, en::height);
		} else {
			fs->svalue("off");
			//glutFullScreen();
		}
		
		bfs = ! bfs;
		fs->rebuild();
	}
}

void ap::debugbox::init() {
	using namespace gui;
	box = new Box();
	box->sx(50);
	box->sy(100);
	
	en::add(box);
	
	stats::fps = new Label(box, "fps", "60");
	stats::delta = new Label(box, "delta", "0.003234");
	stats::draws = new Label(box, "draws", "120");
	stats::sprites = new Label(box, "sprites", "20");
	
	fs = new Button(box, "windowed", "", fscb);
	//fs->category = true;
	fs->svalue("on");
	
	pet = new Button(box, "pet", "", petcb);
	//pet->category = true;
	pet->svalue("on");
	
	box->add(stats::fps);
	box->add(stats::delta);
	box->add(stats::draws);
	box->add(stats::sprites);
	
	box->add(fs);
	box->add(pet);
	//debugbox->step();
}