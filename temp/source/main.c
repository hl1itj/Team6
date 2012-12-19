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
static portTASK_FUNCTION(ControlTask, pvParameters);

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

	xTaskCreate(SoundTask,
			(const signed char * const)"SoundTask",
			2048,
			(void *)NULL,
			tskIDLE_PRIORITY + 1,
			NULL);

	KeyQueue = xQueueCreate(MAX_KEY_LOG, sizeof(u8));

	xTaskCreate(KeyTask,
			(const signed char * const)"KeyTask",
			2048,
			(void *)NULL,
			tskIDLE_PRIORITY + 1,
			NULL);

	xTaskCreate(ImageTask,
			(const signed char * const)"ImageTask",
			2048,
			(void *)NULL,
			tskIDLE_PRIORITY + 1,
			NULL);
	xTaskCreate(ControlTask,
			(const signed char * const)"ControlTask",
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

