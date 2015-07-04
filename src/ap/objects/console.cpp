#include "console.h"

#include "../def.h"

ap::objects::Console::Console() :
	ap::Object::Object(en::GDEF, &textures::tier3switch, &regions::tier3switch) //,
	//anim(nullptr)
	{
	LOG("terminal")
}

ap::objects::Console::~Console() {

}

void ap::objects::Console::step() {
	Object::step();
} 

void ap::objects::Console::activate() {
	LOG("DOING SOMETHING WITH CONSOLE DUDE")
} 