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
string s(10,'-');
//----------
```
- `p++` vs `++p`  
A `++p` returns a reference to `p`,whereas `p++` must return a copy of `p` holding the old value.Thus,for more compilcated iterators,`++p` is likely to be more efficient than `p++`.
- `iterator` operations
```c++
advance(it,3)
// iterator it=it+3
int x=distance(it1,it2)


iterator it2 =next(it1,3)
// it1 must be a forward iterator
iterator it3 =prev(it1,3
// it1 must be at least a bidirectional iterator

```
- `for_each`
  In C++, you can use `for_each` in all the containers.
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
- `string` to `int`:`std::stoi`
- fill the container start from int A
```c++
vector<int> v(9);
std::iota(v.begin(), v.end(), 80);
```
- Move iterator
- Function Objects
- Function Adapters
    A function adapter takes a function as argument and returns a function object that can be used to invoke the original function.The `bind` and `mem_fn` adaptors do argument binding,also called `Currying or Partial evaluation` 
- Instantiation
  - Template instantiation :From a template function and a set of template arguments,a function needs to be generated.This process is commonly called `template instantiation`

# The standard library
- Iterators provide the mechanism to make standard algorithms generic
- `initializer-list`:does not support a subscript operator.If you want to use `[]` rather than `*`,subscript a pointer.
-  Generalized numeric algorithms
   - `accumulate`
   - `partial_sum` and `adjacent_difference`:inverse of each other and deal with the notion of incremental change.

# Class constructors
- `()` vs `{}`
  - `()`:use *value initialization* if the parameters are empty,or *direct initialization* if non-empty.
  - `{}`:use *list initialization*,which implies *value initialization*  if the braces are empty,or `aggregate initialization` if the initialized object is an aggregate.

# Iterators
Iterators are the glue that ties Standard Library algorithms and their data
- Iterator categories
  - input iterator:`istream`
  - output iterator:`ostream`
  - forward iterator
  - Bidirectional iterator
  - random access iterator
- curried:`bind`
```c++
double cube(double);
auto cube2 = bind(cube,2);
```
- File streams
  - stream modes
    - `ios_base::app`:append
    - `ios_base::ate`:at the end
    - `ios_base::binary`:binary mode;beware of system-specific behavior
    - `ios_base::in`:for reading
    - `ios_base::out`:for writing
    - `ios_base::trunc`:truncate the file to 0 length
- String streams
  - istringstream
  - ostringstream
  - stringstream
- Stream iterators
  - 
>>>>>>> 9a57110dafe701445ee3f8f2493d571e5f2e075f
