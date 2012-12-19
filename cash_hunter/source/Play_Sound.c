/*
 * Play_Sound.c
 *
 *  Created on: 2011. 12. 19.
 *      Author: Administrator
 */

#include "init.h"
#include "Play_Sound.h"
#include "Draw_Image.h"



void key_init(void) {
	int i;
	u8 key;

	for (i = 0; i < MAX_KEY_LOG; i++)
		xQueueReceive(KeyQueue, &key, 0);
}

int kbhit(void) {
	u8 key;
	int ret = xQueuePeek(KeyQueue, &key, 0);
	return (ret == pdPASS);
}
char *getKeyName(u8 key)
{
	switch(key){
	case SFX_DO:	return "Do";	break;
	case SFX_DO_S:	return "Do#";	break;
	case SFX_RE:	return "Re";	break;
	case SFX_RE_S:	return "Re#";	break;
	case SFX_MI:	return "Mi";	break;
	case SFX_FA:	return "Fa";	break;
	case SFX_FA_S:	return "Fa#";	break;
	case SFX_SOL:	return "Sol";	break;
	case SFX_SOL_S:	return "Sol#";	break;
	case SFX_LA:	return "La";	break;
	case SFX_LA_S:	return "La#";	break;
	case SFX_SI:	return "Si";	break;
	case SFX_HDO:	return "Do_h";	break;

	case code_C:	return "code_C";	break;
	case code_D:	return "code_D";	break;
	case code_Dm:	return "code_Dm";	break;
	case code_E:	return "code_E";	break;
	case code_Em:	return "code_Em";	break;
	case code_F:	return "code_F";	break;
	case code_Fm:	return "code_Fm";	break;
	case code_G:	return "code_G";	break;
	case code_G7:	return "code_G7";	break;
	case code_G7s:	return "code_G7#";	break;
	case code_A:	return "code_A";	break;
	case code_Am:	return "code_Am";	break;
	case code_A7:	return "code_A7";	break;
	case code_A7s:	return "code_A7#";	break;
	case code_B:	return "code_B";	break;
	case code_B7:	return "code_B7";	break;
	case code_B7p:	return "code_B7b";	break;
	default:	break;
	}
	return "";
}

u8 getkey(void) {
	u8 key;
	xQueueReceive(KeyQueue, &key, portMAX_DELAY);
	return key;
}

portTickType short_timer;
static void f_TimeSet(void *p) {
	short_timer = xTaskGetTickCount();
}

