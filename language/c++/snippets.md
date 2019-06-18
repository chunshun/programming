```c++
// unique
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
- split strings by delimiter
```c++

// suffix in c++
auto s="chunshun";
//s:char *
#include <chrono>
auto s="chunshun"s;
// s:string

```
vector<string> split(string &s, char delimiter)
{
    if (s.empty())
        return {};
    vector<string> ans;
    int i = 0, j = 0;
    for (; i < s.length(); ++i)
    {
        if (s[i++] != delimiter)
            continue;
        ans.push_back(s.substr(j, i - j));
        j = i;
    }
    // cout << s.substr(j, i - j) << endl;
    if (i - j > 0)
        ans.push_back(s.substr(j, i - j));
    return ans;
}
```
