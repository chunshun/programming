def binary_search(data,target,low,high):
    if low >high:
        return False
    else:
        mid=(low+high)//2

        if data[mid]==target:
            print(mid)
            return True
        else:
            if data[mid]>target:
                # high=mid-1
                return binary_search(data,target,low,mid-1)
            else:
                return binary_search(data,target,mid+1,high)
        
data=list(range(100))
print(binary_search(data,90,0,len(data)-1))
