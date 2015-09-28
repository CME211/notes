# Create dictionary with name data
names = {}
f = open("dist.female.first")
for line in f:
    names[line.split()[0]] = 1.
f.close()

f = open("dist.male.first")
for line in f:
    name = line.split()[0]
    if name in names:
        # Just assume a 50/50 distribution for names on both lists
        names[name] = 0.5 
    else:
        names[name] = 0.
f.close()

# Summary information about our reference data
print("There are {} names in our reference data.".format(len(names)))

# Test data
testdata = ["PETER", "LOIS", "STEWIE", "BRIAN", "MEG", "CHRIS", "NICK"]

# Try our algorithm
for name in testdata:
    if name in names:
        ret = names[name]
    else:
        ret = 0.5
    print("{}: {}".format(name, ret))
