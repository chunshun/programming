/* In fact,the LCS's formula is recursive,however,the recursion part is LCS(i,j)=max(LCS(i-1,j),LCS(i,j-1))
*  in the bottom-up format,we could compute the LCS(i,j),where i<len(X),j<len(Y)
*  At the end ,just query in the table, we could get the result
*/
#include <vector>
#include <iostream>
#include <string>
using namespace std;
int lcs_table(string X, string Y)
{
    int m = X.length(), n = Y.length();
    int table[m + 1][n + 1];
    for (int i = 0; i < n; i++)
    {
        table[0][i] = 0;
    }
    for (int j = 0; j < m; j++)
    {
        table[j][0] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (X[i - 1] == Y[j - 1]) //from the bottom to the up
            {
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            else
            {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }
    return table[m][n];
}

int main(int argc, char const *argv[])
{
    string s1 = "abcs", s2 = "sbc";
    cout << lcs_table(s1, s2);

    return 0;
}
