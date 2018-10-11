import names

# Create an instance of the name classifier
classifier = names.NameClassifier('../dist.female.first', '../dist.male.first')

# Setup test data
testdata = ['JOHN', 'TERRY', 'GRAHAM', 'CONNIE', 'MICHAEL', 'ERIC']

# Invoke the ClassifyName() method
for name in testdata:
    print('{}: {}'.format(name, classifier.ClassifyName(name)))
