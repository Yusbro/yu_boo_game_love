#include <vector>
#include <raylib.h>

extern "C"{
	#include <lua5.3/lua.h>
	#include <lua5.3/lualib.h>
	#include <lua5.3/lauxlib.h>
}

#include "../include/api.hpp"
#include "../include/render.hpp"

extern std::vector<int> map_data;
extern Texture texture;
extern Font font;

lua_State* Api::init(){
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	
	luaL_dofile(L, "script/player.lua");
	luaL_dofile(L, "script/main.lua");
	
	
	lua_register(L, "spr", Api::DrawSprite);
	lua_register(L, "map", Api::DrawMap);
	lua_register(L, "key", Api::Control);
	lua_register(L, "get_map", Api::MapData);
	lua_register(L, "text", Api::DrawText);
	return L;
}

void Api::run(lua_State* L){
	lua_getglobal(L, "TIC");
	lua_call(L, 0, 0);
}

//for the whole rendering stuff!!!
int Api::DrawSprite(lua_State *L){
	double x = lua_tonumber(L, 1);
	double y = lua_tonumber(L, 2);
	double sprite_id = lua_tonumber(L, 3);
	
	Render::DrawSprite(texture, sprite_id, x, y);
	return 1;	
}


int Api::DrawMap(lua_State *L){
	double ox = lua_tonumber(L, 1);
	double oy = lua_tonumber(L, 2);
	double w = lua_tonumber(L, 3);
	double h = lua_tonumber(L, 4);
	double sx = lua_tonumber(L, 5);
	double sy = lua_tonumber(L, 6);
	
	Render::DrawMap(texture, map_data, ox, oy, w, h, sx, sy);
	
	lua_pop(L, 1);
	return 1;
}

int Api::DrawText(lua_State *L){
	const char* msg = lua_tostring(L, 1);
	int x = lua_tonumber(L, 2);
	int y = lua_tonumber(L, 3);
	
	Render::DrawFont(font, x, y, msg);

	return 1;
}



//for the whole control stuff!!!!
int Api::Control(lua_State *L){
	int clicked_button = 0;

	if(IsKeyPressed(KEY_W)) clicked_button = 1;
	if(IsKeyPressed(KEY_A)) clicked_button = 2;
	if(IsKeyPressed(KEY_S)) clicked_button = 3;
	if(IsKeyPressed(KEY_D)) clicked_button = 4;
	
	lua_pushnumber(L, clicked_button);

	return 1;
}


//fetch da map stuff!!
int Api::MapData(lua_State *L){
	
	int x = lua_tonumber(L, 1);
	int y = lua_tonumber(L, 2);
	
	int tile_value = map_data[x + (y * 1000)];

	lua_pushnumber(L, tile_value);
	return 1;
}

