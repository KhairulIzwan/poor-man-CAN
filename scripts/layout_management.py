#!/usr/bin/env python

# import the necessary packages
import sys
from PyQt4 import QtGui

def window():
	app = QtGui.QApplication(sys.argv)
	w = QtGui.QWidget()

	b = QtGui.QPushButton(w)
	b.setText("Hello World!")
	b.move(50,20)

	w.setGeometry(100,100,300,200)
	w.setWindowTitle("PyQt")
	w.show()
	sys.exit(app.exec_())

if __name__ == '__main__':
	window()
