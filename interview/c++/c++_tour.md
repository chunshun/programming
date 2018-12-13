- defining multiple functions with the same name is known as *function overloading* and is one of the essential parts of generic programming
- types,variables,and arithmetic
    - A *declaration* is a statement that introduces an entity into the program.It specifies a type for the entity
        - A *type* defines a set of possible values and a set of operations(for an object)
        - An *object* is some that holds a value of some type
        - A *value* is a set of bits interpreted according to a type
        - A *variable* is a names object
- initialization
```c++
double d=1.2;
double d {1.2};

vector<int> v {1,2,4};

auto x=1;
auto c=2;
auto x{1.0};
// auto x=1
//narrow conversion

```
- `const`:meaning not to change the value.**This is used primarily to specify interface so that data can be passed to functions using pointers and references without fear of it being modified**
- `constexpr`:meaning to run evaluated at **compile** time."This is used primarily to specify constants, to allow placement of data in read-only memory (where it is unlikely to be corrupted), and for performance."
- In a declaration,the unary suffix `&` means "reference to".A reference is similar to a pointer,except that you don't need to use a prefix `*` to access the value referred to by the reference.Also,a reference cannot be made to refer to a different object after its initialization.
- `nullpr`:the null pointer
-  A reference and a pointer both refer/point to an object and both are represented in memory as a machine address.However,the language rules for using them differ.**Assignment to a reference does not change what the reference refers to but assigns to the referenced object**.To access the value of a pointer,then use the `*` operator, but that is implicitly(automatically) done for the reference.
```c++
int x =10;
int y=8;
int &r1=x;//r1's position is  88,refer the value 10
int &r2=y;//r2's position is 99,refer the value 8
r1=r2;//r1's position  is not changed,but the refer value is changed from 10 to 8

```
- prefer immutable data,use `nullpr` rather than `0` or `NULL`
  

- user-defined types
    - structures
      - there is no fundamental difference between a *struct* and a *class*;a *struct* is simply a *class* with members *public* by default.
    - classes
    - unions
      - *variants*: A *variant* stores a value of one of a set of alternative types.A *variant<Node \*,int>* can hold either a *Node\** or an int.
        ```c++
        struct Entry{
            string name;
            variant <Node *,int>v;
        };

        void f(Entry* pe){
            if (holds_alternative<int>(pe->v))
                cout<<get<int>(pe->v);

        }
        ```
    - enumerations
      - enumerations are used to represent small sets of integer values.
        ```c++
        enum class Color {red, blue, yellow};
        enum class Traffic_color {light, red, blue};

        Color col=Color::red;
        Traffic_color red =Traffic_color::red;

        ```
        also, enum plain class like C.
        ```c++
        enum Color {red,green,blue}
        ```
The new operator allocates memory from an area called the *free store*(also known as *dynamic memory* and *heap*).Objects allocated
on the free store are independent of the scope from which they are created and live until they are destroyed using the *delete* operator.
 
- Modularity
  - declaration: in general,the *.h* file contains the definition,which is your data and all your method declarations. The idea is to keep signatures and members in the header file.
  - implementation:to help the compiler ensure consistency,the `.cpp` file providing the implementation of *Vector* will also include the *.h* file providing its interface.
  ```c++
    Vector::Vector(int s):elem{new double[s],sz{s}}
    {

    }

    double &Vector::operator[](int i)
    {
        return elem[i];
    }

    int Vector::size()
    {
        return sz;
    }
  ```
  ```c++
    // This example illustrates explicit initialization
    // by constructor.
    #include <iostream>
    using namespace std;

    class complex {
    double re, im;
    public:

    // default constructor
    complex() : re(0), im(0) { }

    // copy constructor
    complex(const complex& c) { re = c.re; im = c.im; }

    // constructor with default trailing argument
    complex( double r, double i = 0.0) { re = r; im = i; }

    void display() {
        cout << "re = "<< re << " im = " << im << endl;
    }
    };

    int main() {

    // initialize with complex(double, double)
    complex one(1);

    // initialize with a copy of one
    // using complex::complex(const complex&)
    complex two = one;

    // construct complex(3,4)
    // directly into three
    complex three = complex(3,4);

    // initialize with default constructor
    complex four;

    // complex(double, double) and construct
    // directly into five
    complex five = 5;

    one.display();
    two.display();
    three.display();
    four.display();
    five.display();
    }

  ```
  - module vs headers
    - A module is compiled once only (rather than in each translation unit in which it is used)
    - Two modules can be imported in either order without changing their meaning.
    - If you import something into a module, users of your module do not implicitly gain access to(and are not bothered by) what you imported:imported is not transitive
  - namespaces
    - namespaces are primarily used to organize larger program components,such as libraries.They simplify the composition of a program out of separately developed parts
- Error-handling Alternatives
  - Throwing an exception is not the only way of reporting an error that cannot be handled locally.A function can indicate that it cannot perform its allotted task by:
    - throwing an exception
    - somehow returns a value indicating failure
    - terminating the program(by invoking a function like *terminate(),exit(),abort()*)

  - static_assert vs assert
    - static_assert:exceptions report found at compile time,`static_assert(4<=sizeof(int),"integer are too small")`.The most important uses of `static_assert` comes when we make assertions about types used as parameters in generic programming.
    - assert:error can be found at run time.Used un the debug mode
  - function arguments and return values
    - Given the importance of passing information to and from functions,it is not surprising that there are a variety of ways of doing it.Key concerns are:
      - Is an object copied or shared?
      - Is an object is shared,is it mutable?
      - Is an object moved,leaving an "empty object" behind?
    - The default behavior for both argument passing is "copy",but some copies can implicitly be optimized to moves.
    - Argument passing
      - By default we copy("pass-by-value") and if we want to refer to an object in the caller's environment,we use a reference("pass-by-reference").When we care about performance,we usually pass small values by-value and larger ones by-reference.Here "small" means "something that's cheap to copy".If we want to pass by reference for performance reasons but don't need to modify the argument,we pass by *const* reference in the *sum()* example.
    - Value Return
      - A local variable disappears when the function returns,so we should not return a pointer or reference to it.
        ```c++
        int &bad(){
            int x;
            return x
            //bad,return a reference to the local variable x
        }
        ```
