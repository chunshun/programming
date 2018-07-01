string = "-3*x**4+8*x**2-3*x+1"

# index=0
# oerator_plus_index=[]
# operator_minus_index=[]

# string_format=[]

# while index<len(string):
#     if string[index]=='+':
#         oerator_plus_index.append(index)
#     if string[index]=='-':
#         operator_minus_index.append(index)
#     index+=1
    
# # while index<len(string):
#     # char=
# # print(string.split('+'))

# string_format_plus=[]

# for s in string.split('+'):
#     # print(s)
#     # print(s.split('-'))
#     for element in s.split('-'):
#         string_format.append(element)

# print(string)
# print(string_format)
# print(operator_minus_index)
# print(oerator_plus_index)



# 计算每个导数

def cal_element(string):
    # a*x**n
    index_a=string.find('*')
    index_n=string.find('**')
    a=string[:index_a]
    n=string[index_n+2:]
    
    if index_a!= -1 & index_n!=-1:
        if int(n)-1==0:
            return a
        else:
            return str(int(a)*(int(n)))+'*x**'+str(int(n)-1)
    else:
        if index_a==-1 & index_n==-1:
            return '0'
        else:
            if index_a==-1 & index_n!=-1:
                if int(n)-1==0:
                    return a
                else:
                    return int(n)+'*x**'+(int(n)-1)
            
            else:
                return a
        

    # return 
    


# 分片

def cut(string):
    cut_string=[]
    index=0
    cut_index=[]
    # for i in range(len(string)):
        # if string
    for index in range(len(string)):
        if string[index] in '-+':
            cut_index.append(index)
    # print(cut_index)
    for cut_pos in cut_index:
        # print(cut_index.index(cut_pos))
        if cut_index.index(cut_pos)==0:
            cut_string.append(string[:cut_pos])
        else:
            cut_string.append(string[cut_index[cut_index.index(cut_pos)-1]:cut_pos])
    cut_string.append(string[cut_index[-1]:])
    print(cut_string)
    return cut_string


# cut('2*x**4+x-1')


    
finals=[]
# print([cal_element(e) for e in string_format and e!=''])

for e in cut(string):
    # if e!='':
    if '+' in e or '-' in e:
        
        finals.append(e[0]+cal_element(e[1:]))

final_string=''
for ins in finals:
    if '0' not in ins:
        final_string+=ins
        

print(string)
print(finals)

print(final_string)
