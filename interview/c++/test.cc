#include<iostream>
using namespace std;

struct R
{
    /* data */
    int x;
    int y;

};


class Arr
{
private:
    /* data */
    int x,y;
public:
    Arr(/* args */int x,int y):x{x},y{y}{};
    void pr();
    ~Arr() { };
};


int main(int argc, char const *argv[])
{
    struct R a;

    Arr arr=new Arr(1,2);

    a.x=100;
    a.y=9;
    cout<<a.x<<endl;
    cout<<"hello"<<endl;
    return 0;
}
