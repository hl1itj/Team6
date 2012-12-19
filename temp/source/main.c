/*
 * main.c
 *
 *  Created on: 2011. 9. 24.
 *      Author: Minsuk Lee
 */

#include "init.h"

void InitDebug(void);


static portTASK_FUNCTION(ControlTask, pvParameters);


#define MAX_KEY_LOG		10


int
main(void)
{
	InitDebug();

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
portTASK_FUNCTION(ControlTask, pvParameters )
{
	while (1) {
		Control();
	}
}



