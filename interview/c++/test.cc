#include<iostream>
#include<map>
#include<string>

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



class Vector
{
private:
    /* data */
    double* elem;
    int sz;
public:
    Vector(/* args */int s);
    double& operator[] (int i);
    ~Vector();
};

Vector::Vector(/* args */int i)
{
}

double &Vector::operator[](int i){
    return elem[i];
}

Vector::~Vector()
{
}

int main(int argc, char const *argv[])
{
    struct R a;

    // Arr arr=new Arr(1,2);
    

    a.x=100;
    a.y=9;
    map<string,int> stu;
    stu.insert(pair<string,int>("chunshun",100));
    stu.insert(pair<string,int>("zhang",100));
    for(const auto [k,v]:stu)
    {
        cout<<"key:"<<k<<"\t"<<"value:"<<v<<endl;
    }

    auto [c,b]=a;
    cout<<"unpack is :"<<c<<"\t"<<b<<endl;
    cout<<a.x<<endl;
    cout<<"hello"<<endl;
    return 0;
}
