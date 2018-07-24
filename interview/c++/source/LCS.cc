/*LCS:longest common subsequence of array A and array B
* LCS(i,j):the longest common subsequence of A[i] and B[j]
* then,LCS(i,j)=LCS(i-1,j-1)+1,if A[i]=B[j];else LCS[i][j]=max(LCS(i-1,j),max(i,j-1))
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int lcs(string,string,int,int);
int main(int argc, char const *argv[])
{
    string s1="abcde";
    string s2="abc";
    // int dp[s1.length()];
    cout<<s1.length()<<endl;
    for(int i = 0; i <s1.length() ; i++)
    {
        for(int j = 0; j < s2.length(); j++)
        {

            cout<<lcs(s1,s2,i,j)<<"\t";
        }
        cout<<endl;
        
        /* code */
    }
    
    return 0;
}

int lcs(string s1,string s2,int m, int n){
    if (m==0 || n==0){
        return 0;
    }
    if (s1[m-1]==s2[n-1]){
        return lcs(s1,s2,m-1,n-1)+1;

    }
    else{
        max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
    }
}