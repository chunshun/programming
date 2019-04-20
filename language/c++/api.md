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
- split string
```c++
void split(const string& s, char c,
           vector<string>& v) {
   string::size_type i = 0;
   string::size_type j = s.find(c);

   while (j != string::npos) {
      v.push_back(s.substr(i, j-i));
      i = ++j;
      j = s.find(c, j);

      if (j == string::npos)
         v.push_back(s.substr(i, s.length( )));
   }
}
```
