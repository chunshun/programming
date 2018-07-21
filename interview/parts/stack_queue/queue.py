"""
The queue abstract data type
- queue():create the empty queue
- dequeue():removes the item 
- enqueue(item):adds a new item to the rear of the queue
- is_empty():return whether the queue is empty
- size():returns the length of the queue

"""
class Queue:
    def __init__(self):
        self._data=[]
    def queue(self):
        return Queue()
    def dequeue(self):
        self._data