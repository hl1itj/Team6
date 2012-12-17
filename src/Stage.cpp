/*
 * Stage.cpp
 *
 *  Created on: 2010. 11. 20.
 *      Author: ������, �ڰ�ȣ, �ŵ���
 */

#include "Items.h"
#include "Stage.h"
#include "includefile.h"

#define DOWN_SCREEN 0
#define UP_SCREEN 1

#define CHARACTER_NUM 0
#define LOPE_NUM 1
#define BALL_NUM 2				// 2������ 9�������� ����.
#define ITEM_NUM 10
#define GAME_OVER 15

#define BALL_RADIUS 16			// ���� ������
#define SCREENHOLE 48			// �� ��ũ���� �Ʒ� ��ũ�� ������ ��

#define SIZE_L4		64
#define SIZE_L3		32
#define SIZE_L2		16
#define SIZE_L1		8
#define POINT 		16

Stage::Stage() {
	ball.setsize(64);
	ball.setlocate(120,220,1,2);
	ball.setimg(0);
	ball.move_flag = 1;

	/*ball2.setsize(32);
	ball2.setlocate(32,32,1,2);
	ball2.setimg(1);
	ball3.setsize(16);
	ball3.setlocate(48,48,1,2);
	ball3.setimg(2);
	ball4.setsize(16);
	ball4.setlocate(POINT*4, POINT*4, 1, 2);
	ball4.setimg(3);
	ball5.setsize(8);
	ball5.setlocate(POINT*5, POINT*5, 1, 2);
	ball5.setimg(4);
	ball6.setsize(8);
	ball6.setlocate(POINT*6, POINT*6, 1, 2);
	ball6.setimg(5);
	ball7.setsize(8);
	ball7.setlocate(POINT*7, POINT*7, 1, 2);
	ball7.setimg(6);
	ball8.setsize(8);
	ball8.setlocate(POINT*8, POINT*8, 1, 2);
	ball8.setimg(7);*/
	isGameOver = 0;		// ���ӳ��� �˸��� �÷���
	isItem = 0;			// �������� �ʿ� �����ִ��� üũ
}

Stage::~Stage() {
}

void Stage::Collision_Character_Item(){
	////////////////////////// �浹  //////////////////////////
	//x,y�� ĳ���� ��ǥ�̰� puck.x, puck.y�� ���� ��ǥ ���� ���� 32*16 ���� ���� ������
	//�浹�������� ���� �ϴ��� Collision�̶�� ���� �����ٰ� ����ִ� �κ��̴�

	if (PA_Distance(character.x, character.y, item.x, item.y - 16) < (item.size*item.size)) {
		AS_SoundQuickPlay(koong);//�浹�� ����
		PA_DeleteSprite(DOWN_SCREEN, ITEM_NUM);
		item.move_flag = 0;
		item.y = -200;

		//isItem = 1;
		//item.SetLocation(lope.x, lope.y);

		//	PA_LoadSpritePal(DOWN_SCREEN, GAME_OVER, (void*)GameOver_Pal);
		//	PA_CreateSprite(DOWN_SCREEN, GAME_OVER,(void*)GameOver_Sprite, OBJ_SIZE_64X64,1, GAME_OVER, 96, 50);
	}
}

