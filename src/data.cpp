#include "../include/data.hpp"
#include <vector>
#include <iostream>
extern "C"{
	#include <lua.h>
	#include <lualib.h>
	#include <lauxlib.h>
}


std::vector<int> Data::fetch_data(){	
	std::vector<int> data;

	//starting da lua stuff!!
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	
	luaL_dofile(L,"asset/tile_map.lua");
	
	lua_getglobal(L, "stuff");
	
	lua_getfield(L, -1, "layers");
	lua_geti(L, -1, 1);
	
	lua_getfield(L, -1, "data");
	
	int table_length = luaL_len(L, -1);
	std::cout<<table_length<<std::endl;
	for(int i=1; i<table_length; i++){
		lua_geti(L, -1, i);
		int value = lua_tointeger(L, -1);
		data.push_back(value);
		lua_pop(L, 1);
	}

	lua_close(L);
	return data;
}



