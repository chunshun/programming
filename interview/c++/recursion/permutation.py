from itertools import permutations,chain
for x in permutations(range(100)):
    print(list(chain(x)),end='\n')