import sys

print("There are {} command line argument(s).".format(len(sys.argv)))

for i, arg in enumerate(sys.argv):
    print("arg {}: {}".format(i,arg))
