import sys

# handle command line arguments
# print useful message if no arguments given
if len(sys.argv) < 3:
    print("Usage:")
    print("  $ python3 names_set.py FEMALE_DATA MALE_DATA [TEST NAMES]")
    print("Example:")
    print("  $ python3 names_set.py dist.female.first dist.male.first Nick")
    sys.exit()

# extract arguments from sys.argv
female_data = sys.argv[1]
male_data   = sys.argv[2]
test_names  = sys.argv[3:]

# Create sets for female and male names
female = set()
f = open(female_data)
for line in f:
    female.add(line.split()[0])
f.close()

male = set()
f = open(male_data)
for line in f:
    male.add(line.split()[0])
f.close()

# Summarize information about the reference data
print("There are {} female names and {} male names.".format(len(female),len(male)))
print("There are {} names that appear in both sets.".format(len(female & male)))

# Try our algorithm
for name in test_names:
    if name.upper() in male:
        ret = "M"
    elif name.upper() in female:
        ret = "F"
    else:
        ret = "NA"
    print("{}: {}".format(name, ret))
