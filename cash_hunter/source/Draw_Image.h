/*
 * Draw_Image.h
 *
 *  Created on: 2011. 12. 19.
 *      Author: Administrator
 */

#ifndef DRAW_IMAGE_H_
#define DRAW_IMAGE_H_


#endif /* DRAW_IMAGE_H_ */
#include "piano_image.h"
#define WALL_WIDTH      32
#define WALL_HEIGHT     32
#define WALL_Y_POS      3
#define WALL_X_MAX      (SCREEN_WIDTH / BOX_WIDTH)
static PrintConsole TopScreen,bottomScreen;


#define BG_GFX			((u16*)0x6000000)		/**< \brief background graphics memory*/
/** \brief  Screen height in pixels */
#define SCREEN_HEIGHT 192
/** \brief  Screen width in pixels */
#define SCREEN_WIDTH  256

#define COLOR_RED       RGB(31,  0,  0) /* Bright Red  	*/
#define COLOR_WHITE     RGB(31, 31, 31) /* Bright White */
#define COLOR_BLACK     RGB( 0,  0,  0)	/* Black : Zero	*/

#define DIRECTION_UP 1
#define DIRECTION_DOWN 2
#define DIRECTION_LEFT 3
#define DIRECTION_RIGHT 4

#define BOX_WIDTH	8
#define BOX_HEIGHT	8

#define BOX_X_POS	0
#define BOX_Y_MAX	(SCREEN_HEIGHT / BOX_HEIGHT)
