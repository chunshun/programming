from init import Stack
nums=11
stack=Stack()
while nums>0:
    stack.push(nums%2)
    nums=nums//2
# print(stack._data.reverse())
data=stack._data
print(list(reversed(data)))