void Run_Sound() {
	u8 key = 99;

	mmInitDefaultMem((mm_addr) soundbank_bin);
	int i, index = 0;

	for (i = MSL_BANKSIZE; i > 0; i--)
		mmLoadEffect(i);
	char *string;
	
	videoSetMode(MODE_0_2D);
	vramSetBankA(VRAM_A_MAIN_BG);
	consoleInit(&TopScreen, 3, BgType_Text4bpp, BgSize_T_256x256, 31, 0, TRUE, TRUE);
	consoleSelect(&TopScreen);
	while (1) {

		if((xTaskGetTickCount() - short_timer) > MSEC2TICK(1000)){
			iprintf("\n [%3d] ", index++);
			f_TimeSet(NULL);
		}
		if(kbhit()){
			key = getkey();

		if(key != 99){
			string = getKeyName(key);
			iprintf("%s ", string);
		}

		switch (key) {
		case SFX_DO:		mmEffectEx(&Do);	break;
		case SFX_DO_S:		mmEffectEx(&Do_s);	break;
		case SFX_RE:		mmEffectEx(&Re);	break;
		case SFX_RE_S:		mmEffectEx(&Re_s);	break;
		case SFX_MI:		mmEffectEx(&Mi);	break;
		case SFX_FA:		mmEffectEx(&Fa);	break;
		case SFX_FA_S:		mmEffectEx(&Fa_s);	break;
		case SFX_SOL:		mmEffectEx(&Sol);	break;
		case SFX_SOL_S:		mmEffectEx(&Sol_s);	break;
		case SFX_LA:		mmEffectEx(&La);	break;
		case SFX_LA_S:		mmEffectEx(&La_s);	break;
		case SFX_SI:		mmEffectEx(&Si);	break;
		case SFX_HDO:		mmEffectEx(&Hdo);	break;

		case code_C:	mmEffectEx(&Do);	mmEffectEx(&Mi);	mmEffectEx(&Sol);	break;//C
		case code_D:	mmEffectEx(&Re);	mmEffectEx(&Fa_s);	mmEffectEx(&La);	break;//D
		case code_Dm:	mmEffectEx(&Re);	mmEffectEx(&Fa);	mmEffectEx(&La);	break;//Dm
		case code_E:	mmEffectEx(&Mi);	mmEffectEx(&Sol_s);	mmEffectEx(&Si);	break;//E
		case code_Em:	mmEffectEx(&Mi);	mmEffectEx(&Sol);	mmEffectEx(&Si);	break;//Em
		case code_F:	mmEffectEx(&Fa);	mmEffectEx(&La);	mmEffectEx(&Do);	break;//F
		case code_Fm:	mmEffectEx(&Fa);	mmEffectEx(&Sol_s);	mmEffectEx(&Do);	break;//Fm
		case code_G:	mmEffectEx(&Sol);	mmEffectEx(&Si);	mmEffectEx(&Re);	break;//G
		case code_G7:	mmEffectEx(&Sol);	mmEffectEx(&Si);	mmEffectEx(&Re);	mmEffectEx(&Fa);	break;//G7
		case code_G7s:	mmEffectEx(&Sol);	mmEffectEx(&Si);	mmEffectEx(&Re);	mmEffectEx(&Fa_s);	break;//G7#

		case code_A:	mmEffectEx(&La);	mmEffectEx(&Do);	mmEffectEx(&Mi);	break;//A
		case code_Am:	mmEffectEx(&La);	mmEffectEx(&Do_s);	mmEffectEx(&Mi);	break;//Am
		case code_A7:	mmEffectEx(&La);	mmEffectEx(&Do);	mmEffectEx(&Mi);	mmEffectEx(&Sol);	break;//A7
		case code_A7s:	mmEffectEx(&La);	mmEffectEx(&Do_s);	mmEffectEx(&Mi);	mmEffectEx(&Sol);	break;//A7#
		case code_B:	mmEffectEx(&Si);	mmEffectEx(&Re_s);	mmEffectEx(&Fa_s);	break;//B
		case code_B7:	mmEffectEx(&Si);	mmEffectEx(&Re_s);	mmEffectEx(&Fa_s);	mmEffectEx(&La);	break;//B7
		case code_B7p:	mmEffectEx(&Si);	mmEffectEx(&Re);	mmEffectEx(&Fa);	mmEffectEx(&Sol_s);	break;//B7^
		}
		}
	}
}

