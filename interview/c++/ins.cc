#include <iostream>
#include <vector>
#include <istream>

using namespace std;

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

