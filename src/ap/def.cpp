#include "stdafx.h"

#include "def.h"
#include "../en/engine.h"


using namespace ap;

// # fonts
// look in ap/bulk.cpp

// # textures
en::Texture textures::spread("spread.png");

en::Texture textures::normal1("fonts/normal1.png");
en::Texture textures::normal2("fonts/normal2.png");
en::Texture textures::big1("fonts/sheet.png");
en::Texture textures::monospace1("fonts/monospace1.png");
en::Texture textures::monospace2("fonts/monospace2.png");
en::Texture textures::statfont("fonts/statfont.png");
en::Texture textures::valuefont("fonts/valuefont.png");
en::Texture textures::buttonfont("fonts/buttonfont.png");
en::Texture textures::valuefontchangeable("fonts/valuefontchangeable.png");
en::Texture textures::noticefont("fonts/noticefont.png");
en::Texture textures::clifont("fonts/clifont.png");

en::Texture textures::guipieces("guipieces.png");

en::Texture textures::hangar("scenes/hangar.png");
en::Texture textures::hangarlight("lights/hangarlight.png");
en::Texture textures::cursorlight("lights/cursorlight.png");

en::Texture textures::sheet("sheet.png");
en::Texture textures::guy("guy.png");
en::Texture textures::backdrop("earth.png");
en::Texture textures::craftgrid("craft/grid.png");
en::Texture textures::parts("craft/parts.png");

en::Texture textures::rocks("craft/rocks.png");

en::Texture textures::teacup("objects/teacup1.png");
en::Texture textures::apexcoolchair("objects/apexcoolchair.png");
en::Texture textures::apexcooltable("objects/apexcooltable.png");
en::Texture textures::apexradio("objects/apexradio.png");
en::Texture textures::apexconsole("objects/apexconsole.png");
en::Texture textures::apexbrainjar("objects/apexbrainjar.png");
en::Texture textures::bonetable("objects/bonetable.png");
en::Texture textures::tier3switch("objects/tier3switch.png");

en::Texture textures::chicken("ais/chicken.png");
en::Texture textures::tentacle("ais/tentacle.png");

en::Texture textures::groundmist("effects/groundmist.png");
en::Texture textures::ventfume("effects/ventfume.png");
en::Texture textures::fireswirl("effects/fireswirl.png");
en::Texture textures::spawnspark("effects/spawnspark.png");
en::Texture textures::spacedust1("effects/spacedust1.png");
en::Texture textures::healcloud("effects/healcloud.png");
en::Texture textures::playerdeath("effects/playerdeath.png");
en::Texture textures::sparkle1("effects/sparkle1.png");
en::Texture textures::bubbles("effects/bubbles.png");

// # regions
en::Region regions::clipane = {0,0,800,160};
en::Region regions::spread = {0,0,512,512};
en::Region regions::teacup = {0,0,8,8};

en::Region regions::hangar = {0,0,937,497};
en::Region regions::hangarlight = {0,0,145,123};

en::Region regions::ply = {0,0,26,34};
en::Region regions::backdrop = {560,390,1920,1029};

en::Region regions::clawbase = {0,323,26,22};
en::Region regions::asteroid = {0,0,46,49};
en::Region regions::masteroid = {0,321,46,49};
en::Region regions::fluotube = {841,1,24,4};
en::Region regions::fluotubelight = {694,1,140,140};
en::Region regions::cursorlight = {0,0,50,50};
en::Region regions::dust = {840,15,50,50};
en::Region regions::ventfume = {0,0,40,40};
en::Region regions::chicken = {18,0,18,18};
en::Region regions::tentacle = {40,0,40,48};
en::Region regions::tentaclepopped = {0,48*2,40,48};

en::Region regions::tilenew = {32,0,16,16};
en::Region regions::tile = {0,0,8,8};
en::Region regions::tileover = {16,0,16,16};

en::Region regions::trusssingle = {0,0,16,16};
en::Region regions::trussuni = {16,0,16,16};
en::Region regions::trussduo = {32,0,16,16};
en::Region regions::trussopposite = {48,0,16,16};
en::Region regions::trusstri = {64,0,16,16};
en::Region regions::trussquad = {80,0,16,16};
en::Region regions::trussjunction = {96,0,16,16};

