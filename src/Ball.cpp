/*
 * Ball.cpp
 *
 *  Created on: 2010. 11. 20.
 *      Author: ������, �ڰ�ȣ, �ŵ���
 */

#include "Ball.h"
#include "includefile.h"

#define DOWN_SCREEN 0
#define UP_SCREEN 1
#define BALL_NUM 2

#define SCREENHOLE 48
#define BALL_RADIUS 16

#define SIZE_L4		64
#define SIZE_L3		32
#define SIZE_L2		16
#define SIZE_L1		8

Ball::Ball() {
	move_flag = 0;
	size = SIZE_L4;
	/*PA_LoadSpritePal(DOWN_SCREEN, BALL_NUM, (void*)sprite1_Pal);	// ��...
	//PA_LoadSpritePal(DOWN_SCREEN, pimg, (void*)sprite1_Pal);	// ��...
	//PA_CreateSprite(������ ��ġ ��ũ�� ��ȣ, �Ҵ��ų ��������Ʈ ��ȣ, ��������Ʈ �׸� ����, ũ��, 256���̸� 1, �ȷ���ȣ, x��ǥ,y��ǥ)
	//PA_CreateSprite(DOWN_SCREEN, BALL_NUM,(void*)circle16x16_Sprite, OBJ_SIZE_16X16,1, 0, x, y); // �� ����
	PA_CreateSprite(DOWN_SCREEN, BALL_NUM,(void*)circle_Sprite, OBJ_SIZE_32X32,1, 0, x, y); // �� ����
	*/
	puck.ball_x = 128; puck.ball_y = 96+192+SCREENHOLE; // central position on bottom screen
	puck.vx = 1; puck.vy = 2; // No speed
}

Ball::~Ball() {
}


