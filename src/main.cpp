#include <Arduino.h>

void task1(void *pvParameters)
{
  for (;;)
  {
    Serial.println("Task 1");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

// put function declarations here:
int myFunction(int, int);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  xTaskCreate(task1, "Task 1", 1000, NULL, 1, NULL);
  vTaskStartScheduler();
  Serial.println("Setup");
}

void loop()
{
  // put your main code here, to run repeatedly:
}
