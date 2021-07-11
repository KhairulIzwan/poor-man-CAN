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

/*put your setup code here, to run once*/
void setup()
{
  Serial.begin(9600); // For debug use
  Serial.println("CAN Read - Testing receival of CAN Bus message");  
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
      
      Serial.println("");
    }
  }
}
