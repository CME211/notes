class Student:
    def __init__(self, id):
        self.id = id
        self.classes = {}
    def getId(self):
        return self.id

s = Student(7)
print(s)
print(s.getId())
