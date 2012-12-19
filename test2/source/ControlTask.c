#include "init.h"
#include "drunkenlogo.h"
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

void setPlayData() {
	//getKey();

	//1. 현재 받아드려진 키값으로 변경되야할 좌표생성한다.
	//2. 현재 캐릭터 상태에 따라서 변경된 좌표가 적용될시 변경되는 캐릭터상태도 채워준다.
	//생성된 내용들을 PlayData전역변 값을 채워서 최신화시켜준다.
}

void Control() {
	consoleDemoInit();

	//display background
	videoSetMode(MODE_5_2D);
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

	consoleDemoInit();

	int bg3 = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0, 0);

	dmaCopy(drunkenlogoBitmap, bgGetGfxPtr(bg3), 256 * 256);
	dmaCopy(drunkenlogoPal, BG_PALETTE, 256 * 2);

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

	do {

		int keys_pressed, keys_released;

		swiWaitForVBlank();
		scanKeys();
		keys_pressed = keysDown();
		keys_released = keysUp();
/*
		if ((keys_pressed & KEY_MOVE)) {
			amb = mmEffectEx(&ambulance);
		}
	*/
		switch(keys_pressed){
		case KEY_UP:
			break;
		case KEY_DOWN:
					break;
		case KEY_LEFT:
					break;
		case KEY_RIGHT:
					break;
		}


		// stop ambulance sound when move button is released
		if ((keys_released & KEY_MOVE)) {
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
