#!/usr/bin/env python

# import the necessary packages
import serial

arduino = serial.Serial('/dev/ttyUSB1', 9600, timeout=.1)
 
while True:
	data = arduino.readline().rstrip()
	
	# Turn the byte string into a string and ignore the illegal string, 
	# because part of the string cannot be converted to UTF-8
	data = data.decode('utf-8','ignore')
	
	if data:
		print("A:%d\tB:%d\tC:%d\tD:%d" % (int(data[0:4]), int(data[4:8]), int(data[8:12]), int(data[12:16])))
