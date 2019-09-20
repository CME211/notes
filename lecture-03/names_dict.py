import sys

# handle command line arguments
# print useful message if no arguments given
if len(sys.argv) < 3:
    print("Usage:")
    print("  $ python3 names_dict.py FEMALE_DATA MALE_DATA [TEST NAMES]")
    print("Example:")
    print("  $ python3 names_dict.py dist.female.first dist.male.first Nick")
    sys.exit()

# extract arguments from sys.argv
female_data = sys.argv[1]
male_data   = sys.argv[2]
test_names  = sys.argv[3:]

# Create dictionary with name data
names = {}
f = open(female_data)
for line in f:
    names[line.split()[0]] = 1.
f.close()

f = open(male_data)
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

# Try our algorithm
for name in test_names:
    # set default value return value as unknown
    ret = 0.5
    if name.upper() in names:
        ret = names[name.upper()]
    print("{}: {}".format(name, ret))
