/*
 * main.cpp
 *
 *  Created on: 2010. 11. 20.
 *      Author: 최진영, 박경호, 신동우
 */


// PAGfxConverter Include

#include "includefile.h"


// Main function
int main(void)	{

	//사운드 관련
	AS_Init(AS_MODE_SURROUND | AS_MODE_16CH);
	AS_SetDefaultSettings(AS_PCM_8BIT, 11025, AS_SURROUND);


	while(1){
		Screen scr;

		scr.Ready_Screen();		// 스타트를 누를때까지 대기상태.

		AS_SoundQuickPlay(yeah); // 배경음악 사운드

		while(1){
			scr.SCreen_Change();

			Stage Game;		// game 객체 생성.

			while(1){
				Game.Location_Update();		// 모든 객체의 좌표값과 상태값 변경.
				Game.Image_Update();		// 모든 객체 이미지 뿌려줌.

				if(Pad.Newpress.Start && Game.isGameOver == 1) break;	// 게임도중 사망했을시.

				PA_WaitForVBL();
			}
			if(Game.isGameOver == 1){		// 사망했을시 초기상태로 돌아감.
				break;
			}
			Game.~Stage();
			PA_WaitForVBL();
		}
		scr.~Screen();
		PA_WaitForVBL();
	}
	return 0;
}
