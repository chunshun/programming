#include <iostream>
#include <vector>
#include <istream>

using namespace std;


class Container {
public:
     virtual double& operator[](int) = 0;     // pure virtual function
     virtual int size() const = 0;            // const member function (§4.2.1)
     virtual ~Container() {}                  // destructor (§4.2.2)
}






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

    for(auto item:generate_vector(cin))
    {
        cout<<item<<endl;
    }
    return 0;
}

