/*
 * Character.cpp
 *
 *  Created on: 2010. 11. 20.
 *      Author: ������, �ڰ�ȣ, �ŵ���
 */

#include "Character.h"
#include "includefile.h"

#define DOWN_SCREEN 0
#define UP_SCREEN 1
#define CHARACTER_NUM 0

Character::Character() {
	x = 120;		// �ʱ� �ɸ��� ��ġ ��.
	y = 160;
	isShild = 0;

	//PA_LoadSpritePal(��ũ����ȣ, �ķ�Ʈ ��ȣ, �ķ�Ʈ)
	PA_LoadSpritePal(DOWN_SCREEN, CHARACTER_NUM, (void*)sprite0_Pal);	// �ɸ���....
	//PA_CreateSprite(������ ��ġ ��ũ�� ��ȣ, �Ҵ��ų ��������Ʈ ��ȣ, ��������Ʈ �׸� ����, ũ��, 256���̸� 1, �ȷ���ȣ, x��ǥ,y��ǥ)
	PA_CreateSprite(DOWN_SCREEN, CHARACTER_NUM,(void*)som_Sprite, OBJ_SIZE_16X32,1, CHARACTER_NUM, x, y); // �ɸ��� ����
}

Character::~Character() {
}

void Character::move() {
	////////////////////////// �ɸ��� ������ //////////////////////////
	//PA_StartSpriteAnim(��ũ�� ��ȣ, ��������Ʈ ��ȣ, ó�� ������, ������ ������,  �ӵ�)
		if(Pad.Newpress.Up) PA_StartSpriteAnim(0, 0, 0, 3, 4);
		if(Pad.Newpress.Down) PA_StartSpriteAnim(0, 0, 8, 11, 4);

		if(Pad.Newpress.Right) {
			PA_StartSpriteAnim(0, 0, 4, 7, 4);
			PA_SetSpriteHflip(0, 0, 0);
		}
		if(Pad.Newpress.Left) {
			PA_StartSpriteAnim(0, 0, 4, 7, 4);
			PA_SetSpriteHflip(0, 0, 1);
		}
		if(!((Pad.Held.Left)||(Pad.Held.Up)||(Pad.Held.Down)||(Pad.Held.Right)))
			PA_SpriteAnimPause(0, 0, 1);

		if (Pad.Held.Up){}  // screen, sprite, frame
		if (Pad.Held.Down){}  // screen, sprite, frame
		if (Pad.Held.Left && x > 5){
			x-=2;
		}
		if (Pad.Held.Right && x < 236){
			x+=2;
		}
	//
}
