
- 1-dimensional dp
  - Tri Tiling
- 2-dimensional dp
  - LCS
- interval dp
  - palindrome
- tree dp
- subset dp
  
1. LCS(longest common subset)
   Given two strings X[m] and Y[n],as to the substring X[:i] and  Y[:j],the formula is given by:
   $LCS(i, j)=LCS(i-1,j-1),if X[i]=Y[j]$
   $LCS(i,j)=\max(LCS(i-1,j),LCS(i,j-1)) if X[i]!=Y[j]$
```c++
#include <iostream>
#include <string>
using namespace std;

// Function to find length of Longest Common Subsequence of substring
// X[0..m-1] and Y[0..n-1]
int LCSLength(string X, string Y)
{
    int m = X.length(), n = Y.length();

    // lookup table stores solution to already computed sub-problems
    // i.e. lookup[i][j] stores the length of LCS of substring
    // X[0..i-1] and Y[0..j-1]
    int lookup[m + 1][n + 1];

    // first column of the lookup table will be all 0
    for (int i = 0; i <= m; i++)
        lookup[i][0] = 0;

    // first row of the lookup table will be all 0
    for (int j = 0; j <= n; j++)
        lookup[0][j] = 0;

    // fill the lookup table in bottom-up manner
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // if current character of X and Y matches
            if (X[i - 1] == Y[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1] + 1;

            // else if current character of X and Y don't match
            else
                lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
        }
    }

    // LCS will be last entry in the lookup table
    return lookup[m][n];
}

// Longest Common Subsequence
int main()
{
    string X = "XMJYAUZ", Y = "MZJAWXU";

    cout << "The length of LCS is " << LCSLength(X, Y);

    return 0;
}

```  
1. calculate the size of the largest plus of 1's in binary matrix 
   用left，right，top，bottom记录可以达到的最远边界，array[i][j]=min(top[i][j],bottom[i][j],left[i][j],right[i][j])

