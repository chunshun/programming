## Stacks,Queues,Deques
### Stacks
The stacks method：
- S.push(e)
- S.pop()
- S.top()
- S.is_empty()
- len(S)
1. The Adapter Pattern    
The adapter design pattern applies to any context where we effectively want to modify an existing class so that its methods match those of a related, but different,class or interface.One general way to apply the adapter pattern is to define a new class in such a way that it contains an instance of the new class using methods of this hidden instance variable.

1. Implementing a Stack Using a Python List
```python
class ArrayStack:
    """LIFO Stack implementation using a Python list as underlying storage"""
    def __init__(self) :
        """create an empty stack"""
        self._data=[]  #nonpublic list instance


    def __len__(self):
        return len(self._data)
    

    def is_empty(self):
        """return true if the stack is empty"""
        return len(self._data)==0
    
    def push(self,e):
        self._data.append(e)   #new item stored at end of list
    
    def top(self):
        if self.is_empty():
            raise Empty('stack is empty')
        return self._data.pop()
            
```
3. Reversing Data Using a Stack
```python

def reverse_file(filename):
    """Overwrite given file with its contents line-by-line reversed"""
    S=ArrayStack()
    original=open(filename)
    for line in original:
        S.push(line.rstrip('\n'))
    original.close()


    #now we overwrite with contents in LIFO order
    output=open(**filename**,'w')
    while not S.is_empty():
        output.write(S.pop()+'\n')
    output.close()

```
4. Matching Parentheses and HTML Tags
To match the `{}` ,`[]` and `()`.
```python 

def is_matched(expr):
    """return true if all delimiters are properly match;false otherwise"""
    lefty='({['  #opening delimiters
    righty=')}]' #respective closing delimiter

    S=ArrayStack()
    for c in expr:
        if c in lefty:
            S.push(c)   #push left delimiter on stack
        elif c in righty: 
            if S.is_empty():
                return False    #nothing to match with
            if righty.index(c)!=lefty.index(S.pop()):
                return False      # mis-matched
    return S.is_empty()  #where all symbols matched?

```
5. Match html tags

```python 

def is_matched_html(raw=''):
    """return true if all HTML tags are properly match;False otherwise"""
    S=ArrayStack()
    j=raw.find('<')
    while j!=-1:
        k=raw.find('>',j+1)
        if k==-1:
            return False
        tag=raw[j+1:k]
        if not tag.startswith('/'):
            S.push(tag)
        else:
            if S.is_empty():
                return False
            if tag[1:]!= S.pop():
                return  False
        j=raw.find('<',k+1)

    return S.is_empty()
            
```
### Queues
The queues methods
- Q.enquenue(e)
- Q.dequeue()
- Q.first()
- Q.is_empty()
- len(Q)
1. A Python Queue Implementation 
```python 

class ArrayQueue:
    """FIFO queue implementation """
    DEFAULT_CAPACITY=10 #moderate capacity for all new queues

    def __init__(self):
    """create an empty queue"""
        self._data=[None]*ArrayQueue.DEFAULT_CAPACITY
        self._size=0
        self._front=0
    
    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size==0
    
    def first(self):
        """return (but do not remove) the element at the front of the queue
        Raise Empty exception if the queue is empty"""
        if self.is_empty():
            raise Empty("Queue is empty")
        return self._data[self._front]
    
    def dequeue(self):
        
        """remove and return the first element of the queue
        raise empty exception if the queue is empty"""
        if self.is_empty():
            raise Empty("queue is empty")

        answer=self._data[self._front]
        self._data[self._front]=None 
        self._front=(self._front+1)%len(self._data)
        self._size-=1
        return answer

    def enqueue(self,e):
        if self._size==len(self._data):
            self._resize(2*len(self._data))
        avail=(self._front+self._size)%len(self._data)
        self._data[avail]=e 
        self._size+=1

    def _resize(self,cap):
        """resize to a new list of capacity>=len(self)"""
        old=self._data
        self._data=[None]*cap
        walk=self._front
        for k in range(self._size):
            self._data[k]=old[walk]
            walk=(1+walk)%len(old)
        self._front=0
        

    
```
### Double-Ended Queues 
double-ended queue,or deque,implemented in `collections` module,supports insertion and 
deletion at both the front and the back of the queue.
