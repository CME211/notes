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
        return self.classes

s = Student(7)
s.addClass("gym", 4)
s.addClass("math", 3)
print("GPA = {}".format(s.getGPA()))
print("classes = {}".format(s.getClasses()))
