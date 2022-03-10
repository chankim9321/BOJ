print("hello world!")
class human:
    def __init__(self,name):
        self.name=name
    def greeting(self):
        print("helllo {0}".format(self.name))
a=human("병찬")
a.greeting()
