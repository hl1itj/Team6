/*
 * init.h
 *
 *  Created on: 2011. 12. 19.
 *      Author: Administrator
 */

#ifndef INIT_H_
#define INIT_H_


 /* INIT_H_ */

#include <stdio.h>          // C-Standard Header
#include <time.h>
#include <stdlib.h>

#include <FreeRTOS.h>       // Free RTOS Headers
#include <task.h>
#include <queue.h>
#include <semphr.h>

#include <nds.h>            // NDS / Sevencore Board Headers
#include <sevencore_io.h>
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

#include "card_spi.h"		// Debugging Headers
#include "gdbStub.h"
#include "gdbStubAsm.h"
#include "sevencore_io.h"

#define KEY_MOVE 0xf0
void Control();

///------
/*

static portTASK_FUNCTION(KeyTask, pvParameters);
static portTASK_FUNCTION(ImageTask, pvParameters);
static portTASK_FUNCTION(SoundTask, pvParameters);
static portTASK_FUNCTION(ControlTask, pvParameters);
*/
//--

typedef struct
{
	int x; // 캐릭터 x좌표
	int y; // 캐릭터 y좌표

	char status;//캐릭터 상태 (승리,패배,보통)
}PlayData;


#endif
