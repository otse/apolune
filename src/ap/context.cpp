#include "stdafx.h"

#include "context.h"

// context

ap::Context::Context()
	: en::Draws::Draws( en::GGUI, nullptr, nullptr ) ,
	active(-1)	
	{
	
}

ap::Context::~Context() {
	
}

void ap::Context::rebuild() {
	
}