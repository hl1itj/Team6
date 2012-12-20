#include "init.h"

mm_sound_effect ambulance = { { SFX_AMBULANCE },			// id
		(int) (1.0f * (1 << 10)),	// rate
		0,		// handle
		255,	// volume
		0,		// panning
		};

mm_sound_effect boom = { { SFX_BOOM },			// id
		(int) (1.0f * (1 << 10)),	// rate
		0,		// handle
		255,	// volume
		255,	// panning
		};
//--

#define FRAMES_PER_ANIMATION 3

//---------------------------------------------------------------------
// The womman sprite
// she needs an array of pointers to sprite memory since all
// her frames are to be loaded.
// she also needs to keep track of which sprite memory pointer is in use
//---------------------------------------------------------------------
typedef struct {
	int x;
	int y;

	u16* sprite_gfx_mem[12];
	int gfx_frame;

	int state;
	int anim_frame;

} Woman;

//---------------------------------------------------------------------
// The state of the sprite (which way it is walking)
//---------------------------------------------------------------------
enum SpriteState {
	W_UP = 0, W_RIGHT = 1, W_DOWN = 2, W_LEFT = 3
};

//---------------------------------------------------------------------
// Screen dimentions
//---------------------------------------------------------------------
enum {
	SCREEN_TOP = 0, SCREEN_BOTTOM = 160, SCREEN_LEFT = 0, SCREEN_RIGHT = 224
};

//---------------------------------------------------------------------
// Animating a woman onlwomanTilesy requires us to alter which sprite memory pointer
// she is using
//---------------------------------------------------------------------
void animateWoman(Woman *sprite) {
	sprite->gfx_frame = sprite->anim_frame
			+ sprite->state * FRAMES_PER_ANIMATION;
}

//---------------------------------------------------------------------
// Initializing a woman requires us to load all of her graphics frames
// into memory
//---------------------------------------------------------------------
void initWoman(Woman *sprite, u8* gfx) {
	int i;

	for (i = 0; i < 12; i++) {
		sprite->sprite_gfx_mem[i] = oamAllocateGfx(&oamSub, SpriteSize_32x32,
				SpriteColorFormat_256Color);
		dmaCopy(gfx, sprite->sprite_gfx_mem[i], 32 * 32);
		gfx += 32 * 32;
	}
}

//-*-

void Control() {

	consoleDemoInit();

	//display background
	videoSetMode(MODE_5_2D);
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);
	//bgInit(3,BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	//decompress(drunkenlogoBitmap, BG_GFX, LZ77Vram);
	//consoleDemoInit();
	int bg3 = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0, 0);
	dmaCopy(drunkenlogoBitmap, bgGetGfxPtr(bg3), 256 * 256);
	dmaCopy(drunkenlogoPal, BG_PALETTE, 256 * 2);

	 consoleDemoInit();

	 //set up the sub display
	 videoSetModeSub(MODE_5_2D);
	 vramSetBankC(VRAM_C_SUB_BG);
	 //bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	 //decompress(piano_imageBitmap, BG_GFX_SUB, LZ77Vram);

	 bgInitSub(3, BgType_Bmp8 , BgSize_R_128x128, 0,0);
	 /*
	 decompress(piano_imageBitmap, BG_GFX_SUB,  LZ77Vram);
	 */

	//-----------------------------------------------------------------
	// Initialize the graphics engines
	//-----------------------------------------------------------------
	//videoSetMode(MODE_0_2D);
	//videoSetModeSub(MODE_0_2D);
	//vramSetBankA(VRAM_A_MAIN_SPRITE);
	vramSetBankD(VRAM_D_SUB_SPRITE);

	//oamInit(&oamMain, SpriteMapping_1D_128, false);
	oamInit(&oamSub, SpriteMapping_1D_128, false);

	//Load Sound data
	mmInitDefaultMem((mm_addr) soundbank_bin);

	// load the module
	mmLoad(MOD_FLATOUTLIES);

	// load sound effects
	mmLoadEffect(SFX_AMBULANCE);
	mmLoadEffect(SFX_BOOM);

	// Start playing module
	mmStart(MOD_FLATOUTLIES, MM_PLAY_LOOP);

	mm_sfxhand amb = 0;

	Woman woman = { 0, 0 };

	vramSetBankC(VRAM_C_SUB_BG);
	bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	decompress(piano_imageBitmap, BG_GFX_SUB, LZ77Vram);

	//-----------------------------------------------------------------
	// Initialize the two sprites
	//-----------------------------------------------------------------
	initWoman(&woman, (u8*) womanTiles);

	dmaCopy(womanPal, SPRITE_PALETTE_SUB, 512);

	do {

		int keys_pressed, keys_released;

		swiWaitForVBlank();
		scanKeys();
		keys_pressed = keysDown();
		keys_released = keysUp();

		int keys = keysHeld();

		if (keys & KEY_START)
			break;

		if (keys) {

			switch (keys) {

			case KEY_UP:
				if (woman.y >= SCREEN_TOP)
					woman.y--;
				woman.state = W_UP;
				break;
			case KEY_DOWN:
				if (woman.y <= SCREEN_BOTTOM)
					woman.y++;
				woman.state = W_DOWN;
				break;
			case KEY_LEFT:
				if (woman.x >= SCREEN_LEFT)
					woman.x--;
				woman.state = W_LEFT;
				break;
			case KEY_RIGHT:
				if (woman.x <= SCREEN_RIGHT)
					woman.x++;
				woman.state = W_RIGHT;
				break;
			}
			keys_pressed = 0;

			woman.anim_frame++;
			if (woman.anim_frame >= FRAMES_PER_ANIMATION)
				woman.anim_frame = 0;
		}

		animateWoman(&woman);

		//-----------------------------------------------------------------
		// Set oam attributes, notice the only difference is in the sprite
		// graphics memory pointer argument.  The man only has one pointer
		// while the women has an array of pointers
		//-----------------------------------------------------------------

		oamSet(&oamSub, 0, woman.x, woman.y, 0, 0, SpriteSize_32x32,
				SpriteColorFormat_256Color,
				woman.sprite_gfx_mem[woman.gfx_frame], -1, false, false, false,
				false, false);

		swiWaitForVBlank();

		oamUpdate(&oamMain);
		oamUpdate(&oamSub);

		if (keys_pressed & KEY_A) {
			amb = mmEffectEx(&ambulance);
		}
		// stop ambulance sound when move button is released
		if ((keys_released & KEY_A)) {
			mmEffectCancel(amb);
		}

		//Play explosion sound effect out of right speaker if B button is pressed
		if (keys_pressed & KEY_B) {
			mmEffectEx(&boom);
		}
		if (keys_pressed & KEY_START)
			break;

	} while (1);

}