void Stage::Collision_Ball_Character(){
	////////////////////////// �浹  //////////////////////////
	//x,y�� ĳ���� ��ǥ�̰� puck.x, puck.y�� ���� ��ǥ ���� ���� 32*16 ���� ���� ������
	//�浹�������� ���� �ϴ��� Collision�̶�� ���� �����ٰ� ����ִ� �κ��̴�
	if (PA_Distance(character.x, character.y, ball.puck.ball_x+ball.size, ball.puck.ball_y-192-SCREENHOLE) < (ball.size*ball.size/6)) {
		PA_LoadSpritePal(DOWN_SCREEN, GAME_OVER, (void*)GameOver_Pal);
		PA_CreateSprite(DOWN_SCREEN, GAME_OVER,(void*)GameOver_Sprite, OBJ_SIZE_64X64,1, GAME_OVER, 96, 50);
		AS_SoundQuickPlay(koong);//�浹�� ����
		while(1){
			if(Pad.Newpress.Start){
				isGameOver = 1;
				break;
			}
			PA_WaitForVBL();
		}
	}
	if (PA_Distance(character.x, character.y, ball2.puck.ball_x+ball2.size, ball2.puck.ball_y-192-SCREENHOLE) < (ball2.size*ball2.size/6)) {
		PA_LoadSpritePal(DOWN_SCREEN, GAME_OVER, (void*)GameOver_Pal);
		PA_CreateSprite(DOWN_SCREEN, GAME_OVER,(void*)GameOver_Sprite, OBJ_SIZE_64X64,1, GAME_OVER, 96, 50);
		AS_SoundQuickPlay(koong);//�浹�� ����
		while(1){
			if(Pad.Newpress.Start){
				isGameOver = 1;
				break;
			}
			PA_WaitForVBL();
		}
	}
	if (PA_Distance(character.x, character.y, ball3.puck.ball_x+ball3.size, ball3.puck.ball_y-192-SCREENHOLE) < (ball3.size*ball3.size/6)) {
		PA_LoadSpritePal(DOWN_SCREEN, GAME_OVER, (void*)GameOver_Pal);
		PA_CreateSprite(DOWN_SCREEN, GAME_OVER,(void*)GameOver_Sprite, OBJ_SIZE_64X64,1, GAME_OVER, 96, 50);
		AS_SoundQuickPlay(koong);//�浹�� ����
		while(1){
			if(Pad.Newpress.Start){
				isGameOver = 1;
				break;
			}
			PA_WaitForVBL();
		}
	}
	if (PA_Distance(character.x, character.y, ball4.puck.ball_x+ball4.size, ball4.puck.ball_y-192-SCREENHOLE) < (ball4.size*ball4.size/6)) {
		PA_LoadSpritePal(DOWN_SCREEN, GAME_OVER, (void*)GameOver_Pal);
		PA_CreateSprite(DOWN_SCREEN, GAME_OVER,(void*)GameOver_Sprite, OBJ_SIZE_64X64,1, GAME_OVER, 96, 50);
		AS_SoundQuickPlay(koong);//�浹�� ����
		while(1){
			if(Pad.Newpress.Start){
				isGameOver = 1;
				break;
			}
			PA_WaitForVBL();
		}
	}
	if (PA_Distance(character.x, character.y, ball5.puck.ball_x+ball5.size+ball5.size, ball5.puck.ball_y-192-SCREENHOLE) < (ball5.size*ball5.size)) {
		PA_LoadSpritePal(DOWN_SCREEN, GAME_OVER, (void*)GameOver_Pal);
		PA_CreateSprite(DOWN_SCREEN, GAME_OVER,(void*)GameOver_Sprite, OBJ_SIZE_64X64,1, GAME_OVER, 96, 50);
		AS_SoundQuickPlay(koong);//�浹�� ����
		while(1){
			if(Pad.Newpress.Start){
				isGameOver = 1;
				break;
			}
			PA_WaitForVBL();
		}
	}
	if (PA_Distance(character.x, character.y, ball6.puck.ball_x+ball6.size+ball6.size, ball6.puck.ball_y-192-SCREENHOLE) < (ball6.size*ball6.size)) {
		PA_LoadSpritePal(DOWN_SCREEN, GAME_OVER, (void*)GameOver_Pal);
		PA_CreateSprite(DOWN_SCREEN, GAME_OVER,(void*)GameOver_Sprite, OBJ_SIZE_64X64,1, GAME_OVER, 96, 50);
		AS_SoundQuickPlay(koong);//�浹�� ����
		while(1){
			if(Pad.Newpress.Start){
				isGameOver = 1;
				break;
			}
			PA_WaitForVBL();
		}
	}
	if (PA_Distance(character.x, character.y, ball7.puck.ball_x+ball7.size+ball7.size, ball7.puck.ball_y-192-SCREENHOLE) < (ball7.size*ball7.size)) {
		PA_LoadSpritePal(DOWN_SCREEN, GAME_OVER, (void*)GameOver_Pal);
		PA_CreateSprite(DOWN_SCREEN, GAME_OVER,(void*)GameOver_Sprite, OBJ_SIZE_64X64,1, GAME_OVER, 96, 50);
		AS_SoundQuickPlay(koong);//�浹�� ����
		while(1){
			if(Pad.Newpress.Start){
				isGameOver = 1;
				break;
			}
			PA_WaitForVBL();
		}
	}
	if (PA_Distance(character.x, character.y, ball8.puck.ball_x+ball8.size+ball8.size, ball8.puck.ball_y-192-SCREENHOLE) < (ball8.size*ball8.size)) {
		PA_LoadSpritePal(DOWN_SCREEN, GAME_OVER, (void*)GameOver_Pal);
		PA_CreateSprite(DOWN_SCREEN, GAME_OVER,(void*)GameOver_Sprite, OBJ_SIZE_64X64,1, GAME_OVER, 96, 50);
		AS_SoundQuickPlay(koong);//�浹�� ����
		while(1){
			if(Pad.Newpress.Start){
				isGameOver = 1;
				break;
			}
			PA_WaitForVBL();
		}
	}

}