en::Region regions::trusssingle_shadow = {0,16,16,16};
en::Region regions::trussuni_shadow = {16,16,16,16};
en::Region regions::trussduo_shadow = {32,16,16,16};
en::Region regions::trussopposite_shadow = {48,16,16,16};
en::Region regions::trusstri_shadow = {64,16,16,16};
en::Region regions::trussquad_shadow = {80,16,16,16};
en::Region regions::trussjunction_shadow = {96,16,16,16};

en::Region regions::wallsingle = {0,32,16,16};
en::Region regions::walluni = {16,32,16,16};
en::Region regions::wallduo = {32,32,16,16};
en::Region regions::wallopposite = {48,32,16,16};
en::Region regions::walltri = {64,32,16,16};
en::Region regions::wallquad = {80,32,16,16};
en::Region regions::walltri2 = {96,32,16,16};
en::Region regions::wallquad2 = {112,32,16,16};

en::Region regions::walliris = {0,32,16,16};

en::Region regions::wallsingle_rear = {0,48,16,16};
en::Region regions::walluni_rear = {16,48,16,16};
en::Region regions::wallduo_rear = {32,48,16,16};
en::Region regions::wallopposite_rear = {48,48,16,16};
en::Region regions::walltri_rear = {64,48,16,16};
en::Region regions::wallquad_rear = {80,48,16,16};
en::Region regions::walltri2_rear = {96,48,16,16};
en::Region regions::wallquad2_rear = {112,48,16,16};

en::Region regions::walliris_rear = {0,48,16,16};

en::Region regions::rocksingle1 = {0,0,8,8};
en::Region regions::rockuni1 = {8,0,8,8};
en::Region regions::rockuni2 = {16,0,8,8};
en::Region regions::rockuni3 = {24,0,8,8};

en::Region regions::apexcoolchair = {0,0,15,18};
en::Region regions::apexcooltable = {0,0,40,16};
en::Region regions::apexradio = {0,0,16,16};
en::Region regions::apexconsole = {0,0,40,16};
en::Region regions::apexbrainjar = {0,0,12,16};
en::Region regions::bonetable = {0,0,40,16};
en::Region regions::tier3switch = {0,0,24,16};

en::Region regions::groundmist = {0,0,40,32};
en::Region regions::fireswirl = {0,0,20,20};
en::Region regions::spawnspark = {0,0,12,12};
en::Region regions::spacedust1 = {0,0,5,5};
en::Region regions::healcloud = {0,0,16,16};
en::Region regions::playerdeath = {0,0,43,43};
en::Region regions::sparkle1 = {0,0,5,5};
en::Region regions::bubble = {0,0,16,16};

en::Region regions::statl = {1,59,14,20};
en::Region regions::statm = {15,59,36,20};
en::Region regions::statr = {51,59,4,20};

en::Region regions::valuel = {30,2,3,18};
en::Region regions::valuem = {33,2,21,18};
en::Region regions::valuer = {54,2,3,18};

en::Region regions::buttonl = {60,2,3,18};
en::Region regions::buttonm = {63,2,14,18};
en::Region regions::buttonr = {77,2,3,18};

en::Region regions::buttonlhover = {83,2,3,18};
en::Region regions::buttonmhover = {86,2,14,18};
en::Region regions::buttonrhover = {100,2,3,18};

en::Region regions::buttonlpressed = {106,2,3,18};
en::Region regions::buttonmpressed = {109,2,14,18};
en::Region regions::buttonrpressed = {123,2,3,18};

en::Region regions::booltrue = {1,25,8,18};
en::Region regions::boolfalse = {10,25,8,18};

en::Region regions::booll = {19,25,1,18};
en::Region regions::boolm = {20,25,14,18};
en::Region regions::boolr = {34,25,1,18};

en::Region regions::noticel = {1,89,14,39};
en::Region regions::noticem = {15,89,46,39};
en::Region regions::noticer = {61,89,16,39};

// #colors
en::Color colors::RED = {1,0,0};
en::Color colors::GREEN = {0,1,0};
en::Color colors::BLUE = {0,0,1};
en::Color colors::YELLOW = {1,1,0};

