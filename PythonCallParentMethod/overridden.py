# Python program to demonstrate
# calling the parent's class method
# inside the overridden method


class Parent(object):
	#def __init__(self):
	#	pass

	def show(self):
		print("Inside Parent")
		
class Child(Parent):
	#def __init__(self):
        #    super(Parent, self).__init__()

	def show(self):
		# Calling the parent's class
		# method
		Parent.show(self)
		#super().show()			#python 3
		#super(Parent, self).show()	#python 2.7????
		print("Inside Child")
		
# Driver's code
obj = Child()
obj.show()

