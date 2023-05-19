#include <raylib.h>
#include <iostream>

int main(){
	InitWindow(800, 640, "Tile_To_Index");
	
	Texture image = LoadTexture("asset/tilemap.png");
	while(!WindowShouldClose()){
		BeginDrawing();
			ClearBackground(BLACK);

			DrawTextureEx(image, (Vector2){0,0}, 0, 5, WHITE);
			
			//the whole mouse stuff!!!
			Vector2 mospos = GetMousePosition();
			int x = (mospos.x / (5*8));
			int y = (mospos.y / (5*8));
			

			int index = x + (y*16);
			DrawText(TextFormat("%i", index), 700, 200, 30, RED);
			DrawRectangleLines(x*(5*8), y*(5*8), (5*8), (5*8), RED);

			std::cout<<x<<"	"<<y<<std::endl;

		EndDrawing();
	}
	UnloadTexture(image);
	CloseWindow();
	return 0;
}
