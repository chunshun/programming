def find_max(S):
    if len(S)==1:
        return S[-1]
    else:
        n=len(S)//2
        return max(find_max(S[:n]),find_max(S[n:]))

print(find_max(list(range(100))))