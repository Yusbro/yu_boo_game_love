#include <raylib.h>
#include <vector>

namespace Render{
	void init(int width, int height, Texture &tilemap);
	void DeInit(Texture &tilemap);

	void DrawMap(Texture &tilemap, std::vector<int> &tiledata ,int ox, int oy, int w, int h, int sx, int sy);
	void DrawSprite(Texture &tilemap, int sprite_id, int x, int y);
	void DrawFont(Font &font, int x, int y, const char* msg);
}


