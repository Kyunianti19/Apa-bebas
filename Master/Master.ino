// Wire Master Writer

#include <Wire.h>
#include "HEADER.h"

int delayLed;
char n[8];

void setup() 
{
  Serial.begin(9600);
  Wire.begin();
}

void loop() 
{
  while(Serial.available())
  {
    String c = Serial.readString();
    if (c == "On")
    {
      Wire.beginTransmission(7);
      Wire.write('H');
      Wire.endTransmission();
    }
    else if (c == "Off")
    {
      Wire.beginTransmission(7);
      Wire.write('L');
      Wire.endTransmission(); 
    } else if ((isDelay(c))||((c[0]=='d')&&(c[1]==' ')))
    {
      delayLed = ParseDelay(c);
      Wire.beginTransmission(7);
      Wire.write('D');
      itoa(delayLed, n, 10);
      int i = 0;
      while ((n[i]>='0')&&(n[i]<='9')){
        Wire.write(n[i]);
        i++;
      }
      Wire.write('a');
      Wire.endTransmission(); 
    }
   
    Serial.println(c);
    Serial.println(delayLed);
    Serial.println(n);
  }
}
