#include "../include/render.hpp"
#include <raylib.h>


#define SCREEN_TILE_SIZE 20

extern Font font;


void Render::init(int width, int height, Texture &tilemap){
	InitWindow(width, height, "YU!!");
	SetTargetFPS(60);
	tilemap = LoadTexture("asset/tilemap.png");
	font = LoadFont("asset/04B_30__.TTF");

}

void Render::DeInit(Texture &tilemap){
	UnloadTexture(tilemap);
	CloseWindow();
}


void Render::DrawMap(Texture &tilemap, std::vector<int> &tiledata, int ox, int oy, int w, int h, int sx, int sy){
	#define MAP_SIZE 1000
	#define MAP_AREA 1000000

	for(int y = 0; y < w; y++){
		for(int x = 0; x < h; x++){
			int translated_pointer_x = ox + x;
			int translated_pointer_y = oy + y;

			int index = translated_pointer_x + (translated_pointer_y * MAP_SIZE);
			if(index > MAP_AREA || index < 0) continue;
			
			int tile_id = tiledata[index] - 1;
			Render::DrawSprite(tilemap, tile_id, sx + x, sy + y);	
		}
	}
}

void Render::DrawSprite(Texture &tilemap, int sprite_id, int x, int y){
	
	int tilesize = 8;
	int sy = sprite_id/16;
	int sx = sprite_id - (y * 16);
	
	Rectangle src = (Rectangle){(float)sx * tilesize, (float)sy * tilesize, (float)tilesize, (float)tilesize};	
	Rectangle dest = (Rectangle){(float)x * SCREEN_TILE_SIZE, (float)y * SCREEN_TILE_SIZE, SCREEN_TILE_SIZE, SCREEN_TILE_SIZE};

	DrawTexturePro(tilemap, src, dest, (Vector2){0,0}, 0, WHITE);
}


void Render::DrawFont(Font &font, int x, int y, const char* msg){
	DrawTextEx(font, msg, (Vector2){(float)x * 20, (float)y * 20}, 18, 2, WHITE);
}