void Ball::move(){
	if(move_flag){
	//if(size == 32){
		puck.ball_x += puck.vx;	//puck.x , puck.y �� �����̴� ���� x,y��ǥ.
		puck.ball_y += puck.vy;	//puck.vx, puck.vy �� �ӵ��� ���� ���� �̵� ��ǥ.
//		���� ��ġ�� �߽��� �������� �ϰ� 0,0��  �� ȭ���� 0,0��.
//		����  �������� 16�̴�.

	// If the sprite touches the left or right border, flip the horizontal speed

		if ((puck.ball_x - BALL_RADIUS <= 0) && (puck.vx < 0)) puck.vx = -puck.vx;			//X��ǥ ���ʺ� ��
		else if ((puck.ball_x + size - BALL_RADIUS >= 256)&&(puck.vx > 0)) puck.vx = -puck.vx;	//X��ǥ ������ �� ��

	// Same thing, for top and bottom limits...
		if ((puck.ball_y - BALL_RADIUS <= 240) && (puck.vy < 0)) puck.vy = -puck.vy;	//Y��ǥ�� �� ��ũ���� ������
		else if ((puck.ball_y + size - BALL_RADIUS >= 192 + 192 + SCREENHOLE)&& (puck.vy > 0)) puck.vy = -puck.vy;//Y��ǥ �ǹؽ�ũ�� �ٴڱ���

	// The bottom limit is at the bottom of the bottom screen, so that would be 2 screen heights, plus the space in between...
	//	PA_OutputText(UP_SCREEN, 0, 6, "b1 x : %d ", puck.ball_x);
	//	PA_OutputText(UP_SCREEN, 0, 7, "b1 y : %d ", puck.ball_y);
/*	}else{
		puck.ball_x += puck.vx;	//puck.x , puck.y �� �����̴� ���� x,y��ǥ.
		puck.ball_y += puck.vy;	//puck.vx, puck.vy �� �ӵ��� ���� ���� �̵� ��ǥ.
		//		���� ��ġ�� �߽��� �������� �ϰ� 0,0��  �� ȭ���� 0,0��.
		//		����  �������� 16�̴�.

			// If the sprite touches the left or right border, flip the horizontal speed
		if ((puck.ball_x - BALL_RADIUS <= 0) && (puck.vx < 0)) puck.vx = -puck.vx;			//X��ǥ ���ʺ� ��
		else if ((puck.ball_x + BALL_RADIUS >= 256)&&(puck.vx > 0)) puck.vx = - puck.vx;	//X��ǥ ������ �� ��

			// Same thing, for top and bottom limits...
		if ((puck.ball_y - BALL_RADIUS <= 240) && (puck.vy < 0)) puck.vy = -puck.vy;	//Y��ǥ�� �� ��ũ���� ������
		else if ((puck.ball_y + BALL_RADIUS >= 192 + 192 + SCREENHOLE)&& (puck.vy > 0)) puck.vy = - puck.vy;//Y��ǥ �ǹؽ�ũ�� �ٴڱ���
		PA_OutputText(UP_SCREEN, 0, 8, "b2 x : %d ", puck.ball_x);
		PA_OutputText(UP_SCREEN, 0, 9, "b2 y : %d ", puck.ball_y);
	}*/
	}
}
void Ball::setimg(int pimg){
	x = 16;
	y = 16;

	//PA_LoadSpritePal(��ũ����ȣ, �ķ�Ʈ ��ȣ, �ķ�Ʈ)

		//	PA_LoadSpritePal(DOWN_SCREEN, pimg, (void*)sprite1_Pal);	// ��...
			//PA_CreateSprite(������ ��ġ ��ũ�� ��ȣ, �Ҵ��ų ��������Ʈ ��ȣ, ��������Ʈ �׸� ����, ũ��, 256���̸� 1, �ȷ���ȣ, x��ǥ,y��ǥ)
			//PA_CreateSprite(DOWN_SCREEN, BALL_NUM,(void*)circle16x16_Sprite, OBJ_SIZE_16X16,1, 0, x, y); // �� ����
	if(size == SIZE_L4){
		PA_LoadSpritePal(DOWN_SCREEN, BALL_NUM+pimg, (void*)circle64x64_Pal);	// ��...
		PA_CreateSprite( DOWN_SCREEN, BALL_NUM+pimg, (void*)circle64x64_Sprite, OBJ_SIZE_64X64,1, BALL_NUM+pimg, x, y); // �� ����
	}
	else if(size == SIZE_L3){
		PA_LoadSpritePal(DOWN_SCREEN, BALL_NUM+pimg, (void*)sprite1_Pal);	// ��...
		PA_CreateSprite( DOWN_SCREEN, BALL_NUM+pimg, (void*)circle_Sprite, OBJ_SIZE_32X32,1, BALL_NUM+pimg, x, y); // �� ����
	}else if(size == SIZE_L2){
		PA_LoadSpritePal(DOWN_SCREEN, BALL_NUM+pimg, (void*)circle16x16_Pal);	// ��...
		PA_CreateSprite( DOWN_SCREEN, BALL_NUM+pimg, (void*)circle16x16_Sprite, OBJ_SIZE_16X16,1, BALL_NUM+pimg, x, y); // �� ����
	}else if(size == SIZE_L1){
		PA_LoadSpritePal(DOWN_SCREEN, BALL_NUM+pimg, (void*)circle8x8_Pal);	// ��...
		PA_CreateSprite( DOWN_SCREEN, BALL_NUM+pimg, (void*)circle8x8_Sprite, OBJ_SIZE_8X8,1, BALL_NUM+pimg, x, y); // �� ����
	}
}
void Ball::setlocate(int x, int y, int dx, int dy){
	this->puck.ball_x = x;
	this->puck.ball_y = y;
	this->puck.vx = dx;
	this->puck.vy = dy;
}
void Ball::setsize(int ball_size){
	this->size = ball_size;
	if(puck.vx > 0)
		puck.vx++;
	else
		puck.vx--;
	if(puck.vy > 0)
		puck.vy++;
	else
		puck.vy--;
}
