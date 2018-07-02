

def alphabet_frequency(file):
# file="~/programming/data_structue/chapter2/deritaive.py"
    string = open(file, 'r+').read()
    print(string)
    # string="chubs "
    alphabet_list = []
    alphabet_list_count = [0]*26
    for c in range(65, 91):
        alphabet_list.append(chr(c))
        # alphabet_list.append(chr(c).lower())

    # print(alphabet_list)
    # print(set(alphabet_list))

    for c in string:
        if c.isalpha():
            print(c.upper())
            index = alphabet_list.index(c.upper())
            print(index)
            alphabet_list_count[index] += 1

    print(alphabet_list_count)


# print(alphabet_frequency())
alphabet_frequency('./test.py')