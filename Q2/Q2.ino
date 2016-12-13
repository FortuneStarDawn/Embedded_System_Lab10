#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#define KEY_ROWS 4
#define KEY_COLS 4

int mode = 0, count = 0;

char keymap[KEY_ROWS][KEY_COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte colPins[KEY_COLS] = {9, 8, 7, 6};
byte rowPins[KEY_ROWS] = {13, 12, 11, 10};

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, KEY_ROWS, KEY_COLS);

// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
void setup()
{ 
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.noBacklight();
}
void loop()
{ 
  char key = myKeypad.getKey();
  if(key)
  {
    if(mode==0)
    {
      if(key=='*')
      {
        lcd.backlight();
        lcd.print("Enter password:");
        mode = 1;
      }
    }
    if(mode==1)
    {
      if(count==0)
      {
        if(key=='1') count++;
        else count=0;
      }
      else if(count==1)
      {
        if(key=='2') count++;
        else count=0;
      }
      else if(count==2)
      {
        if(key=='3') count++;
        else count=0;
      }
      if(count==3)
      {
        mode=0;
        count=0;
        lcd.clear();
        lcd.noBacklight();
      }
    }
  }
}

