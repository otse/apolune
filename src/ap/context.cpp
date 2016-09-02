#include "stdafx.h"

#include "context.h"

// context

ap::Context::Context()
	: en::Draws::Draws(SORT_UNIMPORTANT, nullptr, nullptr ) ,
	active(-1)	
	{
	
}

ap::Context::~Context() {
	
}

void ap::Context::rebuild() {
	
}