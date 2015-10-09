class User:
    def __init__(self, id):
        self.id = id
    def __len__(self):
        return self.getId()
    def getId(self):
        return self.id
