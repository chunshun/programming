# Recursion
1. linear recursion
- summing the elements of a sequence recursively

```python

def linear_sum(S,n):
    """Return the sum of the first n numbers of sequence S"""
    if n==0:
        return 0
    else:
        return linear_sum(S,n-1)+S[n-1]

```

- reversing a sequence with recursion 

```python 
def reverse(S,start,stop):
    """Reverse elements in implicit slice S[start:stop]"""
    if stop<stop-1:
        S[start],S[stop-1]=S[stop-1],S[start]
        reverse(S,start+1,stop-1)
    


```
- recursive algorithms for computing powers
```python

def power(x,n):
    """compute the value x**n for integer n"""
    if n==0:
        return 1
    else:
        return x*power(x,n-1)


```
or

```python 

def power(x,n):
    if n==0:
        return 1
    else:
        partial=power(x,n//2)
        result=partial*partial
        if n%2==0:
            result*=x
        return result

        

```


2. binary recursion
- summing the n elements of a sequence
```python 

def binary_sum(S,start,stop):
    """Return the sum of the  numbers in implicit slice S[start:stop]"""
    if start>=stop:
        return 0
    elif start == stop -1:
        return S[start]
    else:
        mid=(start+stop)//2
        return binary_sum(S,start,mid)+binary_sum(S,mid,stop)


```
3. multiple recursion
such as disk space usage  of the file system.

4. Emilatingn the tail recursion
A recursion is a tail recustion  if any recursive call that is made from one context is the very last operation in that context,with the return value of the recursive call(if any) immediately returned by the enclosing recursion.By necessity,a tail recusrion must be a linear recusrionO(since there is no way to make a second recursive call if you must immdediately return the result of the first)

Any tail recursion can be reimplemented nonrecursively by enclosing the body in a loop for repetition,and replacing a recursive call with new parameters by a reassignment of the existing parameters to those values.