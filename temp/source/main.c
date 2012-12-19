/*
 * main.c
 *
 *  Created on: 2011. 9. 24.
 *      Author: Minsuk Lee
 */

#include "init.h"

void InitDebug(void);

static portTASK_FUNCTION(KeyTask, pvParameters);
static portTASK_FUNCTION(ImageTask, pvParameters);
static portTASK_FUNCTION(SoundTask, pvParameters);
static portTASK_FUNCTION(ControlTask, pvParameters);

extern xQueueHandle KeyQueue;
#define MAX_KEY_LOG		10


int
main(void)
{
	InitDebug();
	//init_virtual_io(ENABLE_LED);	// Enable Virtual IO Devices

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

static
portTASK_FUNCTION(ImageTask, pvParameters )
{
	while (1) {
		//playData = getStatus();

		//PrintScreen(playData);
	}
}

portTASK_FUNCTION( KeyTask, pvParameters) {
	u16 key;
	u8 key_pressed = FALSE;

		while (1) {
		key = NDS_SWITCH();
		writeb_virtual_io(BARLED2, 0);

		if ((key_pressed == FALSE) && (key != NULL)){
			key_pressed = TRUE;
			xQueueSend(KeyQueue, &key, 0);
		}

		if ((key_pressed == TRUE) && (key == 0))
			key_pressed = FALSE;

		if (NDS_SWITCH() & KEY_START)
			break;
		vTaskDelay(50);
	}
	while (NDS_SWITCH() & KEY_START)
		vTaskDelay(10);		// Wait while START KEY is being pressed

}

portTASK_FUNCTION(SoundTask, pvParameters )
{

	while (1) {
		/*
			배경음을 출력한다.
			상태에 따른 효과음을 출력한다.

		playData = getStatus();
		switch(playData.status){
			case BACKGROUND :
			break;
			case CAUGHT :
			break;
			case WIN :
			break;

			}*/
	}
}

static
portTASK_FUNCTION(ControlTask, pvParameters )
{
	while (1) {
		setPlayData();
	}
}




