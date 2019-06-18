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


