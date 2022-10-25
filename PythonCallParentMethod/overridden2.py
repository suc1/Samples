# Python program to demonstrate
# calling the parent's class method
# inside the overridden method


class Parent(object):
	def __init__(self):
		pass

	def show(self):
		print("Inside Parent")
		
class Child(Parent):
	def __init__(self):
            Parent.__init__(self)
		
# Driver's code
obj = Child()
obj.show()

