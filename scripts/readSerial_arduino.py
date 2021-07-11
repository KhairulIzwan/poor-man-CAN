#!/usr/bin/env python

# import the necessary packages
import serial

arduino = serial.Serial('/dev/ttyUSB0', 9600, timeout=.1)

listCANID = []

while True:
	data = arduino.readline().rstrip()
	
	# Turn the byte string into a string and ignore the illegal string, 
	# because part of the string cannot be converted to UTF-8
	data = data.decode('utf-8','ignore')
	
#	listCANID = []
	
	if data:
#		print("A:%d\tB:%d\tC:%d\tD:%d" % (int(data[0:4]), int(data[4:8]), int(data[8:12]), int(data[12:16])))
#		print(data)
#		print(len(data))
#		print(data[0:3])	#ID:
#		print(data[3:7])	#CANID
		
		a = data[3:7]
		a = a.encode('ascii','ignore')
		a = str(a)
#		print(int(a, base=16))	#CANID
		
		a = int(a)
#		print(a)
		
		if a not in listCANID:
			listCANID.append(a)
			
	print(listCANID)
	print(len(listCANID))
		
#		print(len(a))

		
#		if data[3:7] 
