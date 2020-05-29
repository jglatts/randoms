import os
from decimal import *

class CableData(object):

    def __init__(self):
        self.count = 0
        self.totalErrors = 0
        self.totalPasses = 0
        self.totalPinErrors = 0
        self.totalPinPasses = 0
        self.totalOLErrors = 0
        self.copyoutput = ""
        self.copy = []
        self.verbose = False


    def readAllFiles(self):
        files = [f for f in os.listdir('.') if self.isTextFile(f)]
        self.copy = files
        for f in files:
           self.readFile(f)
           self.count += 1
    

    def isTextFile(self, f):
        return os.path.isfile(f) and f[-1] != "y"


    def readFile(self, filename):
        f = open(filename, "r")
    
        #read off some data
        for i in range(6):
            f.readline()   
    
        self.readTestData(f)         
        f.close()


    def readTestData(self, f):
        passed = True
        h = f.readline().split(" ")
        c = f.readline().split()
        p = f.readline().split("-")
        check = c[len(c)-1]
        limcheck = h[len(h)-1]  #add another helper() to check for OL lims
        pins = int(p[len(p)-1])
        errcount = 0

        #print data for each pin
        for x in range(pins):
           s = f.readline().split()
           if (s[2] == check and check == "OL"):
               errcount += 1
               self.totalPinErrors += 1
               passed = False   
           else:
               self.totalPinPasses += 1
        
        self.checkData(passed, f, pins, errcount)  
        print("Resistance Actual Value = " + check)
        print("Resistance High Limit   = " + limcheck)    



    def checkData(self, passed, f, pins, errcount):
        if (passed):
            self.totalPasses += 1
        else:
            self.totalErrors += 1
        if (self.verbose):
            print("Testing: " + f.name + " Data File: " + str(self.count+1) + " Testing " + str(pins) + " pins, Errors: " + str(errcount))       
            print("Raw File = ")
            print(self.copyoutput + "\n")
        else:
            print("Data File #" + str(self.count+1) + ", Testing " + str(pins) + " pins, Errors: " + str(errcount))  


    def checkForOpens(self):
        count = 0
        files = [f for f in os.listdir('.') if self.isTextFile(f)]
        for f in files:
            isopen = False
            file = open(f, "r")
            line = file.readline()
            while (line):
                str = line.split()
                for s in str:
                    if (s == "OL"):
                        isopen = True
                        break
                line = file.readline()
            file.close()
            if (isopen):
                count += 1

        return count


    def printResults(self):
        print("\nTested: " + str(self.count) + " cables")
        print("Total Passes: " + str(self.totalPasses))
        print("Total Fails: " + str(self.totalErrors))
        print("Total OL Fails: " + str(self.checkForOpens()))
        print("Total Pin Passes: " + str(self.totalPinPasses))
        print("Total Pin Errors: " + str(self.totalPinErrors))        
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
