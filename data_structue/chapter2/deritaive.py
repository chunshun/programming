string= "-3*x**4+8*x**2-3*x+1"

# string=input()

operator=['+','-']

# for lement in string:
string_format=[]
# index=0
for index,char  in enumerate(string):
    # index=string.index(char)
    
    if char=='+' or char=='-':
        
        string_format.append(char)
        if '+' in string[index+1:] or '-' in string[index+1:]:
            # next_index=list(string[index:]).index('+') |
            plus_index=string[index+1:].find('+')
            minux_index=string[index+1:].find('-')
            if plus_index*minux_index!=0:
                next_index=min(plus_index,minux_index)  
            string_format.append(string[index:next_index+1])
    index=next_index



# print(string_format)
print(string_format)
