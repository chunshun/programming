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