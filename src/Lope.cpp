/*
 * Lope.cpp
 *
 *  Created on: 2010. 11. 20.
 *      Author: ������, �ڰ�ȣ, �ŵ���
 */

#include "Lope.h"
#include "includefile.h"

#define DOWN_SCREEN 0
#define UP_SCREEN 1


#define LOPE_NUM 1

Lope::Lope() {
	x= -200;
	y= -200;
	isShot = 0;
	isSelected = 1;
	//PA_LoadSpritePal(��ũ����ȣ, �ķ�Ʈ ��ȣ, �ķ�Ʈ)
	PA_LoadSpritePal(DOWN_SCREEN, LOPE_NUM, (void*)suri_Pal);	// ����...

	//PA_CreateSprite(������ ��ġ ��ũ�� ��ȣ, �Ҵ��ų ��������Ʈ ��ȣ, ��������Ʈ �׸� ����, ũ��, 256���̸� 1, �ȷ���ȣ, x��ǥ,y��ǥ)
	PA_CreateSprite(DOWN_SCREEN, LOPE_NUM,(void*)suri_Sprite, OBJ_SIZE_8X8,1, LOPE_NUM, x, y); // ���� ����
}

Lope::~Lope() {}

void Lope::change(){

}

void Lope::move(int ch_x, int ch_y){

	if(Pad.Newpress.A && isShot == 0){
		AS_SoundQuickPlay(gunshot);//�� �߻�� ����

		isShot = 1;
		x = ch_x;
		y = ch_y;
	}

	if(isShot == 1){
		if(y <= 0){
			isShot = 0;
			x = -200, y = -200;
		}
		y = y - 5;
	}
}
