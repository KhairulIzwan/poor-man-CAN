// Useful for data logging/stream
/*import the necessary packages*/

/*Library for using SPI Communication*/
#include <SPI.h>
/*Library for using CAN Communication*/
#include <mcp2515.h>

/*Create object*/
struct can_frame canMsg;

/*SPI CS Pin 10 */
MCP2515 mcp2515(10);

/*put your setup code here, to run once:*/
void setup() 
{
	Serial.begin(115200);

	mcp2515.reset();
	mcp2515.setBitrate(CAN_1000KBPS,MCP_16MHZ);
	mcp2515.setNormalMode();

/*	Serial.println("------- CAN Read ----------");*/
/*	Serial.println("ID  DLC   DATA");*/
}

/*put your main code here, to run repeatedly:*/
void loop()
{
	if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK)
	{
/*		print ID*/
		Serial.print(canMsg.can_id, HEX);
		Serial.print("\t");
		
/*		print DLC*/
		Serial.print(canMsg.can_dlc, HEX);
		Serial.print("\t");

/*		print the data*/
		for (int i = 0; i<canMsg.can_dlc; i++)  
		{
			Serial.print(canMsg.data[i],HEX);
			Serial.print("\t");
		}

		Serial.println();      
	}
}
