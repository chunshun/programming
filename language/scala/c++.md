# c++
```c++
    std::vector<int> v1{0, 1, 2, 3, 40, 40, 41, 41, 5};
    auto i2 = std::adjacent_find(v1.begin(), v1.end(), std::greater<int>());
    if (i2 == v1.end())
    {
        std::cout << "The entire vector is sorted in ascending order\n";
    }
    else
    {
        std::cout << "The last element in the non-decreasing subsequence is at: "
                  << std::distance(v1.begin(), i2) << '\n';
    }
    // The last element in the non-decreasing subsequence is at: 7
```
