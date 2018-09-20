# 使用`getchar`和`putcahr` 输入和输出字符
getchar可以识别换行符
# 常用`math`函数
1. `fabs` 函数
2. `floor`和`ceil`函数
3. `log(x)`自然数对数为底
4. `sin(doublen x),cos(double x),tan(double x)`
5. `asin(double x)`
6. `round(double x)`
# memset 对数组中每一个元素赋相同的值
# `break`和`continue`语句
添加`string,.h`头文件，只赋值0，-1，其他使用`fill`  函数

```c++
#include <string.h>
#include "stdio.h"
using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
int a[8];
memset(a,0,sizeof(a));
// memset(array_name,value,sizeof(array_name))
for(int i=0;i<sizeof(a)/sizeof(*a);i++){

    printf("%d\t",a[i]);
}

return 0;
}



```
# 字符数组
1. `puts` and `gets`
```c++

#include <stdio.h>
main(int argc, char const *argv[])
{
    char str1[10];
    char str2[5][10];
    gets(str1);

    for (int i = 0; i < 3; i++)
    {
        gets(str2[i]);
            
    }
    return 0;

}
```
# `string.h`
1. `strlen()`
2. `strcmp(s1,s2)`
3. `strcmp(s1,s2)` and `strcat(s1,s2)`
4. `sscanf()` and `sprintf()`
   `scanf(str,"%d",&n)`:string+scanf
   `sprintf`:string+printf
# 函数引用
不使用指针，修改传入参数的目的，引用不产生副本，对引用变量的操作就是对原变量的操作
```c++
int x=0;
int &r=x;

int *p;
p=&x;
```
引用是产生变量的别名， 因此常亮不可使用引用

## STL 
### vector
`vector`的访问
- 通过迭代器访问
```c++
vector<typename>::iterator it;
vector<int> vi(5,1);
vector<int>::iterator it=vi.begin();
for(int i=0;i<5;i++){
    cout<<*(it+i);
}
```
遍历容器
```c++

for(vector<int>::iterator it=vi.begin();it!=vi.end();it++){
    cout<<*it;
}
```
`push_back`,`pop_back`,`size`,`clear`,`insert(vector<typename>::iterator it,x)`,`erase(it)`or `erase(first,last)`
- `vector`的常见用途
  - 数组
  - 邻接矩阵存储图
### set
- `set`的定义
  `set<typename> name;`除开`vector`和`string`之外的STL容器都不支持`*(it+i)`的访问方式
- `set`常用函数
  - insert(x)
  - find(value)=>set<typename>::iterator it
  - erase()与vector<typename>::erase 同
  - size()
  - clear()
- `set`的常见用途
  - 主要用途是自动去重并按升序排列
  - multiset,unordered_set
### string
- `string`的定义
  `string str="chunshun"`
- 访问
  `str[i]`,但如果只要输出整个字符串，使用`cin`和`cout`,或者`str.c_str()`转换为字符数组
- 通过迭代器访问
- 常用函数
    - operator+=
    `string str1="abc",str2="cde",str3;str3=str1+str2;str3+=str2
    - compare operator
    like `==`,`!=`,`>`
    - `length()`/`size()`
    - `insert(pos,string)` or  `insert(it,it2,it3)`
    - `erase()` or `erase(pos,length)`
    - `clear()`
    - `substr(pos,len)`
    - `string::npos`
    - `find()`若无，返回`string::npos`
    - `replace(pos,len,str2)`
### map
`map`可以将任何基本类型映射到任何基本类型，`map`中的键是唯一的。
- 通过下标访问
- 通过迭代器访问
  `map<typename1,typename1>::iterator it `
  `for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++){
      cout<< it->first<< it->second;
  }
  it->first:key,it->second:value
- map常用函数
    - `find()`
    - `erase()`
    - `size()`
    - `clear()`
- `map`的常见用途
  - 如需要建字符（或字符串）与整数之间映射
  - 判断大整数或者其他类型数据是否存在的题目，可以把`map`当`bool`数组用
  - 字符串和字符的映射
  - 如果一个键需要对应多个value,使用multimap
### queue
- definition 
  ` queue<typename> name `
- 访问
  `front()`和`back()`来访问队首和对尾
- 常用函数
  - `push()`
  - `front()`,`back()`
  - `pop()`
  - `empty()`
  - `size()`
- 常见用法
  实现广度优先搜索树时，实现队列
### priority_queue
- priority_queue
  `priority_queue<typename> name`
- 访问：`top()`
- 常用函数
    - `push()`
    - `pop()`
    - `top()`
    - `empty()`
    - `size()`
- 优先级的设定
  - 基本数据类型的优先级设置
  `priority_queue<int> q; priority_queue<int,vector<int>,less<int>>q;`
  `less<int>`表示数字大的优先级越大，而`greater<int>`表示数字小的优先级越大
### stack
- definition 
  `stack<typename> name`
- stack元素的访问（top）
- 常用函数
  - `push()`
  - `pop()`
  - `top()`
  - `empty()`
  - `size()`
### pair
- definition
  `pair<typename1, typename2> name`
  or `make_pair("chunshun",0.5);`
- `pair`中元素的访问
  `name.first`,`name.second`
- 常见用途
  - 用来代替二元结构及其构造函数
  - 作为`map`的键值对进行插入
    `mp.insert(make_pair("chunshn",1))`

## algorithm
- `max()`,`min()`,`abs()`
  `max`和`min`参数必须是两个
- `swap(x,y)`
- `reverse(it1 ,it2)`
  `int a[]={1,234,5,5,0};reverse(a,a+4);`
```c++
string str="chunshun";
reverse(str.begin()+2,str.begin()+4);
```
- `next_permutation()`
  给出一个序列在全排列中的下一个序列
  ` int a[]={1,2,3};next_permuation(a,a+3);`

- `fill()`
  `int a[5];fill(a,a+5,223 );`
- `sort()`
  - `sort(pos_start,pos_end+1,cmp_function(optional))`
  - `cmp`函数：
```c++
bool cmp(int a, int b ){
    return a>b;
}
bool cmp2(node a,node b){
    if(a.x!=b.x) return a.x>b.x;
    else return a.y<b.y;
}
```
- `lower_bound()`and `upper_bound()`
        - `lower_bound(first,last,value)`:return the first index which no less than the value 
        - `upper_bound(first,last,value)`:return the first index which is greater than the value

## hash
将元素通过一个函数转换为整数，使得该整数可以尽量唯一的代表这个元素
## recursion
-  全排列(full permutation)
- backtracking(回溯)
## two points
- to find if there exits a[i]+a[j]==target in a sorted array.
```py
S=list(range(10))
i,j=0,len(S)-1
target=8
while i<j:
    print(i,j)
    sm=S[i]+S[j]
    if sm==target:
        print('----',i,j)
        i+=1
        j-=1
    else:
        if sm<target:
            i+=1
        else:
            j-=1
    
```
-two sorted sequence merge problem
## 随机选择算法
- 随机数的生成（quick-sort)
- k-max element
  
## 组合数
- $n!$中0的个数
- 计算
  - $C(n,m)=C(n-1,m)+C(n-1,m-1)$,recursion or dynamic programming 
  - 定义计算：
```c++
for(int i=1;i<=m;i++){
  ans=ans*(n-m-i)/i;
}
return ans;

```