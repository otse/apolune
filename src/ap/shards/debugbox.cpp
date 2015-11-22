#include "../gui/all.h"
#include "../ais/chicken.h"

using namespace en;

namespace ap {
	namespace debugbox {
		extern gui::Box *box;
		void init();
		
		extern bool bpet;
		extern gui::Label *pet;
		void petcb();
		
		extern bool bfs;
		extern gui::Label *fs;
		void fscb();
		
	}
}

gui::Box *ap::debugbox::box;

gui::Label *ap::debugbox::pet;
bool ap::debugbox::bpet = true;

gui::Label *ap::debugbox::fs;
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
	
	stats::fps = new Label(box, "fps", "60", false);
	stats::delta = new Label(box, "delta", "0.003234", false);
	stats::draws = new Label(box, "draws", "120", false);
	stats::sprites = new Label(box, "sprites", "20", false);
	
	fs = new Label(box, "windowed", "", true);
	fs->onclick = fscb;
	fs->svalue("on");
	
	pet = new Label(box, "pet", "", true);
	pet->onclick = petcb;
	pet->svalue("on");
	
	box->add(stats::fps);
	box->add(stats::delta);
	box->add(stats::draws);
	box->add(stats::sprites);
	
	box->add(fs);
	box->add(pet);
	//debugbox->step();
}