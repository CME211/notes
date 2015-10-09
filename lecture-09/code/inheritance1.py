# parent class
class User:
    def __init__(self, id):
        self.id = id
    def getId(self):
        return self.id

# child class
class MovieWatcher(User):
    pass
