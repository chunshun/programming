```c++
string s {"abccdddee"};
auto p=std::unique(s.begin(),s.end());
cout<<s<<p-s.begin();
// abcdeddee5

```