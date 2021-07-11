/*
*CAN Master 
*Reading and Streaming DATA on CAN Bus
*/
 
/*import the necessary packages/library*/
#include <Canbus.h>
#include <defaults.h>
#include <global.h>
#include <mcp2515.h>
#include <mcp2515_defs.h>

tCAN message;

const int nrLeds = 3; // total number of LEDs
const int ledPins0[] = { 3, 4, 5}; // array of LEDs pins
const int ledPins1[] = { 6, 7, 8}; // array of LEDs pins
const boolean LED_ON = LOW; // to turn the LED on
const boolean LED_OFF = HIGH; // to turn the LED off

int ledLevel0 = 0; // sensor value converted into LED sequence
int ledLevel1 = 0; // sensor value converted into LED sequence

/*put your setup code here, to run once*/
void setup()
{
  for (int led0 = 0; led0 < nrLeds; led0++)
  {
    pinMode(ledPins0[led0], OUTPUT); // make all the LED pins outputs
  }

  for (int led1 = 0; led1 < nrLeds; led1++)
  {
    pinMode(ledPins1[led1], OUTPUT); // make all the LED pins outputs
  }
  
  Serial.begin(9600); // For debug use
//  Serial.println("CAN Read - Testing receival of CAN Bus message");  
//  delay(1000);
  
  if(Canbus.init(CANSPEED_500))  //Initialise MCP2515 CAN controller at the specified speed
  {
//    Serial.println("CAN Init ok");  
  }
  else
  {
//    Serial.println("Can't init CAN");  
  }
  
//  delay(1000);
}

/*put your main code here, to run repeatedly:*/
void loop()
{ 
  if (mcp2515_check_message())
  {
    if (mcp2515_get_message(&message)) 
  	{
      Serial.print("ID: ");
      Serial.print(message.id,HEX);
      Serial.print("\t");
      
      Serial.print("Data: ");
      Serial.print(message.header.length,DEC);
      Serial.print("\t");
      
      for(int i=0;i<message.header.length;i++) 
      {  
        Serial.print(message.data[i], HEX);
        Serial.print("\t");
      }
      
      if(message.id==0x631)
      {
        ledLevel0 = map(message.data[6], 0, 5, 0, nrLeds); 
//        ledLevel1 = map(message.data[7], 0, 255, 0, nrLeds); 
        
        for (int led0 = 0; led0 < nrLeds; led0++)
        {
          if (led0 < ledLevel0 )
          {
            digitalWrite(ledPins0[led0], LED_OFF); // turn on pins less than the level
          }
          else 
          {
            digitalWrite(ledPins0[led0], LED_ON); // turn off pins higher than the
          }
        }
//        for (int led1 = 0; led1 < nrLeds; led1++)
//        {
//          if (led1 < ledLevel1 )
//          {
//            digitalWrite(ledPins1[led1], LED_ON); // turn on pins less than the level
//          }
//          else 
//          {
//            digitalWrite(ledPins1[led1], LED_OFF); // turn off pins higher than the
//          }
//        }
      }
      else if(message.id==0x632)
      {
//        ledLevel0 = map(message.data[6], 0, 100, 0, nrLeds); 
        ledLevel1 = map(message.data[7], 0, 255, 0, nrLeds); 
        
//        for (int led0 = 0; led0 < nrLeds; led0++)
//        {
//          if (led0 < ledLevel0 )
//          {
//            digitalWrite(ledPins0[led0], LED_ON); // turn on pins less than the level
//          }
//          else 
//          {
//            digitalWrite(ledPins0[led0], LED_OFF); // turn off pins higher than the
//          }
//        }
        for (int led1 = 0; led1 < nrLeds; led1++)
        {
          if (led1 < ledLevel1 )
          {
            digitalWrite(ledPins1[led1], LED_ON); // turn on pins less than the level
          }
          else 
          {
            digitalWrite(ledPins1[led1], LED_OFF); // turn off pins higher than the
          }
        }
      }
      Serial.println("");
    }
  }
}
