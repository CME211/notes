import sys

# handle command line arguments
# print useful message if no arguments given
if len(sys.argv) < 3:
    print("Usage:")
    print("  $ python3 names_list.py FEMALE_DATA MALE_DATA [TEST NAMES]")
    print("Example:")
    print("  $ python3 names_list.py dist.female.first dist.male.first Nick Sally")
    sys.exit()

# extract arguments from sys.argv
female_data = sys.argv[1]
male_data   = sys.argv[2]
test_names  = sys.argv[3:]

# Create sets for female and male names
female = list()
f = open(female_data)
for line in f:
    female.append(line.split()[0])
f.close()

male = list()
f = open(male_data)
for line in f:
    male.append(line.split()[0])
f.close()

# Summarize information about the reference data
print("There are {} female names and {} male names.".format(len(female),len(male)))

# need to implement intersection
nboth = 0
for name in female:
    if name in male:
        nboth = nboth + 1

print("There are {} names that appear in both sets.".format(nboth))

# Try our algorithm
for name in test_names:
    if name.upper() in male:
        ret = "M"
    elif name.upper() in female:
        ret = "F"
    else:
        ret = "NA"
    print("{}: {}".format(name, ret))
