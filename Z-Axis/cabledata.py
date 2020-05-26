import os
from decimal import *

class CableData(object):

    def __init__(self):
        self.count = 0
        self.totalErrors = 0
        self.totalPasses = 0
        self.copyoutput = ""
        self.copy = []
        self.verbose = False

    def readAllFiles(self):
        files = [f for f in os.listdir('.') if os.path.isfile(f) and f[-1] != "y"]
        self.copy = files
        for f in files:
           self.readFile(f)
           self.count += 1

    def readFile(self, filename):
        f = open(filename, "r")
    
        #read off some data
        for i in range(7):
            f.readline()   
    
        self.readTestData(f)         
        f.close()

    def readTestData(self, f):
        passed = True
        c = f.readline().split()
        p = f.readline().split("-")
        check = c[len(c)-1]
        pins = int(p[len(p)-1])
        pincount = 0

        #print data for each pin
        for x in range(pins):
           s = f.readline().split()
           if (s[2] == check and check == "OL"):
               pincount += 1
               passed = False
    
        if (passed):
            self.totalPasses += 1
        else:
            self.totalErrors += 1
        if (self.verbose):
            print("Testing: " + f.name + " Data File: " + str(self.count+1) + " Testing " + str(pins) + " pins, Errors: " + str(pincount) + "\n")       
            print("Raw File = ")
            print(self.copyoutput + "\n")
        else:
            print("Data File: " + str(self.count+1) + " Testing " + str(pins) + " pins, Errors: " + str(pincount) + "\n")       
    
    def printResults(self):
        print("\nTested: " + str(self.count) + " cables")
        print("Total Passes: " + str(self.totalPasses))
        print("Total Errors: " + str(self.totalErrors))
        sum = self.totalPasses + self.totalErrors
        print("%pass " + str(round((self.totalPasses / sum) * 100, 2)) + "%")
        print("%error " + str(round((self.totalErrors / sum) * 100, 2)) + "%")

    def copyFile(self):
        c = 1
        for f in self.copy:
            file = open(f, "r")
            print("\n--------------Test #" + str(c) + "--------------")
            print(file.read())
            file.close()
            c += 1

    def testData(self):
        self.readAllFiles()

    def testData(self):
        self.readAllFiles()

    def testDataVerbose(self):
        print("\n-------------------Verbose Output Enabled-------------------\n")
        self.verbose = True
        self.readAllFiles()
        self.copyFile()
        self.verbose = False
