```c++
string s {"abccdddee"};
auto p=std::unique(s.begin(),s.end());
cout<<s<<p-s.begin();       
// abcdeddee5
```
- the `map` in C++ will be  in ascending order according to the values of the key default.
- `sort` the vector reverse
```c++
std::sort(v.rbrgin(),v.rend());

```
- `max` multi-val
```c++
std::max({1,2,3});


```
- `rbegin()`
```c++
vector<int> v{1,3,4,5};
auto i=v.rbegin()[1];
 //refers to the *(v.rbegin()+1)
 
```
