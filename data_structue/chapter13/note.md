# Text Processing 
1. Pattern-Matching Algorithms
Given a string T of length n and a pattern string P of length m,to find whether P is a substring of T.If so,we may want to find the lowest index j within T at which P begins,or perhaps to find all indices of T at which pattern P begins
- The KMP algorithm
2. Dynamic Programming 
- maximum sequence sum 
- DNA and Text Sequence Alignment(longest common sequence)
$X=x_1x_2\cdots x_n,Y=y_1y_2\cdots y_n,L_{j,k}$ denotes the longest of a longest string that is sub-sequence of both $X[0:j],Y[0;k]$
    - $x_{j-1}=y_{k-1}, L_{j,k}=1+L_{j-1,k-1}$
    - $x_{j-1}\neq y_{k-1},L_{j,k}=\max\{L_{j-1,k},L_{j,k-1}\}$ 
```python 
def LCS(X,Y):
    """return table such that L[j][k] is length of LCS X[0:j] and Y[0:k]."""
    n,m=len(X),len(Y)
    L=[[0]*(m+1) for k in range(n+1)]
    for j in range(n):
        for k in range(m):
            if X[j]==Y[k]:
                L[j+1][k+1]=L[j][k]+1
            else:
                L[j+1][k+1]=max(L[j][k+1],L[j+1][k])

    return L

def LCS_solution(X,Y):
    """Return the longest common substring of X and Y,given LCS table L"""
    solution=[]
    j,k=len(X),len(Y)
    while L[j][k]>0:
        if X[i-1]==Y[j-1]:
            solution.append(X[j-1])
            j-=1
            k-=1
        elif L[j-1][k]>=L[j][k-1]:
            j-=1
        else:
            k-=1
    return ''.join(reversed(solution))
```

3. The Greedy Algorithm 
- The Hoffman Coding

4. Tries(单词查找树) 
A trie is a tree-based data structure for storing strings in order to support fast pattern matching.The name 'trie' comes from the word 'retrieval'.The prefix query operation that trie supports are pattern matching and prefix matching 
- standard tries
- compressed tries
- suffix tries