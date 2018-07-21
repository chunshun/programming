from init import Stack

stack=Stack()
string='((()))(())'
parent='()'
# data=string.split()
index=0
balanced=True
print(list(string))
while index<len(string):
    if stack.is_empty() and string[index]==')':
        balanced=False
        break
    else:
        x=string[index]
        if x in parent:
            stack.push(x) 
            print(stack._data)
            if x==')':
                stack.pop()
                y=stack.pop()
                print(stack._data)
                if y==')':
                    balanced=False
                    break
            
    print(index,x)   
    index+=1
        # stack.push(string[index]) 
if not stack.is_empty():
    balanced=False
    
print(balanced)