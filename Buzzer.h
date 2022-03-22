#include "task.h" 

#define  EV_OBJECT_DETECTED 1<<0

void BuzzerInit(void);
void BuzzerTest(void);
void vTaskBuzzerTest(void * pvParameters);