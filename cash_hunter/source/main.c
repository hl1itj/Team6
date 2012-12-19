/*
 * main.c
 *
 *  Created on: 2011. 9. 24.
 *      Author: Minsuk Lee
 */

#include "init.h"


static portTASK_FUNCTION(Key_Task, pvParameters);
static portTASK_FUNCTION(Touch_Task, pvParameters);
static portTASK_FUNCTION(Sound_Task, pvParameters);
void Key_Sound();
void Touch_Sound();
void Run_Sound();

void Draw_down();
void Draw_Up_Init();
void InitDebug(void);

extern xQueueHandle KeyQueue;
#define MAX_KEY_LOG		10


int
main(void)
{
	InitDebug();
	//init_virtual_io(ENABLE_LED);	// Enable Virtual IO Devices
	Draw_Up_Init();
	Draw_down();

	xTaskCreate(Sound_Task,
			(const signed char * const)"Sound_Task",
			2048,
			(void *)NULL,
			tskIDLE_PRIORITY + 1,
			NULL);

	KeyQueue = xQueueCreate(MAX_KEY_LOG, sizeof(u8));

	xTaskCreate(Key_Task,
			(const signed char * const)"Key_Task",
			2048,
			(void *)NULL,
			tskIDLE_PRIORITY + 1,
			NULL);

	xTaskCreate(Touch_Task,
			(const signed char * const)"Touch_Task",
			2048,
			(void *)NULL,
			tskIDLE_PRIORITY + 1,
			NULL);

	vTaskStartScheduler();		// Never returns
	while(1)
		;
	return 0;
}

void
InitDebug(void)
{
#ifdef DEBUG
	irqInit();
	initSpi();
	initDebug();
	BreakPoint();
#endif
}

static
portTASK_FUNCTION(Key_Task, pvParameters )
{
	while (1) {
		 Key_Sound();
	}
}
static
portTASK_FUNCTION(Touch_Task, pvParameters )
{
	while (1) {
		 Touch_Sound();
	}
}
static
portTASK_FUNCTION(Sound_Task, pvParameters )
{
	while (1) {
		 Run_Sound();
	}
}
