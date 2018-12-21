#include <iostream>
#include <vector>
#include <istream>

using namespace std;


class Container {
public:
     virtual double& operator[](int) = 0;     // pure virtual function
     virtual int size() const = 0;            // const member function (§4.2.1)
     virtual ~Container() {}                  // destructor (§4.2.2)
};


class X
{
    public:
        X();
        // ordinary constructor 
        X(const X&);
        //copy constructor
        X(X&&);
        //move constructor
        X& operator=(const X&);
        //copy assignment
        X& operator=(X&&);
        //move assignment
        ~X();
};




std::vector<double> generate_vector(istream& is)
{
    std::vector<double> v;

    for (double d;is>>d;)
    {
        v.push_back(d);
    }
    return v;
}

int main(int argc, char const *argv[])
{
    /* code */

    vector<unique_ptr<Container>> p;
    for(auto item:generate_vector(cin))
    {
        cout<<item<<endl;
    }
    // throw out_of_range("list oute of range");
    return 0;
}

