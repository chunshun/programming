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
