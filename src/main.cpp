/*
 * main.cpp
 *
 *  Created on: 2010. 11. 20.
 *      Author: ������, �ڰ�ȣ, �ŵ���
 */


// PAGfxConverter Include

#include "includefile.h"


// Main function
int main(void)	{

	//���� ����
	AS_Init(AS_MODE_SURROUND | AS_MODE_16CH);
	AS_SetDefaultSettings(AS_PCM_8BIT, 11025, AS_SURROUND);


	while(1){
		Screen scr;

		scr.Ready_Screen();		// ��ŸƮ�� ���������� ������.

		AS_SoundQuickPlay(yeah); // ������� ����

		while(1){
			scr.SCreen_Change();

			Stage Game;		// game ��ü ����.

			while(1){
				Game.Location_Update();		// ��� ��ü�� ��ǥ���� ���°� ����.
				Game.Image_Update();		// ��� ��ü �̹��� �ѷ���.

				if(Pad.Newpress.Start && Game.isGameOver == 1) break;	// ���ӵ��� ���������.

				PA_WaitForVBL();
			}
			if(Game.isGameOver == 1){		// ��������� �ʱ���·� ���ư�.
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