```c++
#include <stdio.h>
#include <string.h>

// size of binary square matrix
#define N 10

inline int min(int a, int b) { return (a < b) ? a : b; }
inline int minimum(int a, int b, int c, int d) 
{
    return min(min(a, b), min(c, d));
}

// Calculate the size of the largest '+' formed by 1's
int calculateSize(int grid[][N])
{
    // left[j][j] stores maximum number of consecutive 1's
    // present to the left of grid[i][j] (including grid[i][j])
    int left[N][N];
    memset(left, 0, sizeof left);

    // right[j][j] stores maximum number of consecutive 1's
    // present to the right of grid[i][j] (including grid[i][j])
    int right[N][N];
    memset(right, 0, sizeof right);

    // top[j][j] stores maximum number of consecutive 1's
    // present to the top of grid[i][j] (including grid[i][j])
    int top[N][N];
    memset(top, 0, sizeof top);

    // bottom[j][j] stores maximum number of consecutive 1's
    // present to the bottom of grid[i][j] (including grid[i][j])
    int bottom[N][N];
    memset(bottom, 0, sizeof bottom);

    // initialize above matrices
    for (int i = 0; i < N; i++)
    {
        // initialize first row of top matrix
        top[0][i] = grid[0][i];

        // initialize last row of bottom matrix
        bottom[N - 1][i] = grid[N - 1][i];

        // initialize first column of left matrix
        left[i][0] = grid[i][0];

        // initialize last column of right matrix
        right[i][N - 1] = grid[i][N - 1];
    }

    // fill all cells of above four matrix
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            // fill left matrix
            if (grid[i][j] == 1)
                left[i][j] = left[i][j - 1] + 1;

            // fill top matrix
            if (grid[j][i] == 1)
                top[j][i] = top[j - 1][i] + 1;

            // fill bottom matrix
            if (grid[N - 1 - j][i] == 1)
                bottom[N - 1 - j][i] = bottom[N - j][i] + 1;

            // fill right matrix
            if (grid[i][N - 1 - j] == 1)
                right[i][N - 1 - j] = right[i][N - j] + 1;
        }
    }

    // bar stores length of longest + found so far
    int bar = 0;

    // compute longest plus
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
        {
            // find minimum of left(i, j), right(i, j), top(i, j), bottom(i, j)
            int len = minimum(top[i][j], bottom[i][j], left[i][j], right[i][j]);

            // largest + would be formed by a cell that has maximum value
            if (len - 1 > bar)
                bar = len - 1;
        }
    }

    return bar;
}

// main function
int main()
{
    int grid[N][N] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
        { 1, 1, 0, 0, 1, 0, 1, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
    };

    int bar = calculateSize(grid);

    // 4 directions of length 4*bar + 1 for middle cell
    if (bar)
       printf("Largest Plus of 1's has size of %d", 4*bar + 1);

    return 0;
}
```
3. calculate the sum of all elements in sub-matrix in constant time
Given a M*N and two coordinates(p,q) and (r,s) which represents top-left and bottom-right coordinates of a sub-matrix of the given matrix,calculate the sum of all elements present in the sub-matrix in O(1) time.Calculate the sum  of the (p->r, q->s).
$ total=sum[r][s]-sum[r][q-1]-sum[p-1][s]+sum[p-1][q-1]$
```c++
#include <iostream>
using namespace std;

// M x N matrix
#define M 5
#define N 5

int findSubmatrixSum(int mat[M][N], int p, int q, int r, int s)
{
    // pre-process the input matrix such that sum[i][j] stores
    // sum of elements in matrix from (0, 0) to (i, j)
    int sum[M][N];

    sum[0][0] = mat[0][0];

    // pre-process first row
    for (int j = 1; j < N; j++)
        sum[0][j] = mat[0][j] + sum[0][j - 1];

    // pre-process first column
    for (int i = 1; i < M; i++)
        sum[i][0] = mat[i][0] + sum[i - 1][0];

    // pre-process rest of the matrix
    for (int i = 1; i < M; i++)
        for (int j = 1; j < N; j++)
            sum[i][j] = mat[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

    // uncomment below lines to print the sum matrix
    /* 
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            cout << setw(3) << sum[i][j] << " ";

        cout << '\n';
    } */

    // total = sum[r][s] - sum[r][q-1] - sum[p-1][s] + sum[p-1][q-1]
    int total = sum[r][s];

    if (q - 1 >= 0)
        total -= sum[r][q - 1];

    if (p - 1 >= 0)
        total -= sum[p - 1][s];

    if (p - 1 >= 0 && q - 1 >= 0)
        total += sum[p - 1][q - 1];

    return total;
}

// Calculate sum of all elements in a sub-matrix in constant time
int main()
{
    int mat[M][N] =
        {
            {0, 2, 5, 4, 1},
            {4, 8, 2, 3, 7},
            {6, 3, 4, 6, 2},
            {7, 3, 1, 8, 3},
            {1, 5, 7, 9, 4}};

    // (p, q) and (r, s) represents top-left and bottom-right
    // coordinates of the sub-matrix
    int p = 1, q = 1, r = 3, s = 3;

    // calculate sub-matrix sum
    cout << findSubmatrixSum(mat, p, q, r, s);

    return 0;
}
```
4. longest common substring problem(the subset must be consecutive)
5. subset sum problem
   Given a set of positive integers s, is there any non-empty subset whose sum to s
   subset problem can be seen as a special case of Knapsack problem.For each item,there are two possibilities:
    - we include current item in the subset and recurs for remaining items with remaining sum
    - we exclude current item from subset and recurs for remaining items
  The formula is:
    result=find(s-array[i],n-array[i]) if array[i] is selected;else result=find(s-array[i],n)
