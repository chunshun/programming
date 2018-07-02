def fab(n):
    if n<=1:
        return (n,0)
    else:
        (a,b)=fab(n-1)
        return (a+b,a)
    

print(fab(100))