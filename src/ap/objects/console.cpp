#include "console.h"

#include "../def.h"

ap::objects::Console::Console() :
	ap::Object::Object(en::GDEF, &textures::apexconsole, &regions::apexconsole) ,
	anim(anims::apexconsole)
	{
	
}

ap::objects::Console::~Console() {

}

void ap::objects::Console::step() {
	Object::step();
	
	sregion( anim.progress(animi) );
}