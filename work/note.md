1. decorator:
```python
def paragraphize(inputFunction):
   def newFunction():
      return "<p>" + inputFunction() + "</p>"
   return newFunction

@paragraphize
def getText():
   return "Here is some text!"
```
2. Time Using


```python
nums=list(range(100)) #list

nums=[x for x in range(100)] #comprehension

def test():
    l=[]
    for i in range(100):
        l.append(i)   #append

def test_1():
    l=[]
    for i in range(100):
        l=l+[i]

```
3. `del` keyword
To delete the useless variable
```python
for x in range(10):
    do(x)
del x

```