void Stage::Collision_Ball_Lope(){
	////////////////////////// �浹  //////////////////////////
	//rope_x,rope_y�� ������ ��ǥ�̰� puck.x, puck.y�� ���� ��ǥ �ؼ� ���� 32*16 ���� ���� ������
	//�浹�������� ���� �ϴ��� Collision�̶�� ���� �����ٰ� ����ִ� �κ��̴�

	if (PA_Distance(lope.x, lope.y, ball.puck.ball_x, ball.puck.ball_y-192-SCREENHOLE) < 64*64) {
		//PA_OutputText(UP_SCREEN, 0, 16, "suri and ball Collision !!");
		//PA_DeleteSprite(0, 1);
		if(ball.size==SIZE_L4){

			//�浹�� ������ ����.
			isItem = 1;
			item.SetLocation(lope.x, lope.y);

			PA_OutputText(UP_SCREEN, 0, 16, "suri and ball Collision !!");
			lope.y = -100;
			ball2.move_flag = 1;
			ball2.setsize(SIZE_L3);
			ball2.setlocate(ball.puck.ball_x,ball.puck.ball_y, -ball.puck.vx,ball.puck.vy);
			ball2.setimg(1);
			ball.setsize(SIZE_L3);
			ball.setlocate(ball.puck.ball_x,ball.puck.ball_y, ball.puck.vx,ball.puck.vy);
			PA_DeleteSprite(0, BALL_NUM);
			ball.setimg(0);
		}
	}

	if(PA_Distance(lope.x, lope.y, ball.puck.ball_x, ball.puck.ball_y-192-SCREENHOLE) < 32*32){

		if(ball.size == SIZE_L3){
			PA_OutputText(UP_SCREEN, 0, 16, "suri and ball1 Collision !!");
			lope.y = -100;
			ball3.move_flag = 1;
			ball3.setsize(SIZE_L2);
			ball3.setlocate(ball.puck.ball_x,ball.puck.ball_y, -ball.puck.vx,ball.puck.vy);
			ball3.setimg(2);
			ball.setsize(SIZE_L2);
			PA_DeleteSprite(0, BALL_NUM);
			ball.setimg(0);
		}
	}

	if(PA_Distance(lope.x, lope.y, ball.puck.ball_x, ball.puck.ball_y-192-SCREENHOLE) < 16*16){

		if(ball.size == SIZE_L2){
			PA_OutputText(UP_SCREEN, 0, 16, "suri and ball1 Collision !!");
			lope.y = -100;
			ball5.move_flag = 1;
			ball5.setsize(SIZE_L1);
			ball5.setlocate(ball.puck.ball_x,ball.puck.ball_y, -ball.puck.vx,ball.puck.vy);
			ball5.setimg(4);
			ball.setsize(SIZE_L1);
			PA_DeleteSprite(0, BALL_NUM);
			ball.setimg(0);
		}
	}

	if(PA_Distance(lope.x, lope.y, ball.puck.ball_x, ball.puck.ball_y-192-SCREENHOLE) < 16*8){
		PA_OutputText(UP_SCREEN, 0, 16, "suri and ball1 Collision !!");
		lope.y = -100;
		//	PA_DeleteSprite(0, BALL_NUM);
		ball.move_flag = 0;
		ball.puck.ball_x=-100;
		ball.puck.ball_y=-100;
		PA_SetSpriteXY(DOWN_SCREEN, BALL_NUM, ball.puck.ball_x - BALL_RADIUS, ball.puck.ball_y);	//��
	}

	if (PA_Distance(lope.x, lope.y, ball2.puck.ball_x, ball2.puck.ball_y-192-SCREENHOLE) < 32*32) {

		//PA_OutputText(UP_SCREEN, 0, 17, "suri and ball2 Collision !!");
		if(ball2.size==SIZE_L3){
			PA_OutputText(UP_SCREEN, 0, 16, "suri and ball2 Collision !!");
			lope.y = -100;
			ball4.move_flag = 1;
			ball4.setsize(SIZE_L2);
			ball4.setlocate(ball2.puck.ball_x,ball2.puck.ball_y, -ball2.puck.vx,ball2.puck.vy);
			ball4.setimg(3);
			ball2.setsize(SIZE_L2);
			PA_DeleteSprite(0, BALL_NUM+1);
			ball2.setimg(1);
		}
	}

	if(PA_Distance(lope.x, lope.y, ball2.puck.ball_x, ball2.puck.ball_y-192-SCREENHOLE) < 16*16){

		if(ball2.size == SIZE_L2){
			PA_OutputText(UP_SCREEN, 0, 16, "suri and ball2 Collision !!");
			lope.y = -100;
			ball7.move_flag = 1;
			ball7.setsize(SIZE_L1);
			ball7.setlocate(ball2.puck.ball_x, ball2.puck.ball_y,-ball2.puck.vx, ball2.puck.vy);
			ball7.setimg(6);
			ball2.setsize(SIZE_L1);
			PA_DeleteSprite(0, BALL_NUM+1);
			ball2.setimg(1);
		}
	}

	if(PA_Distance(lope.x, lope.y, ball2.puck.ball_x, ball2.puck.ball_y-192-SCREENHOLE) < 16*8){
		PA_OutputText(UP_SCREEN, 0, 16, "suri and ball2 Collision !!");
		lope.y = -100;
		//	PA_DeleteSprite(0, BALL_NUM+1);
		ball2.move_flag = 0;
		ball2.puck.ball_x=-100;
		ball2.puck.ball_y=-100;
		PA_SetSpriteXY(DOWN_SCREEN, BALL_NUM, ball2.puck.ball_x - BALL_RADIUS, ball2.puck.ball_y);	//��
	}

	if (PA_Distance(lope.x, lope.y, ball3.puck.ball_x, ball3.puck.ball_y-192-SCREENHOLE) < 16*16) {

		if(ball3.size == SIZE_L2){
			PA_OutputText(UP_SCREEN, 0, 16, "suri and ball3 Collision !!");
			lope.y = -100;
			ball6.move_flag = 1;
			ball6.setsize(SIZE_L1);
			ball6.setlocate(ball3.puck.ball_x, ball3.puck.ball_y,-ball3.puck.vx, ball3.puck.vy);
			ball6.setimg(5);
			ball3.setsize(SIZE_L1);
			PA_DeleteSprite(0, BALL_NUM + 2);
			ball3.setimg(2);
		}
	}
	if(PA_Distance(lope.x, lope.y, ball3.puck.ball_x, ball3.puck.ball_y-192-SCREENHOLE) < 16*8){
		PA_OutputText(UP_SCREEN, 0, 16, "suri and ball3 Collision !!");
		lope.y = -100;
		//	PA_DeleteSprite(0, BALL_NUM + 2);
		ball3.move_flag = 0;
		ball3.puck.ball_x = -100;
		ball3.puck.ball_y = -100;
		PA_SetSpriteXY(DOWN_SCREEN, BALL_NUM+2, ball3.puck.ball_x - BALL_RADIUS, ball3.puck.ball_y);	//��
	}

	if (PA_Distance(lope.x, lope.y, ball4.puck.ball_x, ball4.puck.ball_y-192-SCREENHOLE) < 16*8) {

		if(ball4.size == SIZE_L2){
			PA_OutputText(UP_SCREEN, 0, 16, "suri and ball4 Collision !!");
			lope.y = -100;
			ball8.move_flag = 1;
			ball8.setsize(SIZE_L1);
			ball8.setlocate(ball4.puck.ball_x, ball4.puck.ball_y,-ball4.puck.vx, ball4.puck.vy);
			ball8.setimg(7);
			ball4.setsize(SIZE_L1);
			PA_DeleteSprite(0, BALL_NUM + 3);
			ball4.setimg(3);
		}
	}
	if(PA_Distance(lope.x, lope.y, ball4.puck.ball_x, ball4.puck.ball_y-192-SCREENHOLE) < 16*8){
		lope.y = -100;
		//	PA_DeleteSprite(0, BALL_NUM+3);
		ball4.move_flag = 0;
		ball4.puck.ball_x=-100;
		ball4.puck.ball_y=-100;
		PA_SetSpriteXY(DOWN_SCREEN, BALL_NUM+3, ball4.puck.ball_x - BALL_RADIUS, ball4.puck.ball_y);	//��
	}

	if (PA_Distance(lope.x, lope.y, ball5.puck.ball_x, ball5.puck.ball_y-192-SCREENHOLE) < 16*8) {
		lope.y = -100;
		//	PA_DeleteSprite(0, BALL_NUM + 4);
		ball5.move_flag = 0;
		ball5.puck.ball_x = -100;
		ball5.puck.ball_y = -100;
		PA_SetSpriteXY(DOWN_SCREEN, BALL_NUM+4, ball5.puck.ball_x - BALL_RADIUS, ball5.puck.ball_y);	//��
	}

	if (PA_Distance(lope.x, lope.y, ball6.puck.ball_x, ball6.puck.ball_y-192-SCREENHOLE) < 16*8) {
		lope.y = -100;
		//	PA_DeleteSprite(0, BALL_NUM + 5);
		ball6.move_flag = 0;
		ball6.puck.ball_x = -100;
		ball6.puck.ball_y = -100;
		PA_SetSpriteXY(DOWN_SCREEN, BALL_NUM+5, ball6.puck.ball_x - BALL_RADIUS, ball6.puck.ball_y);	//��
	}

	if (PA_Distance(lope.x, lope.y, ball7.puck.ball_x, ball7.puck.ball_y-192-SCREENHOLE) < 8*8) {
		lope.y = -100;
		//PA_DeleteSprite(0, BALL_NUM + 6);
		ball7.move_flag = 0;
		ball7.puck.ball_x = -100;
		ball7.puck.ball_y = -100;
		PA_SetSpriteXY(DOWN_SCREEN, BALL_NUM+6, ball7.puck.ball_x - BALL_RADIUS, ball7.puck.ball_y);	//��
	}

	if (PA_Distance(lope.x, lope.y, ball8.puck.ball_x, ball8.puck.ball_y-192-SCREENHOLE) < 8*8) {
		lope.y = -100;
		//	PA_DeleteSprite(0, BALL_NUM + 7);
		ball8.move_flag = 0;
		ball8.puck.ball_x = -100;
		ball8.puck.ball_y = -100;
		PA_SetSpriteXY(DOWN_SCREEN, BALL_NUM+7, ball8.puck.ball_x - BALL_RADIUS, ball8.puck.ball_y);	//��
	}

}