void Key_Sound() { //          press_key
	u16 sw;
	u8 key;
	u8 old_key = 99;

	// Variables
//사운드뱅크 초기화
	mmInitDefaultMem((mm_addr) soundbank_bin);
//0~있는거 죄다 사운드 로드해오기
	int i;
	for (i = MSL_BANKSIZE; i > 0; i--)
		mmLoadEffect(i-1);

	while (1) {
		// Fill Here
		key = 99;
		sw = NDS_SWITCH();



		if ((sw & KEY_UP)) { //C
			key = code_C;
		}

		if ((sw & KEY_LEFT) && (sw & KEY_L)) { //Dm
			key = code_Dm;
		} else if (sw & KEY_LEFT) { //D
			key = code_D;
		}

		if ((sw & KEY_DOWN) && (sw & KEY_L)) { //Em
			key = code_Em;
		} else if (sw & KEY_DOWN) { //E
			key = code_E;
		}
		//		(sw & KEY_L)		(sw & KEY_R)		(sw & KEY_RIGHT) {//7
		if ((sw & KEY_Y) && (sw & KEY_L)) { //Fm
			key = code_Fm;
		} else if (sw & KEY_Y) { //F
			key = code_F;
		}
		if ((sw & KEY_X) && (sw & KEY_RIGHT) && (sw & KEY_R)) { //G7#
			key = code_G7s;
		} else if ((sw & KEY_X) && (sw & KEY_RIGHT)) { //G7
			key = code_G7;
		} else if (sw & KEY_X) { //G
			key = code_G;
		}

		if ((sw & KEY_A) && (sw & KEY_RIGHT) && (sw & KEY_R)) { //A7#
			key = code_A7s;
		} else if ((sw & KEY_A) && (sw & KEY_RIGHT)) { //G7
			key = code_A7;
		} else if ((sw & KEY_A) && (sw & KEY_L)) { //Am
			key = code_Am;
		} else if (sw & KEY_A) { //A
			key = code_A;
		}
		if ((sw & KEY_B) && (sw & KEY_RIGHT) && (sw & KEY_L)) { //B7^
			key = code_B7p;
		} else if ((sw & KEY_B) && (sw & KEY_RIGHT)) { //G7
			key = code_B7;
		} else if (sw & KEY_B) { //B
			key = code_B;
		}
		if (key != old_key) {
			xQueueSend(KeyQueue, &key, 0);
			old_key = key;
		}


		vTaskDelay(MSEC2TICK(20));
	}
}
void Touch_Sound() {

	mmInitDefaultMem((mm_addr) soundbank_bin);

	touchPosition touch;

	consoleSelect(&bottomScreen);
	u8 key, old_key = 99;
	//u8 button = 0;
	while (1) {
		touchRead(&touch);
		key = 99;

		if (((touch.px >= 0) && (touch.px < 32))
				&& ((touch.py <= 190) && (touch.py > 158))) {
			key = SFX_DO;
		} // ��
		if (((touch.px >= 32) && (touch.px < 64))
				&& ((touch.py <= 190) && (touch.py > 158))) {
			key = SFX_RE;
		} // ��
		if (((touch.px >= 64) && (touch.px < 96))
				&& ((touch.py <= 190) && (touch.py > 158))) {
			key = SFX_MI;
		} // ��
		if (((touch.px >= 96) && (touch.px < 128))
				&& ((touch.py <= 190) && (touch.py > 158))) {
			key = SFX_FA;
		} // ��
		if (((touch.px >= 128) && (touch.px < 160))
				&& ((touch.py <= 190) && (touch.py > 158))) {
			key = SFX_SOL;
		} // ��
		if (((touch.px >= 160) && (touch.px < 192))
				&& ((touch.py <= 190) && (touch.py > 158))) {
			key = SFX_LA;
		} // ��
		if (((touch.px >= 192) && (touch.px < 224))
				&& ((touch.py <= 190) && (touch.py > 158))) {
			key = SFX_SI;
		} // ��
		if (((touch.px >= 224) && (touch.px < 256))
				&& ((touch.py <= 190) && (touch.py > 158))) {
			key = SFX_HDO;
		} // ��
		if (((touch.px >= 20) && (touch.px < 46))
				&& ((touch.py <= 158) && (touch.py >= 75))) {
			key = SFX_DO_S;
		} // �� ��
		if (((touch.px >= 51) && (touch.px < 76))
				&& ((touch.py <= 158) && (touch.py >= 75))) {
			key = SFX_RE_S;
		} // �� ��
		if (((touch.px >= 116) && (touch.px < 141))
				&& ((touch.py <= 158) && (touch.py >= 75))) {
			key = SFX_FA_S;
		} // �� ��
		if (((touch.px >= 147) && (touch.px < 172))
				&& ((touch.py <= 158) && (touch.py >= 75))) {
			key = SFX_SOL_S;
		} // �ּ�
		if (((touch.px >= 178) && (touch.px < 203))
				&& ((touch.py <= 158) && (touch.py >= 75))) {
			key = SFX_LA_S;
		} // �� ��
		if((key != old_key)){
			xQueueSend(KeyQueue, &key, 0);
		}
		old_key = key;
	}
}

