- local variable
```python
def fun():
    x = 1

    def f():
        nonlocal x
        x += 1

    f()
    print(x)

fun()
# 2

```
- get the area of the island
```python 
def get_area(i, j):
      if not 0 <= i < len(nums) or not 0 <= j < len(nums[0]) or not nums[i][j]:
          return 0
      nums[i][j] = 0
      return (
          1
          + get_area(i + 1, j)
          + get_area(i - 1, j)
          + get_area(i, j + 1)
          + get_area(i, j - 1)
      )
```
- priority_queue
```python
from queue import PriorityQueue
pq=PriorityQueue()
pq.put((1,2))
pq.get()
pq.empty()
```