#ifndef aplua_H
#define aplua_H

#include "../h.h"

extern "C" {
	#include "Q:/lua-5.2.3/src/lua.h"
	#include "Q:/lua-5.2.3/src/lauxlib.h"
	#include "Q:/lua-5.2.3/src/lualib.h"
}

/*#include "../../../DEPS/Binaries-LuaDist-batteries-0.9.8-Windows-x86/include/lua.h"
#include "../../../DEPS/Binaries-LuaDist-batteries-0.9.8-Windows-x86/include/lauxlib.h"
#include "../../../DEPS/Binaries-LuaDist-batteries-0.9.8-Windows-x86/include/lualib.h"*/


namespace ap {
	class Lua {
		public:
		Lua();
		~Lua();
		
		struct _lua {
			lua_State *L;
		};
		_lua lua;
		
		bool init();
		void verify();
		bool dostring(const std::string &);
	};
}

#endif