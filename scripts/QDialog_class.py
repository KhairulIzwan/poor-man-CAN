#!/usr/bin/env python

# import the necessary packages
import sys
from PyQt4.QtGui import *
from PyQt4.QtCore import *

def window():
	app = QApplication(sys.argv)
	w = QWidget()
	
	b = QPushButton(w)
	b.setText("Hello World!")
	b.move(50,50)
	b.clicked.connect(showdialog)
	
	w.setWindowTitle("PyQt Dialog demo")
	w.show()
	sys.exit(app.exec_())

def showdialog():
	d = QDialog()
	b1 = QPushButton("ok",d)
	b1.move(50,50)
	d.setWindowTitle("Dialog")
	d.setWindowModality(Qt.ApplicationModal)
	d.exec_()

if __name__ == '__main__':
	window()
