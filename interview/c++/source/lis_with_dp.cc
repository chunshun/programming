#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int array[]={
        9,1,2,4,2,3,6,4,
    };
    vector<int> dp(sizeof(array)/sizeof(array[0]),1);
    int res=0;
    int length=sizeof(array)/sizeof(array[0]);
    for(int i=0;i<length;i++){
        for(int j=0;j<i;j++){
            if(array[i]>array[j]){
                dp[i]=max(dp[i],dp[j]+1);
                
            }
        }
        res=max(res,dp[i]);
    }
    cout<<res<<endl;    
    // sort()
    return 0;
}
