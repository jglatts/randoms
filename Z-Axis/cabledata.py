import os
import sys

from decimal import *




#
#
# |\_____  \|\   ____\|\   ____\        |\  \|\  \|\  \|\   ____\|\  \|\  \                                          
#  \|___/  /\ \  \___|\ \  \___|        \ \  \\\  \ \  \ \  \___|\ \  \\\  \                                         
#      /  / /\ \  \    \ \  \            \ \   __  \ \  \ \  \  __\ \   __  \                                        
#     /  /_/__\ \  \____\ \  \____        \ \  \ \  \ \  \ \  \|\  \ \  \ \  \                                       
#    |\________\ \_______\ \_______\       \ \__\ \__\ \__\ \_______\ \__\ \__\                                      
#     \|_______|\|_______|\|_______|        \|__|\|__|\|__|\|_______|\|__|\|__|                                      
# ________  ________  _______   _______   ________          ________  ________  ________  ___       _______         
# |\   ____\|\   __  \|\  ___ \ |\  ___ \ |\   ___ \        |\   ____\|\   __  \|\   __  \|\  \     |\  ___ \        
# \ \  \___|\ \  \|\  \ \   __/|\ \   __/|\ \  \_|\ \       \ \  \___|\ \  \|\  \ \  \|\ /\ \  \    \ \   __/|       
#  \ \_____  \ \   ____\ \  \_|/_\ \  \_|/_\ \  \ \\ \       \ \  \    \ \   __  \ \   __  \ \  \    \ \  \_|/__     
#   \|____|\  \ \  \___|\ \  \_|\ \ \  \_|\ \ \  \_\\ \       \ \  \____\ \  \ \  \ \  \|\  \ \  \____\ \  \_|\ \    
#     ____\_\  \ \__\    \ \_______\ \_______\ \_______\       \ \_______\ \__\ \__\ \_______\ \_______\ \_______\   
#    |\_________\|__|     \|_______|\|_______|\|_______|        \|_______|\|__|\|__|\|_______|\|_______|\|_______|   
#    \|_________|                                                                                                    
#  _________  _______   ________  _________  _______   ________          ________  ________  _________  ________     
# |\___   ___\\  ___ \ |\   ____\|\___   ___\\  ___ \ |\   __  \        |\   ___ \|\   __  \|\___   ___\\   __  \    
# \|___ \  \_\ \   __/|\ \  \___|\|___ \  \_\ \   __/|\ \  \|\  \       \ \  \_|\ \ \  \|\  \|___ \  \_\ \  \|\  \   
#      \ \  \ \ \  \_|/_\ \_____  \   \ \  \ \ \  \_|/_\ \   _  _\       \ \  \ \\ \ \   __  \   \ \  \ \ \   __  \  
#       \ \  \ \ \  \_|\ \|____|\  \   \ \  \ \ \  \_|\ \ \  \\  \|       \ \  \_\\ \ \  \ \  \   \ \  \ \ \  \ \  \ 
#        \ \__\ \ \_______\____\_\  \   \ \__\ \ \_______\ \__\\ _\        \ \_______\ \__\ \__\   \ \__\ \ \__\ \__\
#         \|__|  \|_______|\_________\   \|__|  \|_______|\|__|\|__|        \|_______|\|__|\|__|    \|__|  \|__|\|__|
#
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
        self.passed = True
        self.verbose = False

    def readAllFiles(self):
        files = [f for f in os.listdir('.') if self.isTextFile(f)]
        self.copy = files
        for f in files:
           self.readFile(f)
           if (self.verbose and not self.passed):
               print()
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
        self.passed = True
        failed = []
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
               failed.append(x)
               self.passed = False   
           else:
               self.totalPinPasses += 1
        
        self.checkData(f, pins, errcount, failed)  
        #print("Resistance High Limit   = " + limcheck)    
        #print("Resistance Actual Value = " + check)

    def checkData(self, f, pins, errcount, failed):
        if (self.passed):
            self.totalPasses += 1
        else:
            self.totalErrors += 1
            if (self.verbose):
                self.printVerbose(pins, errcount)
            for i in range(len(failed)):
                pin = failed[i] 
                if (self.verbose):
                    s = str(pin + 1) + " "
                    sys.stdout.write(s)

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
                        self.totalPinErrors += 1
                        break
                line = file.readline()
            file.close()
            if (isopen):
                count += 1

        return count

    def printVerbose(self, pins, errcount):
        print("\nData File: " + str(self.count+1))
        print("Testing: " + str(pins) + " pins")
        print("Errors: " + str(errcount))

    def printResults(self):
        print("Tested:           " + str(self.count) + " cables")
        print("Total Passes:     " + str(self.totalPasses))
        print("Total Fails:      " + str(self.totalErrors))
        print("Total OL Fails:   " + str(self.checkForOpens()))
        print("Total Pin Passes: " + str(self.totalPinPasses))
        print("Total Pin Errors: " + str(self.totalPinErrors))        
        sum = self.totalPasses + self.totalErrors
        print("%pass             " + str(round((self.totalPasses / sum) * 100, 2)) + "%")
        print("%error            " + str(round((self.totalErrors / sum) * 100, 2)) + "%\n")

    def copyFile(self):
        c = 1
        for f in self.copy:
            file = open(f, "r")
            print("\n--------------Test #" + str(c) + "--------------")
            print(file.read())
            file.close()
            c += 1

    def testData(self):
         # change to sys calls for no \n
        print("\n******************************")
        print("... Reading Data Files ...")
        print("******************************")
        self.readAllFiles()

    def testDataVerbose(self):
        print("******************************")
        print("... Reading Data Files ...")
        print("******************************")
        self.verbose = True
        self.readAllFiles()
        self.verbose = False
