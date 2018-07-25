/*to find the longest subsequence of a given sequence in increasing order
* dp[i]: the lis of A[i] ended with index i
* dp[i]=max(dp[j]+1 , 1) where j<i and A[j]<A[i]
*/
#include <iostream>
using namespace std;
int lis_index(int array[],int n){
    int items[n+1][n+1];
    if (n==1){
        return 1;
    }
    else{
        // int count =0;
        for(int i = 0; i < n; i++)
        {
            
            if (array[i]<array[n])
                // count++;
                re
        }
        return n;
    }
    
}
int main(int argc, char const *argv[])
{
    int array[]={12,3,4,4,5,6};
    cout<<sizeof(array)<<"-----------------\t"<<sizeof(array[0])<<endl;

    return 0;
}
