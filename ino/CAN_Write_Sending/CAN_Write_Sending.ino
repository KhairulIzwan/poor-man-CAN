/*import the necessary packages/library*/
#include <Canbus.h>
#include <defaults.h>
#include <global.h>
#include <mcp2515.h>
#include <mcp2515_defs.h>

tCAN message1;
tCAN message2;

// These constants won't change. They're used to give names to the pins used:
const int analogInPin0 = A2;  // Analog input pin that the potentiometer is attached to
const int analogInPin1 = A3;  // Analog input pin that the potentiometer is attached to

int sensorValue0 = 0;        // value read from the pot
int outputValue0 = 0;        // value output to the PWM (analog out)
int sensorValue1 = 0;        // value read from the pot
int outputValue1 = 0;        // value output to the PWM (analog out)

/*put your setup code here, to run once*/
void setup() 
{
  Serial.begin(9600);
  Serial.println("CAN Write - Testing transmission of CAN Bus messages");
//  delay(1000);
  
  if(Canbus.init(CANSPEED_500))  //Initialise MCP2515 CAN controller at the specified speed
  {
    Serial.println("CAN Init ok");
  }
  else
  {
    Serial.println("Can't init CAN");
  }
  
//  delay(1000);
}

/*put your main code here, to run repeatedly:*/
void loop() 
{
  // read the analog in value:
  sensorValue0 = analogRead(analogInPin0);
  sensorValue1 = analogRead(analogInPin1);
  // map it to the range of the analog out:
  outputValue0 = map(sensorValue0, 0, 1023, 0, 255);
  outputValue1 = map(sensorValue1, 0, 1023, 0, 255);
  
  message1.id = 0x631; //formatted in HEX
  
  message1.header.rtr = 0;
  
  message1.header.length = 8; //formatted in DEC
  
  message1.data[0] = 0x40;
  message1.data[1] = 0x05;
  message1.data[2] = 0x30;
  message1.data[3] = 0xFF; //formatted in HEX
  message1.data[4] = 0x00;
  message1.data[5] = 0x40;
  message1.data[6] = outputValue0;
  message1.data[7] = outputValue1;

  message2.id = 0x632; //formatted in HEX
  
  message2.header.rtr = 0;
  
  message2.header.length = 8; //formatted in DEC
  
  message2.data[0] = 0x00;
  message2.data[1] = 0x00;
  message2.data[2] = 0x40;
  message2.data[3] = 0x00; //formatted in HEX
  message2.data[4] = 0xFF;
  message2.data[5] = 0x30;
  message2.data[6] = 0x05;
  message2.data[7] = 0x40;
  
  mcp2515_bit_modify(CANCTRL, (1<<REQOP2)|(1<<REQOP1)|(1<<REQOP0), 0);
  
  mcp2515_send_message(&message1);
  mcp2515_send_message(&message2);
  
  delay(100); // 1000ms
}