void Stage::Location_Update() {
	if(isGameOver == 0)
		character.move();

	Collision_Ball_Character();
	Collision_Ball_Lope();
	Collision_Character_Item();
	lope.move(character.x, character.y);

	ball.move();
	if(ball2.move_flag)
		ball2.move();
	if(ball3.move_flag)
		ball3.move();
	if(ball4.move_flag)
		ball4.move();
	if(ball5.move_flag)
		ball5.move();
	if(ball6.move_flag)
		ball6.move();
	if(ball7.move_flag)
		ball7.move();
	if(ball8.move_flag)
		ball8.move();

	if(ball.move_flag == 0 && ball2.move_flag == 0&& ball3.move_flag == 0&& ball4.move_flag == 0
			&& ball5.move_flag == 0 && ball6.move_flag == 0 && ball7.move_flag == 0 && ball8.move_flag == 0 )
		PA_OutputText(UP_SCREEN, 0, 14, "Stage Clear!!");

	if(isItem == 1){
		isItem = 0;
		item.change();
	}else{
		item.move();
	}
}

void Stage::Image_Update() {
	PA_SetSpriteXY(DOWN_SCREEN, CHARACTER_NUM, character.x, character.y);		//�ɸ���
	if(ball.move_flag)
		PA_SetSpriteXY(DOWN_SCREEN, BALL_NUM, ball.puck.ball_x - BALL_RADIUS, ball.puck.ball_y);	//��
	if(ball2.move_flag)
		PA_SetSpriteXY(DOWN_SCREEN, BALL_NUM+1, ball2.puck.ball_x - BALL_RADIUS, ball2.puck.ball_y);	//��
	if(ball3.move_flag)
		PA_SetSpriteXY(DOWN_SCREEN, BALL_NUM+2, ball3.puck.ball_x - BALL_RADIUS, ball3.puck.ball_y);	//��
	if(ball4.move_flag)
		PA_SetSpriteXY(DOWN_SCREEN, BALL_NUM+3, ball4.puck.ball_x - BALL_RADIUS, ball4.puck.ball_y);	//��
	if(ball5.move_flag)
		PA_SetSpriteXY(DOWN_SCREEN, BALL_NUM+4, ball5.puck.ball_x - BALL_RADIUS, ball5.puck.ball_y);	//��
	if(ball6.move_flag)
		PA_SetSpriteXY(DOWN_SCREEN, BALL_NUM+5, ball6.puck.ball_x - BALL_RADIUS, ball6.puck.ball_y);	//��
	if(ball7.move_flag)
		PA_SetSpriteXY(DOWN_SCREEN, BALL_NUM+6, ball7.puck.ball_x - BALL_RADIUS, ball7.puck.ball_y);	//��
	if(ball8.move_flag)
		PA_SetSpriteXY(DOWN_SCREEN, BALL_NUM+7, ball8.puck.ball_x - BALL_RADIUS, ball8.puck.ball_y);	//��

	//PA_SetSpriteXY(DOWN_SCREEN, , ball.puck.ball_x - BALL_RADIUS, ball.puck.ball_y);	//��
	PA_SetSpriteXY(DOWN_SCREEN, ITEM_NUM, item.x, item.y);		//������
	PA_SetSpriteXY(DOWN_SCREEN, LOPE_NUM, lope.x, lope.y);		//����

}
