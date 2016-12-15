#include <Arduino_FreeRTOS.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int buzzer = 10, greenLED = 3, yellowLED = 4, redLED = 5;

void Normal( void *pvParameters );
void Ambulance( void *pvParameters );
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup()
{
   pinMode(buzzer, OUTPUT);
   pinMode(greenLED, OUTPUT);
   pinMode(yellowLED, OUTPUT);
   pinMode(redLED, OUTPUT);
   lcd.begin(16, 2);
   lcd.backlight();
   xTaskCreate(Normal, (const portCHAR *)"Normal", 128, NULL, 2, NULL);
   xTaskCreate(Ambulance, (const portCHAR *)"Ambulance", 128, NULL, 3, NULL);
}
void loop()
{
  
}

void Normal( void *pvParameters )
{
  (void) pvParameters;
  int i;
  const TickType_t xDelay = 1000/portTICK_PERIOD_MS;
  for (;;)
  {
    for(i=4; i>0; i--)
    {
      digitalWrite(greenLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Green light");
      lcd.setCursor(0, 1);
      lcd.print(i);
      vTaskDelay(xDelay);
    }
    for(i=2; i>0; i--)
    {
      digitalWrite(yellowLED, HIGH);
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Yellow light");
      lcd.setCursor(0, 1);
      lcd.print(i);
      vTaskDelay(xDelay);
    }
    for(i=6; i>0; i--)
    {
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Red light");
      lcd.setCursor(0, 1);
      lcd.print(i);
      vTaskDelay(xDelay);
    }
  }
}

void Ambulance( void *pvParameters )
{
  (void) pvParameters;
  int i, r;
  const TickType_t xDelay = 1000/portTICK_PERIOD_MS;
  for (;;)
  {
    r = random(7, 13);
    vTaskDelay(xDelay*r);
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    for(i=4; i>0; i--)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Ambulance");
      lcd.setCursor(0, 1);
      lcd.print(i);
      tone(buzzer, 500, 500);
      delay(1000);
    }
    vTaskDelay(xDelay*(12-r));
  }
}

