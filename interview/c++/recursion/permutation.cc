// hashTable[x]=true if x is in the pernmuation
//
#include <iostream>
using namespace std;
const int max_n = 11;
int n, p[max_n], hash_table[max_n] = {false};
void generate_permutation(int index)
{
    if (index == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << p[i];
        }
    cout<<endl;
    return;
    }
    for(int x=1; x<=n; x++){
        if (hash_table[x]==false){
            p[index]=x;
            hash_table[x]=true;
            generate_permutation(index+1 );
            hash_table[x]=false;
        }
    }
}
int main(int argc, char const *argv[])
{
    n=100;
    generate_permutation(1);
    return 0;
}
// int jjjjjjj  fun(int x){
    // jjj
// }jjj