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
- use `copy_if` like `filter`
```c++
vector<int> vv(v.size());
auto it=std::copy_if(v.begin(),v.end(),vv.begin(),[](int x){return x%2==0;};
vv.resize(std::distance(vv.begin(),it ));

for(auto i:vv)
{
  cout<<i<<" ";
}
```
