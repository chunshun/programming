- remove duplicates in the collection
```c++
#include <algorithm>

vector<int> v{1,2,4,5,2,4};
std::sort(v.begin(),v.end());
auto last=std::unique(v.begin(),v,end());
v.erase(last,v.end());
for(auto i:v)
{
  cout<<i<<"\t";
}
```
- use `std::transform` like the `map`
```c++
vector<int> v{1,2,4,5,2,4};
//2	4	8	10	4	8
std::trandform(v.begin(),v.end(),[](int x){return x+x;};

```
