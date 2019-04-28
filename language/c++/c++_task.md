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
