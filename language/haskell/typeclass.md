A typeclass is a sort of interface that defines some behavior. typeclass是一种定义某些行为的接口。like `Ord`,`Eq`
```haskell
(==) :: (Eq a) => a -> a -> Bool  
```
1. `Eq`: is used for types that support equality testing
2. `Ord`: is for types that have an ordering.
3. `Bounded`:Bounded members have an upper and a lower bound.
4. `Enum`: members are sequentially ordered types — they can be enumerated.

