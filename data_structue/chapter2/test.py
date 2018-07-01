string = "-3*x**4+8*x**2-3*x+1"

index = 0
string_format = []

while index < len(string):

    char = string[index]
    if char == '+' or char == '-':
        string_format.append(char)
        if '+' in string[index+1:] or '-' in string[index+1:]:
            # next_index=list(string[index:]).index('+') |
            plus_index = string[index+1:].find('+')
            minux_index = string[index+1:].find('-')
            if plus_index*minux_index != 0:
                next_index = min(plus_index, minux_index)
            string_format.append(string[index:next_index+1])
        index = next_index
        if(index > len(string)):
            print(index)
            break
    else:
        index += 1

print(string_format)
