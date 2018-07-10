## Tree
1. The tree abstract data type
- T.root()
- T.is_root(p)
- T.parent(p)
- T.num_children(p)
- T.is_leaf(p)
- T.children(p)
- len(T)
- T.is_empty()
- T.positions()
- iter(T)
2. A Tree Abstract Base 
```python
class Tree(object):
    def __init__(self):
        self.left=None
        self.right=None
        self.data=None

root=Tree()
root.data="root"
root.left=Tree()
root.left.data="left"
root.right=Tree()
root.right.data="right"
```