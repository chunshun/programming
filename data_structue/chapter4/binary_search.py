sq=list(range(100))
num=30
# sq=[]
# i=0
start=0
end=len(sq)-1
mid=(start+end)//2

# binary search with a sorted list
def binary_search(sq):
       
    global mid,start,end
    
        # return False
    try:
        if sq[mid]==num:
            print(mid)
            return mid
        else:
            if sq[mid]<num:
                
                start=mid+1
                end=end+1
                mid=(start+end)//2
                # print(sq[]
                sq=sq[start:end]
                return binary_search(sq[start:end])
            else:
                start=start=1
                end=mid+1
                mid=(start+end)//2
                # sq=sq[start:end]
                return binary_search(sq[start:end])

   
    except :
        return False
        pass

            
            
# num=30
print(binary_search(sq))