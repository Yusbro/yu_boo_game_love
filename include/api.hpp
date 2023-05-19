
extern "C"{	
	#include <lua5.3/lua.h>
	#include <lua5.3/lualib.h>
	#include <lua5.3/lauxlib.h>
}



namespace Api{
	lua_State* init();	
	void run(lua_State* L);

	//the whole rendering bits!!!
	int DrawSprite(lua_State *L);
	int DrawMap(lua_State *L);
	int DrawText(lua_State *L);

	//the whole control stuff!!!!
	int Control(lua_State *L);
	
	//fetch the map stuff!!!
	int MapData(lua_State *L);
}
