```c++
string s {"abccdddee"};
auto p=std::unique(s.begin(),s.end());
cout<<s<<p-s.begin();       
// abcdeddee5
```
- the `map` in C++ will be  in ascending order according to the values of the key default.