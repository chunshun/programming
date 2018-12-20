
class Vector
{
private:
    /* data */
    double *elem;
    int sz;
public:
    Vector(/* args */int s);
    double& operator[](int i);
    int size();
    ~Vector();
};

