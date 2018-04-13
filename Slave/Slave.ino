// Wire Slave Receiver

#include <Wire.h>
#include "HEADER.h"

char c;
boolean ledState = false;
int delayLed = 0;
char b[8];
int  i;

void setup() 
{
  Wire.begin(7);                
  Wire.onReceive(receiveEvent);

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() 
{
  if (c == 'H' )
    {
      ledState=true;
      if (delayLed == 0)
      {
        digitalWrite(13, HIGH);
      }
      else
      {
        digitalWrite(13, HIGH);
        delay (delayLed);
        digitalWrite(13, LOW);
        delay (delayLed);
      }
    }
    else if (c == 'L')
    {
      ledState=false;
      digitalWrite(13, LOW);
    }
    else if ((c=='D') && (ledState))
    {  
      if (delayLed == 0)
      {
        digitalWrite(13, HIGH);
      }
      else
      {
        digitalWrite(13, HIGH);
        delay (delayLed);
        digitalWrite(13, LOW);
        delay (delayLed);
      }
    }
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) 
{ 
  while(Wire.available())
  {
    c = Wire.read();
    if (c == 'H' )
    {
      ledState=true;
    }
    else if (c == 'L')
    {
      ledState=false;
    }
    else if (c=='D')
    {  
      char a = Wire.read();
      while (a!='a'){
        i = 0;
        b[i]=a;
        i++;
        a = Wire.read();
      }
      //b[i]='\0';
      delayLed=atoi(b);
    }
  }
}
