```python
# kadane algorithm
#reference:https://en.wikipedia.org/wiki/Maximum_subarray_problem#Kadane's_algorithm
def maxSubArray(nums):
     """
     :type nums: List[int]
     :rtype: int
     """
     for i in range(1, len(nums)):
            if nums[i-1] > 0:
                nums[i] += nums[i-1]
     return max(nums)

```
# Sliding window algorithm
```c++
/* 给定一个整数数组，计算长度为 'k' 的连续子数组的最大总和。 */
void fun(vector<int> v, int k)
{
    int sum = 0;
    for (auto i = 0; i != k; ++i)
        sum += v[i];
    auto current_sum = sum;
    for (auto i = k; i!= v.size(); ++i)
    {
        current_sum += (v[i] - v[i - k]);
        sum = max(current_sum, sum);
    }
    cout << sum;
}

fun({1, 2, -1, 4,100}, 2);
// 104 

// https://leetcode-cn.com/classic/problems/grumpy-bookstore-owner/description/
/* 
g[i]==0 的c[i]的base显然满足要求，再找最大长度为K的子列和
 */
```
```python
def fun(c,g, k):
    a=[c[i]*g[i] for i in range(len(c))]
    b=[c[i] for i in range(len(c)) if not g[i]]
    base=sum(b)

    tmp=sum(a[:k])
    ans=tmp
    for i in range(k ,len(c)):
        tmp+=(a[i]-a[i-k])
        ans=max(tmp,ans)
    print(base+ans)
```
- to check if two single link-lists intersected
Note that the single link list node only has one *next*,which means that the shape must be like *y*,traverse the two lists and check the last two nodes whether is **equal**
```c++
bool isIntersect(Node *h1, Node *h2)
{
    if (!h1 && !h2)
        return true;

    while (!h1)
        h1 = h1->next;
    while (!h2)
        h2 = h2->next;
    return h1 == h2;
}
```
- find the intersected node of two link lists
Let the longest lists go first(l1-l2),and then go together,the first equal node is the answer.
```c++
int l1 = length(h1);
    int l2 = length(h2);
    if (l1 < l2)
        swap(h1, h2);

    int cut = l1 - l2;
    for (int i = 0; i < cut; ++i)
    {
        h1 = h1->next;
    }
    while (h1 != h2)
    {
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1;
···
- edit distance
/* 
calculate the  distance by three methods:insert/remove/replace

Input:   str1 = "geek", str2 = "gesek"
Output:  1
We can convert str1 into str2 by inserting a 's'.

Input:   str1 = "cat", str2 = "cut"
Output:  1
We can convert str1 into str2 by replacing 'a' with 'u'.

Input:   str1 = "sunday", str2 = "saturday"
Output:  3
Last three and first characters are same.  We basically
need to convert "un" to "atur".  This can be done using
below three operations. 
Replace 'n' with 'r', insert t, insert a
*/

```c++
int editDistDP(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int dp[m + 1][n + 1];

    // Fill d[][] in bottom up manner
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i == 0)
                dp[i][j] = j; // Min. operations = j

            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i

            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // If the last character is different, consider all
            // possibilities and find the minimum
            else
                dp[i][j] = 1 + min(dp[i][j - 1],      // Insert
                                   dp[i - 1][j],      // Remove
                                   dp[i - 1][j - 1]); // Replace
        }
    }

    return dp[m][n];
}
```