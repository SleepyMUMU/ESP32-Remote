#include <Arduino.h>
#include <FashionStar_UartServo.h>
#include <FashionStar_UartServoProtocol.h>

#define SERVO_ID 0x01

//初始化舵机通讯协议
FSUS_Protocol protocol;

//绑定舵机到协议
FSUS_Servo servo(SERVO_ID, &protocol);

void task1(void *pvParameters)
{
  for (;;)
  {
    Serial.println("Task 1 is running");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
String inputString = "";         // a string to hold incoming data

void SerialCom(void *pvParameters)
{
  for (;;)
  {
    if (Serial.available() > 0)
    {
      while (Serial.available() > 0)
      {
        inputString += (char)Serial.read();
      }
    }
  }
}

  void setup()
  {
    // put your setup code here, to run once:
    Serial.begin(115200);

    servo.init();
    servo.setSpeed(100.0);
    servo.setAngle(0);
    
    xTaskCreate(task1, "Task 1", 1000, NULL, 1, NULL);
    xTaskCreate(SerialCom, "SerialCom", 1000, NULL, 1, NULL);
    vTaskStartScheduler();
  }

  void loop()
  {
    // put your main code here, to run repeatedly:
  }
