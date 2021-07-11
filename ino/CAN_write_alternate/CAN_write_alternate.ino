/*import the necessary packages*/

/*Library for using SPI Communication*/
#include <SPI.h>
/*Library for using CAN Communication*/
#include <mcp2515.h>

/*Create object*/
struct can_frame canMsg1;
struct can_frame canMsg2;

/*SPI CS Pin 10 */
MCP2515 mcp2515(10);

bool state = true;

/*put your setup code here, to run once:*/
void setup()
{
	while (!Serial);
	Serial.begin(115200);
	
/*	Begins SPI communication*/
	SPI.begin();

	mcp2515.reset();
/*	Sets CAN at speed X-KBPS and Clock X-MHz*/
	mcp2515.setBitrate(CAN_1000KBPS,MCP_16MHZ);
/*	Sets CAN at normal mode*/
	mcp2515.setNormalMode();
	
/*	CAN id as per choice*/
	canMsg1.can_id  = 0x570;
/*	CAN data length as 8*/
	canMsg1.can_dlc = 8;
	canMsg1.data[0] = 0x00;
	canMsg1.data[1] = 0x00;
	canMsg1.data[2] = 0x00;
	canMsg1.data[3] = 0x00;
	canMsg1.data[4] = 0x00;
	canMsg1.data[5] = 0x00;
	canMsg1.data[6] = 0x00;
//	canMsg1.data[7] = 0x86;

/*	CAN id as per choice*/
	canMsg2.can_id  = 0x036;
/*	CAN data length as 8*/
	canMsg2.can_dlc = 8;
	canMsg2.data[0] = 0x0E;
	canMsg2.data[1] = 0x0A;
	canMsg2.data[2] = 0x00;
	canMsg2.data[3] = 0x00;
	canMsg2.data[4] = 0x00;
	canMsg2.data[5] = 0x00;
	canMsg2.data[6] = 0x00;
//	canMsg2.data[7] = 0xA0;

/*	Serial.println("Example: Write to CAN");*/
}

/*put your main code here, to run repeatedly:*/
void loop()
{
  if (state == true)
  {
    canMsg1.data[7] = 0x01;
    canMsg2.data[7] = 0xA0;
    state = !state;
  }
  else
  {
    canMsg1.data[7] = 0xFF;
    canMsg2.data[7] = 0xB0;
    state = !state;
  }
  
/*	Sends the CAN message*/
	mcp2515.sendMessage(&canMsg1);
	mcp2515.sendMessage(&canMsg2);

/*	Serial.println("Messages sent");*/
  
	delay(100);
}
