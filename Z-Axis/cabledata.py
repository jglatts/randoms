import os

class CableData(object):

    # use this to check all the data and find an average pass/fail rate
    def readAllFiles(self):
        files = [f for f in os.listdir('.') if os.path.isfile(f) and f[-1] != "y"]
        count = 1
        for f in files:
           self.readFile(f, count)
           count += 1

    # add data processing stuff
    def readFile(self, filename, count):
        f = open(filename, "r")
    
        #read off some data
        for i in range(7):
            f.readline()   
    
        self.readTestData(f, count)         
        f.close()

    def readTestData(self, f, count):
        #read critical data
        c = f.readline().split()
        p = f.readline().split("-")
        check = c[len(c)-1]
        pins = int(p[len(p)-1])
        pincount = 0

        #print data for each pin
        for x in range(pins):
           s = f.readline().split()
           z = s[0]
           if (s[2] == check and check == "OL"):
               pincount += 1
               z = z[1:2]
        print("Data File: " + str(count) + " Testing " + str(pins) + " pins, Errors: " + str(pincount))       
    
    
    def testData(self):
        self.readAllFiles()


