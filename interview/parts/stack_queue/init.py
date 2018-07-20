"""
to implement a sack,which has such methods,like `push`,`pop`,`peek`,`is_empty`,`size`
peek():return the top item from the stack but does not remove it.It needs no parameters.The stack is not modified 
"""

class Stack:
    def __init__(self):
        self._data=[]
    def size(self):
        return len(self._data)
    def push(self,item):
        return self._data.append(item)
    def pop(self):
        if self.size()==0:
            return None
        else:
            return self._data.pop()
    def peek(self):
        return self._data[0]
    def is_empty(self):
        return True if self.size()==0 else False
# stack=Stack()    
# stack.push(1)
# stack.push(2)
# stack.pop()
# print(stack._data)
# print(stack.size())
# stack.pop()