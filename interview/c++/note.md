# 使用`getchar`和`putcahr` 输入和输出字符
getchar可以识别换行符
# 常用`math`函数
1. `fabs` 函数
2. `floor`和`ceil`函数
3. `log(x)`自然数对数为底
4. `sin(doublen x),cos(double x),tan(double x)`
5. `asin(double x)`
6. `round(double x)`
# `break`和`continue`语句
# memset 对数组中每一个元素赋相同的值
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
# `string.h`****
1. `strlen()`
2. `strcmp(s1,s2)`
3. `strcmp(s1,s2)` and `strcat(s1,s2)`
4. `sscanf()` and `sprintf()`