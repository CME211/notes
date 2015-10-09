import copy

class Student:
    def __init__(self, id):
        self.id = id
        self.classes = {}
    def getId(self):
        return self.id
    def addClass(self, name, gradepoint):
        self.classes[name] = gradepoint
        sumgradepoints = float(sum(self.classes.values()))
        self.gpa = sumgradepoints/len(self.classes)
    def getGPA(self):
        return self.gpa
    def getClasses(self):
        return copy.deepcopy(self.classes)
    def __repr__(self):
        string = "Student %d: " % self.getId()
        string += " %s, " % self.getClasses()
        string += "GPA = %4.2f" % self.getGPA()
        return string

s = Student(7)
s.addClass("gym", 4)
s.addClass("math", 3)

# now easy to print a student
print(s)