en::Color colors::CLIPANE = {30/255.f, 33/255.f, 37/255.f};

en::Color colors::BLUEISH = {73/255.f, 83/255.f, 92/255.f};
en::Color colors::MENUGREY = {31/255.f,31/255.f,31/255.f};
en::Color colors::TEXTOFF = {170/255.f, 170/255.f, 170/255.f};
en::Color colors::OBJECTHOVER = {.7f, .7f, 1};
en::Color colors::TOOLTIP = {.8f, .8f, .8};
en::Color colors::GUIGRAY = {222/255.f, 222/255.f, 222/255.f};


// # animations
const en::Anim ap::anims::teacup(nullptr, .2, false,
		{
				{0, 0, 8, 8},
				{8, 0, 8, 8},
				{8*2, 0, 8, 8},
				{8*3, 0, 8, 8},
				{8*4, 0, 8, 8},
				{8*5, 0, 8, 8},
				{8*6, 0, 8, 8}
		}, 7);
		
const en::Anim ap::anims::walk(nullptr, .1, false,
		{
				{7*26, 0, 26, 34},
				{8*26, 0, 26, 34},
				{9*26, 0, 26, 34},
				{10*26, 0, 26, 34},
				{11*26, 0, 26, 34},
				{12*26, 0, 26, 34},
				{13*26, 0, 26, 34},
				{14*26, 0, 26, 34}
		}, 8);
		
/*const en::Anim ap::anims::walk(nullptr, .1D, false,(en::Region[]) {{259, 278, 43, 43},{302, 278, 43, 43},{345, 278, 43, 43},{388, 278, 43, 43},{431, 278, 43, 43},{474, 278, 43, 43},{517, 278, 43, 43},{560, 278, 43, 43}});*/
		
const en::Anim ap::anims::apexconsole(nullptr, .2, false,
		{
				{0, 0, 40, 16},
				{40, 0, 40, 16},
				{40*2, 0, 40, 16},
				{40*3, 0, 40, 16},
				{40*4, 0, 40, 16}
		}, 5);
		
const en::Anim ap::anims::chickenflap(nullptr, .2, false,
		{
				{18, 18, 18, 18},
				{18*2, 18, 18, 18},
				{18*3, 18, 18, 18},
				{18*4, 18, 18, 18}
		}, 4);
		
const en::Anim ap::anims::chickenrun(nullptr, .2, false,
		{
				{18, 36, 18, 18},
				{18*2, 36, 18, 18},
				{18*3, 36, 18, 18},
				{18*4, 36, 18, 18}
		}, 4);
		
const en::Anim ap::anims::tentacleblink(nullptr, .1, false,
		{
				{40, 48, 40, 48},
				{40*2, 48, 40, 48},
				{40*3, 48, 40, 48},
				{40, 0, 40, 48}
		}, 4);
		
const en::Anim ap::anims::tentaclemove(nullptr, .125, false,
		{
				{0, 48*3, 40, 48},
				{40, 48*3, 40, 48},
				{40*2, 48*3, 40, 48},
				{40*3, 48*3, 40, 48},
				{40*4, 48*3, 40, 48},
				{40*5, 48*3, 40, 48},
				{40*6, 48*3, 40, 48},
				{40*7, 48*3, 40, 48}
		}, 8);

const en::Anim ap::anims::tentaclepop(nullptr, .125, false,
		{
				{40,0,40,48},
				{0, 48*2, 40, 48},
				{40, 48*2, 40, 48},
				{40*2, 48*2, 40, 48},
				{40*3, 48*2, 40, 48},
				{40*4, 48*2, 40, 48},
				{40*5, 48*2, 40, 48},
				{40*6, 48*2, 40, 48},
				{40*7, 48*2, 40, 48},
				{40,0,40,48}
		}, 10);
		
