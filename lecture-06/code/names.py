class NameClassifier:
    def __init__(self, femalefile, malefile):
        self.LoadNameData(femalefile, malefile)

    def LoadNameData(self, femalefile, malefile):
        # Creates a dictionary with the name data from the two input files
        self.namedata = {}
        self.weights = {}
        f = open(femalefile,'r')
        for line in f:
            name = line.split()[0]
            weight = float(line.split()[1])
            self.namedata[name] = 1.0
            self.weights[name] = weight
        f.close()
            
        f = open(malefile,'r')
        for line in f:
            name = line.split()[0]
            if name in self.namedata:
                # Probability the name is female
                weight = float(line.split()[1])
                self.namedata[name] = self.weights[name]/(self.weights[name]+weight)
            else:
                self.namedata[name] = 0.0
        f.close()

    def ClassifyName(self, name):
        if name in self.namedata:
            return self.namedata[name]
        else:
            # Don't have this name in our data
            return 0.5
