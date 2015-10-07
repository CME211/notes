class Student:
    def __init__(self, id):
        self.__id = id
        self.classes = {}
    def getId(self):
        return self.__id

s = Student(7)
print("s.getId() = {}".format(s.getId()))
print("s.id = {}".format(s.__id))
