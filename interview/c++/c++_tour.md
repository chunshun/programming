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
      - Structed binding
  ```c++
  struct Entry{
    string name;
    int value;
  };
  Entry read_entry(istresm &is)
  {
    string s;
    int i;
    is>> s >>i;
    reurn {s,i};

  }
  auto e=read_entry(cin);
  cout<<e.name<<"\t"<<e.value<<endl;
  ```
  Here,`{s,i}` is used to construct the `Entry` return value.To unpack the structure like that.
  ```c++
  auto [n, v]=read_entry(is);


  map<string,int> m;
  for(const auto [key,value]: m)
  {
    cout<<key<<"\t"<<value<<endl;

  }

  ```
    - class binding
      - there must be the same number of names defined for the binding.
    ```c++
    complex<double> z={1,2};
    auto [re,im]=z+2;


    ```
    - distinguish between declarations(used as interfaces) and definitions(used as implementations)(separate into two files)
    - avoid non-inline function definitions in headers;
- classes
  - concrete class
    - A constructor can be invoked without an argument is called a default constructor.By defining a default constructor to eliminate the possibility of un-initialized variable of that type.
    - A container is an object holding a collection of elements.
    - The container,it does have a fatal flaw: it allocates elements using new but never de-allocates them.C++ is not guaranteed that one is available to make unused memory available for new objects.
    - initializing containers :
      - initializer-list constructor:Initialize with a list of elements.
      - push_back():Add a new element at the end of(at the end of) the sequence.
      ```c++
      class Vector{
        public:
          Vector<std::initializer_list>(double);
          void push_back(double);
      }
      ```
      - the `initializer-list` used to define the initializer-list constructor is a standard-library type known to the compiler:when we use a `{}` list,such as `{1,2,3,4}`,the compiler will create an object of type `initializer_list` to give to the program.
      ```c++
      Vector v ={1,2,5};
      ``` 
  - abstract class
    - the word `virtual` means may be redefined later in a class derived from this one.A function declared "virtual" is called a *virtual function*
    ```c++
    class Container {
        public:
            virtual double& operator[](int) = 0;     // pure virtual function
            virtual int size() const = 0;            // const member function (§4.2.1) , the curious =0 means the function is *pure virtual* function,that is, some class derived from Container must define the function.Thus,it is not possible to redefine an object that is just a *Container*
            virtual ~Container() {}                  // destructor (§4.2.2)
        }
    ``` 
    - A `Container` can only serve as the interface to a class that implements its `operator[]()` and `size()` functions.A class with a pure virtual function is called a *abstract class*
    - **You cannot create an object of an abstract class type; however, you can use pointers and references to abstract class types.** The abstract class doesn't have any data to initialize and doesn't have constructor.The abstract class defines only an interface and no implementation.
  ```c++
  class Vector_container:public Container // the `:` can be read as "it derived from" or "is subtype of".
  {
    public:
        Vector_container(int s) : v(s) { }   // Vector of s elements
        ~Vector_container() {}
        double& operator[](int i) override { return v[i]; }
        int size() const override { return v.size(); }
    private:
        Vector v;
    }
  ``` 
    - A class that provides the interface to a variety of other classes is often called a *polymorphic type*.

  - virtual function
    - virtual function table:For the compiler to convert the name of pointers to functions.The table is usually called the *virtual function table* or simply the *vbtl*
  - class hierarchies
    - A class hierarchy is a set of class 
    - A virtual destructor is essential for an abstract class because an object of a derived class is usually manipulated through the interface provided by its abstract base class.
    - Benefits from hierarchy
      - **Interface inheritance**:An object of a derived class can be used wherever an object of a base class is required.That is,the base class acts as an interface for the derived class.
      - **Implementation inheritance**:A base class provides functions on data that simplifies the implementation of derived class.
      ```c++
      enum class Kind{circle,triangle,simley};
      
      Shape* read_shape(is_stream& is)
      {
        switch(k)
        {
          case Kind::circle:
            return new Circle{p,r};
          case Kind::triangle:
            return new triangle{p1,p2,p3};
          case Kind::simley:
            Smiley* ps = new Smiley{p,r};
            ps−>add_eye(e1);
            ps−>add_eye(e2);
            ps−>set_mouth(m);
            return ps;
        }
      }
      ```
    - the aim is to simplify the class hierarchy and organize the data,and more
  - hierarchy navigation
    - However, what can we do if we want to use a member function that is only provided by a particular derived class.The function with `virtual` is written in different derived class.Use the `dynamic_cast` methods

  - Avoiding resource leaks 
  ```c++
  void user(int x)
  {
    Shape* p = new Circle {Point{0,0},10}
    if(x<0)
    {
      throw Bad_x{};
      //potential leaks
    }
    if(x==0) return ;
    //potential leaks
    delete p;
  }
  ```
  - One simple solution  is to use a standard library `unique_ptr` rather than a naked pointer when deletion is required.
  ```c++
  class Simply
  {
    private:
      vector<uniqiue_ptr<Shape>> eyes;
      unique_ptr<Shape> mouth;

  }

  ```

