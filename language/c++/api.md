```c++
std::find=>bool
std::binary_find()=>bool
// std::generate

int gen(){
    static int i=0;
    return ++i;
}
int i;
std::vector<int> v(10);
std::generate(v.begin(),v.end(),gen);
vector<int>::iterator i1;
for (i1 = v.begin(); i1 != v.end(); ++i1) {
    std::cout << *i1 << " ";
    }

std::merge: merge two sorted lists

```