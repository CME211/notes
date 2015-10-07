class Student:
    def __init__(self, id):
        self.id = id
        self.classes = {}
    def getId(self):
        return self.id

s = Student(7)
print(s)
id = s.getId()
print("id = {}".format(id))
id = 9
print("id = {}".format(id))
print("s.getId() = {}".format(s.getId()))
