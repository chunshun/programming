/* the overlapping problem is:
*LIS is a special case of edit distance, LIS:to find the longest increasing subsequence(similar to the MSIS(to find the i-th increasing array))
* L[i]:bottom-up approach
* dp[i] denotes that the longest increasing  subsequence ended with the A[i]
* then dp[i]=max(1,dp[j]+1),where j=1,2,3,...,n-1  and A[j]<A[i]
* if the item is larger than the previous element in the LIS,than add the item in the set
* else exclude the current item
*/
#include <iostream>
#include <string.h>
using namespace std;
void LIS(int array[], int n)
{
    // int n = sizeof(array) / sizeof(*array);
    // std::cout<
    std::cout << n << endl;
    int record[n];
    memset(record, 0, sizeof(record));
    for (int i = 0; i < n; i++)
    {
        int item[i];

        for (int j = 1; j < i; j++)
        {
            cout << array[i] << endl;
            if(array[j-1]<array[j] && array[j]<array[i]){
                cout<<array[j]<<"\t";
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int array[5] = {
        1, 2, 3, 4, 5};
    LIS(array, 5);
    return 0;
}
