/*given a sequence to find the maximum sum of the contiguous subsequence
*   dp[i]:the maximum sum ended with index i
*   then dp[i]=max(A[i],dp[i-1]+A[i])
*/  

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int array[]={
        // 2,1,-1,-1,-2,4
        2,-1,3
    };
    int length=sizeof(array)/sizeof(array[0]);
    vector<int>dp(length,0);
    dp[0]=array[0];

    for(int i=1;i<length; i++){
        dp[i]=max(array[i],dp[i-1]+array[i]);
    }
    // dp[i]存放的是以index_i结尾的最大值
    for(int i=0;i<length;i++){
        cout<<dp[i]<<"\t";
    }
    int k=0;
    for(int i=0; i<length; i++){
        if (dp[i]>dp[k]) k=i;

    }
    cout<<endl<<dp[k];
    return 0;
    
}
