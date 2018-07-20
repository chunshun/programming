from init import Stack
# import sys
balanced=True
stack=Stack()
parent=list('()')
data=list(input())
print(data)
index=0
while index<len(data):
    x=data[index]
    if x in parent:
        stack.push(x) 
    if x==')':
        stack.pop()
        y=stack.pop()
        if y==')':
            balanced=False
            break
    
    index+=1
print(index)
print(balanced)
print(stack.size())
if stack.size()==0:
    print(True)
else:
    print(False)