- Essential Operations
  - There are five situations in which an object can be copied or moved.
    - As the source of an assignment
    - As an object initializer
    - As a function argument 
    - As a function return value
    - As an exception
    ```c++
    class X
    {
        public:
            X(sometype);
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
    ```
    move constructor:A move constructor enables the resources owned by an right-value object to be moved into an left-value without copying.
  - container operations
  ```c++
  for(auto p=c.begin();p!=c.end();++p)
  {
    *p=0;
  }
    - the standard library `unsorted_map<K,V>` is a hash table with `K` as the key type and `V` as the value type.
  ```
- Templates
  A template is a class or a function that we parameterize with a set of type or values.We use template to represent ideas that are best understood as something general from which we can generate specific types and functions by specifying arguments,such as `vector`'s element type of `double`
  - Parameterized Types
    - Using `class` to introduce a type parameter is equivalent to using `typename`, and in older code we often see `template<class T>` as the prefix.

- Library Overview
  - standard-library components
    - run-time language support
    - The C standard library 
    - strings
    - Support for regular expression matching
    - I/O streams in an extensible framework
    - A framework of containers and algorithms(such as `sort`,`find` and `merge`)
    - Support for concurrent programming,including `threads` and locks
    - Parallel version of the most STL algorithms and some numerical algorithms
    - Utilities to support template meta-programming(STL-style generic programming such as `pair`,general programming such as `variant` and `optional`)
    - Small pointers for resource management, such as `shared_ptr`,`unique_ptr`
    - Special containers such as `array`,`bisect`,and `tuple`.
    - Suffixes for popular units,such as `ms` for milliseconds and `i` for imaginary.
  - Strings
    ```c++
    auto s="cat"s;  //init s as type std::string
    auto t="cat"; //init t as const char*,a C-style string 
    ```
    - string implementation
      - *short string optimization*:only the short string values are kept in the *string* object itself and only longer strings are places on the free store.
    - string views  
      - A `string_views` gives access to contiguous sequence of characters.`string_views:{begin(),size()}`
     ```c++
    string catt(string_view v1,string_view v2)
    {
        cout<<v1.length()<<"\t"  <<v2.length()<<endl;
        string res;
        res.resize(v1.length()+v2.length());
        char* p=&res[0];
        for(auto c:v1)
        {
            *p++=c;
        }
        cout<<"before\t"<<res<<"\n";
        copy(v2.begin(),v2.end(),p);
        cout<<"after\t"<<res<<"\n";
        return res;
    }
    //string t="chunshun";
    //auto s=catt({&t[0],3},"string");===>chustring
    //auto  t=catt("ch"sv,"zh"sv); the `sv` suffix means the "string view"
    ```
      - It can be used for character sequences managed in many different ways.
      - No temporary `string` arguments are created for C style string arguments.
      - Can easily pass substrings.
      - The string_view is read-only view of its characters.
    - Regular expression
      - `regex_match`:match a regular expression against a string(of known size).
      - `regex_search`:search for a string that matches a regular expression in an (arbitrary long) of stream data.
      - `regex_replace`:search for strings that match a regular expression in an(arbitrary long) stream of data and replace them.
      - `regex_iterator`:Iterator over matches and sub_matches.
      - `regex_token_iterator`:Iterator over non-matches.
    - Using iterators or `[]` rather than `at()` when you want to optimize speed.
    - Using `at()`rather than iterators or `[]` when you want range checking.
- Input and output
  - Input
    - By default,a whitespace character,such as a space or a newline, terminates the read
    - I/O of User-Defined Types
    - 