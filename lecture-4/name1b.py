# Create sets for female and male names
female = list()
f = open("dist.female.first")
for line in f:
    female.append(line.split()[0])
f.close()

male = list()
f = open("dist.male.first")
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
