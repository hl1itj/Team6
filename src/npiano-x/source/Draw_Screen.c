#include "init.h"
#include "Draw_Image.h"

// 스크린 하단 의 배경
void Draw_down() {
	videoSetModeSub(MODE_5_2D);
	vramSetBankC(VRAM_C_SUB_BG);
	bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	decompress(piano_imageBitmap, BG_GFX_SUB, LZ77Vram);
}
// 스크린 상단
void Draw_Up_Init() {

	videoSetMode(MODE_0_2D);
	vramSetBankA(VRAM_A_MAIN_BG);



}
// 누른 위치 표시
void draw_my_touch(int pos_x, int pos_y, u16 color) {
	// draw big white box
	int i, j;
	u32 *basePoint, pixel;

	pixel = (color << 16) + color;
	for (i = 0; i < WALL_HEIGHT; i++) {
		basePoint = (u32 *) BG_GFX
				+ ((((pos_y * WALL_HEIGHT) + i) * SCREEN_WIDTH)
						+ pos_x * WALL_WIDTH) / 2;
		for (j = 0; j < (WALL_WIDTH / 2); j++)
			*basePoint++ = pixel;
	}
}


