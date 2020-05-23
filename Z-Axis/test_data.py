# add data processing stuff
def readFile(filename):
    #open data file
    count = 0
    f = open(filename, "r")
    
    #read off some data
    for i in range(7):
        f.readline()   
        
    # clean this guy tf up
    c = f.readline().split()
    p = f.readline().split("-")
    check = c[len(c)-1] 
    pins = int(p[len(p)-1])

    #print data for each pin
    for x in range(pins):
       s = f.readline().split()
       z = s[0]
       if (s[2] == check and check == "OL"):
           count += 1
           z = z[1:2]
    
    return count         

def readTestData(f):
    #read critical data
    c = f.readline().split()
    p = f.readline().split("-")
    check = c[len(c)-1] # change this to a try-catch with ValueError if it's thrown we have an OL
    pins = int(p[len(p)-1])


print(str(readFile("20200521_162421_ZCC In-House Tester.txt")) + " errors with this cable")
