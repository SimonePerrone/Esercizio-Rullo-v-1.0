#include "FreeRTOSConfig.h"             // ARM.FreeRTOS::RTOS:Config
#include "FreeRTOS.h"   
#include "task.h"                       // ARM.FreeRTOS::RTOS:Core
#include "timer.h"                     // ARM.FreeRTOS::RTOS:Timers
#include "event_groups.h"               // ARM.FreeRTOS::RTOS:Event Groups
#include <stdio.h>
#include "Arduino.h"
#include "Buzzer.h"
#define PIN_BUZZER PE15

extern EventGroupHandle_t xEventGroupRullo;


void BuzzerInit(void) {
	pinMode(PIN_BUZZER,OUTPUT);
	xTaskCreate(vTaskBuzzerTest, /* Pointer to the function that implements the task.              */
		"Task 1 (vTaskMotPA2)",    /* Text name for the task.  This is to facilitate debugging only. */
		50,   /* Stack depth in words.                */
		NULL,  /* We are not using the task parameter. */
		1,     /* This task will run at priority 1.    */
		NULL); /* We are not using the task handle.    */
}


void vTaskBuzzerTest(void * pvParameters) {
	const EventBits_t xBitsToWaitFor = EV_OBJECT_DETECTED;
	while(1){
		xEventGroupWaitBits(xEventGroupRullo,xBitsToWaitFor,pdTRUE,pdTRUE,portMAX_DELAY);
		digitalWrite(PIN_BUZZER, HIGH);
		vTaskDelay(300);
		digitalWrite(PIN_BUZZER, LOW);
	}
}
