#include "Vector.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a = 1;
    int b = 4;
    std::swap(a, b);
    cout << "a:" << a << "\t" << b << endl;
    cout << sizeof(int) << endl;
    static_assert(3 < sizeof(int), "size is small");
    // assert(3==sizeof(int));
    return 0;
}
