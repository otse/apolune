#include "stdafx.h"

#include <string>

#include "lua.h"

/*
lua.L = luaL_newstate();
luaL_openlibs(lua.L);
*/

ap::Lua::Lua() { }

ap::Lua::~Lua() { }

bool ap::Lua::init() { // 
	lua.L = luaL_newstate();
	luaL_openlibs(lua.L);
	
	return true;
}

void ap::Lua::verify() {
	LOG("verifying lua...")
	
}

bool ap::Lua::dostring(const std::string &q) {
	#ifdef INTRP
	std::cout << "r::dostring" << std::endl;
	#endif
	int st = luaL_dostring( lua.L, q.c_str() );
	
	if ( ! lua_isnil(lua.L, -1) ) {
		const char *msg = lua_tostring(lua.L, -1);
		#ifdef INTRP
		if ( msg )
			std::cout << "lua_tostring: " << msg << std::endl;
		#endif
		lua_pop(lua.L, 1);
	}
	
	#ifdef INTRP
	std::cout << "lua returns: " << st << std::endl;
	#endif
	
	return true;
}