#include <raylib.h>
#include "../include/render.hpp"
#include "../include/data.hpp"
#include "../include/api.hpp"
#include <vector>

#include <iostream>

Texture texture;
std::vector<int> map_data;
Font font;

int main(){
	map_data = Data::fetch_data();

	Render::init(800, 640, texture);
	lua_State* L = Api::init();	

	while(!WindowShouldClose()){	
		BeginDrawing();
			Api::run(L);
			DrawText("sdasdasd", 10, 10, 5, RED);
		EndDrawing();
	}
	
	UnloadFont(font);
	Render::DeInit(texture);
	lua_close(L);
	return 0;
}

