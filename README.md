# poor-man-CAN

## Reference
1. [CAN Bus Explained - A Simple Intro (2021)](https://www.csselectronics.com/screen/page/simple-intro-to-can-bus/language/en)
2. [Introduction to CAN BUS and How to use it with Arduino](https://www.seeedstudio.com/blog/2019/11/27/introduction-to-can-bus-and-how-to-use-it-with-arduino/)
3. [Arduino CAN Tutorial - Interfacing MCP2515 CAN BUS Module with Arduino](https://circuitdigest.com/microcontroller-projects/arduino-can-tutorial-interfacing-mcp2515-can-bus-module-with-arduino)
4. [CAN Bus Module Tutorial for Arduino, Raspberry Pi and Intel Galileo](https://www.cooking-hacks.com/documentation/tutorials/can-bus-module-shield-tutorial-for-arduino-raspberry-pi-intel-galileo.html)
5. [Car to Arduino Communication: CAN Bus Sniffing and Broadcasting With Arduino](https://www.instructables.com/CAN-Bus-Sniffing-and-Broadcasting-with-Arduino/)
6. [Python-OBD](https://python-obd.readthedocs.io/en/latest/Connections/)
7. [M3 Pi: Raspberry Pi OBD-II Touchscreen Car Computer](https://projects-raspberry.com/m3-pi-raspberry-pi-obd-ii-touchscreen-car-computer/)
8. [Basic Syntax](https://www.markdownguide.org/basic-syntax/)
9. [Extended Syntax](https://www.markdownguide.org/extended-syntax/#fnref:1)
10. [Connecting Arduino to Processing](https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing/all)
11. [Visual Synthesizer](https://pi.processing.org/tutorial/visual-synth/)
12. [About python reading serial data sent by Arduino to convert bytes to str](https://www.programmersought.com/article/57543488505/)
13. [SPRINTF() WITH ARDUINO | PRINT MULTIPLE VARIABLES TO THE SERIAL MONITOR](https://www.programmingelectronics.com/sprintf-arduino/)
14. [Zero Padding or Leading Zeros](https://forum.arduino.cc/t/zero-padding-or-leading-zeros/72406/13)
15. [Python Datalogger - Using pySerial to Read Serial Data Output from Arduino](https://makersportal.com/blog/2018/2/25/python-datalogger-reading-the-serial-output-from-arduino-to-analyze-data-using-pyserial)
16. [How to connect Arduino and Python](http://arahna.de/connect-arduino-python/)
17. [Communication with Arduino from Linux-Terminal](http://arahna.de/arduino-command-line/)
18. [How to install and run qt-designer for python](https://askubuntu.com/questions/763877/how-to-install-and-run-qt-designer-for-python)
19. [Qt Designer and Python: Build Your GUI Applications Faster](https://realpython.com/qt-designer-python/#connecting-signals-and-slots)
20. [Python and PyQt: Building a GUI Desktop Calculator](https://realpython.com/python-pyqt-gui-calculator/)
21. [Qt Examples And Tutorials](https://doc.qt.io/qt-5/qtexamplesandtutorials.html)


## Hardware

| No | Items       | Quantity    | Price (Unit) |
| -- | ----------- | ----------- | ------------ |
| 1 | [Maker UNO Edu Kit (Arduino Compatible)](https://my.cytron.io/p-maker-uno-edu-kit-arduino-compatible) | 2 | RM49.90 |
| 2 | [Elecfreaks CAN-BUS Shield](https://my.cytron.io/p-elecfreaks-can-bus-shield) | 2 | RM50.83	|
| 3 | [Car OBD2 16-Pin to DB9 9-pin Serial Port RS232 Adapter Cable](https://shopee.com.my/Car-OBD2-16-Pin-to-DB9-9-pin-Serial-Port-RS232-Adapter-Cable-i.138610561.2437925166) | 1 | RM15.86 |
| 4 | [Autool Car Obd2 USB Interface Scanner ELM327](https://shopee.com.my/Autool-Car-Obd2-USB-Interface-Scanner-ELM327-i.130188002.6514727716) | 1 | RM20.90 |

<!--### Image-->

<!--![Maker UNO Edu Kit (Arduino Compatible)](https://github.com/KhairulIzwan/poor-man-CAN/blob/main/img/KIT-MAKER-UNO-EDU-05-800x800.jpeg "Maker UNO Edu Kit (Arduino Compatible)")-->

<!--![Elecfreaks CAN-BUS Shield](https://github.com/KhairulIzwan/poor-man-CAN/blob/main/img/SHIELD-CAN-BUS-800x800.jpg "Elecfreaks CAN-BUS Shield")-->

<!--![Car OBD2 16-Pin to DB9 9-pin Serial Port RS232 Adapter Cable](https://github.com/KhairulIzwan/poor-man-CAN/blob/main/img/obd2serial.jpeg "Car OBD2 16-Pin to DB9 9-pin Serial Port RS232 Adapter Cable")-->

<!--![Autool Car Obd2 USB Interface Scanner ELM327](https://github.com/KhairulIzwan/poor-man-CAN/blob/main/img/Obd2-USB-Interface-Scanner-ELM327.jpeg "Autool Car Obd2 USB Interface Scanner ELM327")-->

## Experiments

1. Basic CAN **Write** and **Read**

1.1. CAN Write: Sending pre-defined value (HEX)
 
```c
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
	canMsg1.data[0] = 0x01;
	canMsg1.data[1] = 0x01;
	canMsg1.data[2] = 0x01;
	canMsg1.data[3] = 0x01;
	canMsg1.data[4] = 0x01;
	canMsg1.data[5] = 0x01;
	canMsg1.data[6] = 0x01;
	canMsg1.data[7] = 0x86;

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
	canMsg2.data[7] = 0xA0;

/*	Serial.println("Example: Write to CAN");*/
}

/*put your main code here, to run repeatedly:*/
void loop()
{
/*	Sends the CAN message*/
	mcp2515.sendMessage(&canMsg1);
	mcp2515.sendMessage(&canMsg2);

/*	Serial.println("Messages sent");*/
  
	delay(100);
}
```

1.2. CAN Read: Read **ALL** data`s in CAN-Bus
 
```c
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
```