const en::Anim ap::anims::fireswirl(nullptr, .075, false,
		{
				{0, 0, 20, 20},
				{20, 0, 20, 20},
				{20*2, 0, 20, 20},
				{20*3, 0, 20, 20},
				{20*4, 0, 20, 20},
				{20*5, 0, 20, 20},
				{20*6, 0, 20, 20},
				{20*7, 0, 20, 20},
				{20*8, 0, 20, 20},
				{20*9, 0, 20, 20},
				{20*10, 0, 20, 20},
				{20*11, 0, 20, 20},
				{20*12, 0, 20, 20},
				{20*13, 0, 20, 20},
				{20*14, 0, 20, 20},
				{20*15, 0, 20, 20},
				{20*16, 0, 20, 20},
				{20*17, 0, 20, 20},
				{20*18, 0, 20, 20},
				{20*19, 0, 20, 20},
				{20*20, 0, 20, 20},
				{20*21, 0, 20, 20},
				{20*22, 0, 20, 20},
		}, 23);

const en::Anim ap::anims::spacedust1(nullptr, .05, false,
		{
				{0, 0, 5, 5},
				{5, 0, 5, 5},
				{10, 0, 5, 5},
				{15, 0, 5, 5}
		}, 4);

const en::Anim ap::anims::healcloud(nullptr, .15, false,
		{
				{0, 0, 16, 16},
				{16, 0, 16, 16},
				{16*2, 0, 16, 16},
				{16*3, 0, 16, 16},
				{16*4, 0, 16, 16},
				{16*5, 0, 16, 16},
				{16*6, 0, 16, 16}
		}, 7);

const en::Anim ap::anims::playerdeath(nullptr, .075, false,
		{
				{0, 0, 43, 43},
				{43, 0, 43, 43},
				{43*2, 0, 43, 43},
				{43*3, 0, 43, 43},
				{43*4, 0, 43, 43},
				{43*5, 0, 43, 43},
				{43*6, 0, 43, 43},
				{43*7, 0, 43, 43},
				{43*8, 0, 43, 43},
				{43*9, 0, 43, 43},
				{43*10, 0, 43, 43},
				{43*11, 0, 43, 43},
				{43*12, 0, 43, 43},
				{43*13, 0, 43, 43}
		}, 14);

const en::Anim ap::anims::sparkle1(nullptr, .05, false,
		{
				{0, 0, 5, 5},
				{5, 0, 5, 5},
				{10, 0, 5, 5},
				{15, 0, 5, 5}
		}, 4);

const en::Anim ap::anims::bubbles(nullptr, .1, false,
		{
				{0, 0, 16, 16},
				{16, 0, 16, 16},
				{16*2, 0, 16, 16},
				{16*3, 0, 16, 16},
				{16*4, 0, 16, 16},
				{16*5, 0, 16, 16},
				{16*6, 0, 16, 16},
				{16*7, 0, 16, 16},
				{16*8, 0, 16, 16},
				{16*9, 0, 16, 16},
				{16*10, 0, 16, 16},
				{16*11, 0, 16, 16},
				{16*12, 0, 16, 16},
				{16*13, 0, 16, 16},
				{16*14, 0, 16, 16},
				{16*15, 0, 16, 16}
		}, 16);

// other
int ap::xof;
int ap::yof;


void ap::loadtex() {
	
	textures::normal2.load();
	//textures::big1.load();
	textures::monospace1.load();
	textures::monospace2.load();
	textures::statfont.load();
	textures::valuefont.load();
	textures::buttonfont.load();
	textures::valuefontchangeable.load();
	textures::clifont.load();
	
	textures::guipieces.load();
	
	textures::hangar.load();
	textures::hangarlight.load();
	textures::cursorlight.load();
	
	textures::guy.load();
	textures::backdrop.load();
	textures::craftgrid.load();
	textures::parts.load();
	
	textures::apexcoolchair.load();
	textures::apexcooltable.load();
	textures::bonetable.load();
	textures::apexradio.load();
	textures::apexconsole.load();
	textures::apexbrainjar.load();
	textures::tier3switch.load();
	
	textures::chicken.load();
	textures::tentacle.load();
    
	textures::groundmist.load();
	textures::ventfume.load();
	//textures::fireswirl.load();
	//textures::spawnspark.load();
	//textures::spacedust1.load();
	//textures::healcloud.load();
	textures::playerdeath.load();
	textures::sparkle1.load();
	textures::bubbles.load();

	textures::rocks.load();
}