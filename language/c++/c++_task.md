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
- string multiply
```c++
string s{10,'-'};
//----------
```
- `p++` vs `++p`  
A `++p` returns a reference to `p`,whereas `p++` must return a copy of `p` holding the old value.Thus,for more compilcated iterators,`++p` is likely to be more efficient than `p++`.
- `iterator` operations
```c++
q=advance(it,3)
// iterator q=it+3
int x=distance(it1,it2)


iterator it2 =next(it1,3)
// it1 must be a forward iterator
iterator it3 =prev(it1,3
// it1 must be at least a bidirectional iterator

```
- reverse iterator
```c++
v.rbegin()[3]=-3;

```
- Insert iterators
  - `insert_iterator`:insert before the element pointed to using `insert()`
  - `front_insert_iterator`:inserts before the first element of a sequence using `push_front`
  - `back_insert_iterator`:insert after the last element of the sequence using `push_back`
- `std:: advance` vs `std::next`
  - `std::advance`:
    - returns nothing 
    - modify its argument
    - works on input iterator or better(or bit-directional iterator if a negative distance is given)
  - `std::next`
    - leaves its argument unmodified
    - returns a copy of the argument,advanced by the specified amount
    - works on forward iterators or better(or bi-directional iterators if a negative distance is given)
- 