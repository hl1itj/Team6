/*
 * main.c
 *
 *  Created on: 2011. 9. 24.
 *      Author: Minsuk Lee
 */

#include "init.h"

static portTASK_FUNCTION(ControlTask, pvParameters);

void InitDebug(void);

int
main(void)
{
	InitDebug();
	init_virtual_io(ENABLE_LED);	// Enable Virtual IO Devices
	init_printf();					// Initialize Bottom Screen for printf()

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

void Control(void);

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