```c++
#include <iostream>
#include <unordered_map>
using namespace std;

// create a map to store solutions of subproblems
unordered_map<string, bool> lookup;

// Return true if there exists a subarray of array[0..n] with given sum
bool subsetSum(int arr[], int n, int sum)
{
    // return true if sum becomes 0 (subset found)
    if (sum == 0)
        return true;

    // base case: no items left or sum becomes negative
    if (n < 0 || sum < 0)
        return false;

    // construct a unique map key from dynamic elements of the input
    string key = to_string(n) + "|" + to_string(sum);

    // if sub-problem is seen for the first time, solve it and
    // store its result in a map
    if (lookup.find(key) == lookup.end())
    {
        // Case 1. include current item in the subset (arr[n]) and recurse
        // for remaining items (n - 1) with remaining sum (sum - arr[n])
        bool include = subsetSum(arr, n - 1, sum - arr[n]);

        // Case 2. exclude current item n from subset and recurse for
        // remaining items (n - 1)
        bool exclude = subsetSum(arr, n - 1, sum);

        // assign true if we can get subset by including or excluding the
        // current item
        lookup[key] = include || exclude;
    }

    // return solution to current sub-problem
    return lookup[key];
}

// Subset Sum Problem
int main()
{
    // Input: set of items and a sum
    int arr[] = { 7, 3, 2, 5, 8 };
    int sum = 14;

    // number of items
    int n = sizeof(arr) / sizeof(arr[0]);

    if (subsetSum(arr, n - 1, sum))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
```
6. find minimum cuts needed for palindromic partition of a string 
   Given a string,find minimum cuts needed to partition it such that each partition is a palindrome
   - separate the string into two parts
   - recursively find the minimum cuts of required in each sub-sequence
   - do this for each possible position at which the string can be cut, and take the minimum over all of them
7. Find maximum sum of sub-sequence with no adjacent elements
   Given an array of integers,find the maximum sum of sub-sequence of given array where sub-sequence contains no adjacent elements
   The problem would be the same as the Knapsack problem.The item will be divided into selected or not selected.


8. Increasing sub-sequence with maximum sum
   Find a sub-sequence of a given sequence sum is as high as possible and sub-sequence's elements are in sorted order,from lowest to highest.This sub-sequence is not necessarily contiguous,or unique.
   - MSIS:maximum sum increasing sub-sequence,which is a standard variation of Longest Increasing Sub-sequence problem.
   - we include current item in the set(MSIS) if it is greater than the previous element in the set(MSIS) and recurs for remaining items 

   - we exclude current item from the set and recurs for remaining items.
   - Finally,we return maximum sum we get by including or excluding current item,The base case of the recursion would be when no items are left.

9. collect maximum points in a matrix by satisfying given constraints
    Given a M*N matrix where each cell can have value of 1,0,or -1,where -1 denotes a useful cell,collect maximum number of ones starting  from first cell and by visiting only safe cells(i,e 0 or 1).We are allowed to go only left or down if the row is odd else, we can only right or down from current cell
    The formula is:
    $if M[i][j]!=-1,path(i,j)=M[i][j]+\max(path(i,j-1),path(i+1,j)) (if i is odd)|\max(path(i,j+1),path(i+1,j))(is i is even)
    else:
    path(i,j)=0
    $
    where `path(i,j)` calculates the maximum value that can be collected starting from `cell(i,j)`
```c++
int matrix[5][5]={
    {
        1,1,-1,1,1
    },
    {
        1,0,0,-1,,1
    },
    {
        1,1,1,1,-1
    },
    {
        -1,-1,1,1,1
    },
    {
        1,1,-1,-1,1
    }
//the path would be 1-1-0-1-1-1-1-1-1-1-1

}
```
10. MSIS(maximum sum of increasing subs-sequence)(non-dynamic programming)
    
11. Longest  increasing sub-sequence using dynamic programming
    - we include the current item in the set if it is larger than the previous element in LIS and recurs for remaining 
    - we exclude current item from LIS and recurs for remaining 
  