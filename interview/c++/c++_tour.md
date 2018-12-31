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
  - An assignment uses a copy or move assignment operator.
  - Conversations
    - A constructor taking a single argument defines a conversation from its argument type.
    - Copy and Move
      - The default meaning of copy is memberwise copy:copy each member.
      ```c++
      void test(complex z1)
      {
          complex z2 {z1};
          complex z3;
          z3=z2;
      }
      ```
      For some sophisticated concrete types,memberwise copy is not the right semantics for copy;for abstract types it almost never is.
      - Copying containers
        - When a class is a *resource handle*-that is,when the class is responsible for an object accessed through a pointer- the default memberwise copy is typically a disaster.The default copy,such as `Vector` would leave a copy of `Vector` referring to the same elements as the original.
        - Copying of an object of a class is defined by two members:a *copy constructor* and a *copy assignment*.
          - The name `this` is predefined in a member function and points to the object for which the member function is called.
      - Moving containers
        - We can control copying by defining a copy constructor and a copy assignment,but copying can be costly for large containers.We can't return a reference to a local object as the result(the local object would be destroyed by the time the caller got a chance to look at it).
        - The `&&` means "rvalue reference" and is a reference to which we can bind an value."lvalue" means "something that can appear on the left-hand side for an assignment",so an rvalue is-to a first approximation-a value that you can't assign to,such as an integer returned by a function call.**Thus,an rvalue is a reference to something that nobody can assign to ,so we can safely steal its value.**
      - Resource management
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
  - Output
    - format output
    ```c++
    float i=2.3;
    cout<<fixed<<i<<"\t"<<hex<<i<<endl;
    ```
  - File streams
    - `ifstream`:for reading from a file
    - `ofstream`:for writing to a file
    - `fstream`:for reading from and writing to a file

  - String streams
    - In `sstream`, the standard library provides streams to and from a `string`;
    - `isstringstream` for reading from a `string`
    - `osstringstream` for writing to a `string`
    - `stringstream` for reading from and writing to a `string`.
  - File system
    - `filesystem`:in the `<filesystem>` header
    - using the filesystem,can express file system and navigate through a file system
    - examine file types and the permissions associated with them
- Containers
  - *when copying is undesired,references,or pointers,or moving operations should be used*
  - Elements
    - If you have a class hierarchy that relies on *virtual* functions to get polymorphic behavior,do not store objects directly in a container.Instead store a pointer(or a smart pointer)
    ```c++
    vector<Shape> vs;//no 
    vector<Shape* >vs ;//yes
    vector<unique_ptr<Shape*>> vups;//yes
    ``` 
  - Range checking
    - The standard-library doesn't guarantee range checking.
    - `vector<int>.at()`:check the range to decide whether throw a `out_of_range` error.
  - List
    - the standard lib offers a doubly-linked list called `list`.We use a ` list` for sequences where we want to insert and delete elements without moving other elements
    - The standard lib also offers a singly-linked list called `forward-list`.
  - Map 
    - The standard lib offers a balanced binary search tree(usually a red-black tree) called `map`.
    - In other contexts,a `map` is known as associative array or a dictionary.
  - Unordered-map
    - The cost of a `map` lookup is `O(log(n))`.However,in many cases,we can do better by using a hashed lookup rather than a comparison using an ordering function,such as `<`.The standard lib hashed containers are referred to as `unordered`,because they don't require an ordering function:
    ```c++
    unordered_map<string,int> phone_book {
      {"ch", 1},
      {"zh",2}
    } 
    ```
    - The difference between `map` and `unordered_map` is:
      - A `map` requires an ordering function(the default is `<`) and yields an ordered sequence
      - A `unordered_map` requires a hash function and does not maintain an order among its elements.
    - `vector` optimization:
    ```c++
    vector<pair<string,int>> v;
    v.push_back(pair("ch",1));//not good,make a pair and move it into v
    v.emplace_back(pair("ch", 1));//good,build a pair in v
    ```
- Algorithms
  - `back_inserter`:constructs an iterator that adds elements at the end of a container,extending the container to make room for them.
  - Iterator types
    - What is common for all iterators is their semantics and the naming of their operations.Each container  know its iterator types and makes them available under the conventional names `iterator` and `const_iterator`.For example,the `list<Entry>::iterator` is the general iterator type for `list<Entry>` 
    - Stream iterators:treat the output as a container.The same as `istream_iterator`.
    ``` c++
    ostream_iterator<string> oo {count};
    *oo="hello";
    ++oo;
    *oo="world\n";
    ```
    - usage :remove the duplicate of instream
    ```c++
    int main(int argc, char const *argv[])
    {
        /* code */
        string from,to;

        std::cin>>from>>to;

        ifstream is {from};
        istream_iterator<string> ii {is};
        istream_iterator<string> eos {};

        ofstream os {to};
        ostream_iterator<string> oo {os,"\n"};

        vector<string> b {ii,eos};
        sort(b.begin(),b.end());

        unique_copy(b.begin(),b.end(),oo);

        // cout<<!is.eof()|| !os;
        return !is.eof()|| !os;
    }
    ```
    - An `ifstream` is an `istream` that can be attached  to a file, and an `ofstream` is an `ostream` that can be attached to a file.
    ```c++
    //a slower version
    string from,to;
    cin>>from>>to;
    
    ifstream is {from};

    ofstream os {to};

    set<string> b {istream_iterator<string> {is},istream_iterator<string> {}};

    copy(b.begin(),b.end(),ostream_iterator<string>{os,"\n"});

    return !is.eof()|| !os;
    ```
    - `find_if`
    ```c++
        auto p=find_if(m.begin(),m.end(),[](const pair<string,int>& r){
        return r.second>42;
    });
    ```
- parallel algorithms
  - parallel execution:tasks are done on multiple threads.(ofter running on several process cores)
  - vectorized execution:tasks are done on a single thread using vectorization,also known as *SIMD*(single instruction,multiple data).
  - The standard library offers support for both and we can be specific about wanting sequential execution;in `<execution>`,we find:
    - `seq` :sequential execution
    - `par`:parallel execution(if feasible)
    - `par_unseq`:parallel and/or unsequenced(vectorized) execution(if feasible)
    ```c++
    sort(v.begin(),v.end());
    sort(seq,v.begin(),v.end());

    sort(par,v.begin(),v.end());
    sort(par_unseq,v.begin(),v.end());

    ```
- Utilities
  - Resource management 
    - A resource is something that must be acquired and later released(explicitly or implicitly).Such as memory,locks,thread handles,and file handles.
    - `unique_ptr` and `shared_ptr`
      - `uniue_ptr`:to represent unique ownership
      - `shared_ptr`:to represent shared ownership
      - The most basic use of these "smart pointers" to prevent memory leaks.
      - The `shared_ptr` is similar to `unique_ptr` except that `shared_ptr` are copied rather than moved.The object is destroyed when the last of its `shared_ptr` is destroyed.Use `shared_ptr` only if you actually need shared ownership.
      - pass a pointer to a `shared_ptr` or `unique_ptr`:`make_shared()` or `make_unique()`
    - `move` and `forward`
      - The choice between moving and copying is most implicitly,but we can't copy a `unique_ptr`.
      - If you want copy a `unique_ptr` elsewhere,you must move it.
      ```c++
      void f1()
      {
        auto p=make_unique<int>(2);
        auto q=move(p);
        //p now holds nullptr
      }
      ```
      - **`std::move` doesn't move anything.Instead,it casts its argument to an rvalue reference,thereby saying that its argument will not be used again and therefore may be moved.It should be something like called `rvalue_cast`**
      - We don't want to repeatedly copy potentially large objects,so wev request move using `std::move`
      ```c++
      template <typename T>
      void swap(T &a,T &b)
      {
          T tmp {move(a)};
          a=move(b);
          b=move(tmp);
          
      }
      ```
    - specialized containers
      - `pair` and `tuple` are heterogeneous;all other containers are homogeneous(all elements are the same)
      - `array`,`vector`,and `tuple` elements are contiguously allocated;`forward_list` and `map` are linked structures.
      - `bitset` and `vector<bool>` holds bits and access them through proxy objects; all other standard library containers can hold a variety of types and access elements directly.
      - `basic_string` require its elements to be some form of character and to provide string manipulation,such as concatenation and locale-sensitive operations.
      - `valarrary` requires its elements to be numbers and to provide numerical operations.
      - `pair` and `tuple`
        - pair:the standard library `equal_range` returns a `pair` of iterators specifying a sub-sequence meeting a predicate.Given a **sorted** sequence `[first:last)`,`equal_range()` will return the `pair` representing the subsequence that matches the predicate `cmp`.
        - tuple:more than two elements,a `tuple` can hold different element types.
        ```c++
        auto tup=make_tuple("chunshun",19,2018);
        auto str=get<0>(tup);
        //get the first element.str="chunshun"

        ```
        - get the unique type of tuple:`auto str=get<string>(tup);get<string>(tup)="zhang`
    - Alternatives
      - `variant`:to represent one of a specified set of alternatives
        - `variant` is often a more convenient alternative to explicitly using a `union`.
      - `optional`:to represent a value of a specified type or no value
        - An `optional<A>` can be seen as a special kind of `variant` (like a `variant<A,nothing>`) or as a generalization of the idea of `A*` either pointing to an object or being `nullptr`.
        - An `optional` can be useful for functions that may or may not return an object.
        - An `optional` is treated as a pointer to its object rather than the object itself.The `optional` equivalent to `nullptr` is the empty object,`{}`.
        - `optional` is not guaranteed type safe.
      - `any`:to represent one of an unbounded set of alternatives types
        - An `any` can hold an arbitrary type and know which type(if any) it holds.It is basically an unconstrained version of `variant`
    - Allocators
      - **A pool allocator is an allocator that manages objects of a single fixed size and allocates space for many objects at a time,rather than using individual allocations.**
      - The pool allocator is defined in the `pmr`(polymorphic memory resource) sub-namespace of `std`.
        ```c++
        pmr::synorcherized_pool_resource pool;
        struct Event{
            vector<int> data=vector<int> {512,&pool};
        };
        list <shared_ptr<Event>> q {&pool};

        void producer()
        {
            for(int n=0;n!=LOTS;++n)
            {
                scoped_lock lk {m};
                q.push_back(allocate_shared<Event,pmr::polymorphic_allocator<Event>>{&pool})
                cv.notify_one();
            }
        }

        ```
    - Time
      - In `<chrono>`, the standard library provides facilities for dealing with time.
    - Function Adaption 
      - When passing a function as a function argument,the type of the argument must exactly match the expression in the called function's declaration.If the intended argument almost matches expectation,we have two alternatives:
        - Use a lambda;
        - Use `std::mem_fn` to make a function object from a member function.
          - Given a member function,the function adaptor `mem_fn(mf)` produces a function object that can be called as a nonmember function.
          ```c++
          void draw_all(vector<Shape*>&v)
          {
              for_each(v.begin(),v.end(),mem_fun(&Shape::draw));
          }
          ```
        - Define the function to accept a `std::function`
        ```c++
        int f1(double);
        function<int(double)> fct1 {f1};

        ```
    - Type functions
      - A type function is a function that is evaluated at compile time given a type as its argument or returning a type.The standard library provides a variety of type functions to help library implementer to write code 

      - The standard library offers the `optional` for multi-change list,
    - Type predicates
      - In `<type_traits>`,the standard library offers simple functions,called *type predicates* that answers a fundamental question about types.
      ```c++
      auto mask=is_arithmetic<int>();
      ```
      - `enable_if`:
        - obvious way of using type predicates includes conditions for `static_assert`,compile time `if`,and `enable_if`.The standard library `enable_if` is a widely used mechanism for conditionally introducing definitions.Consider defining a `smart pointer`:
        ```c++
        template<typename T>
        class Smart_pointer{
          T& operator*();
          T& operator->();
          //should work if and only if T is a class.
        }
        ```
        The `->` should be defined if and only if `T` is a class type.
        ```c++
        template<typename T>
        class Smart_pointer
        {
            T& operator*();
            std::enable_if<is_class<T>(),T& >operator->();
        }
        ```
        If `enable_if` is true, the type of `operator->()` is `T&`;otherwise,the definition of `operator->()` is ignored.
- Numerics
  - numeric algorithms
  ```c++
  copy(v.begin(), v.end(), std::ostream_iterator<int>{std::cout, " "});

  ```
  - parallel algorithms
    - such as `reduce`,`inclusive_scan`,`transform_exculsive_scan`
  - random numbers
    - A random number generator consists of two parts
      - An engine that produces a sequence of random or pseudo-random values.
      - A distribution that maps those values into a mathematical distribution in a range.
  - Vector arithmetric
    - `<valarray>`:a vector-like template
- Concurrency
  - `thread`,`mutex`,`lock`,`packaged_task`,`future`
  - Tasks and `thread`
  ```c++
  void f() { cout << "hello"<<"\n"; }

  struct F {
    void operator()() { cout << "world"<<"\n"; };
    /* data */
  };

  int main() {

    std::thread t1{f};
    std::thread t2{F()};
    t1.join();//wait for the thread t1 to terminate
    t2.join();//wait for the thread t2 to terminate

    return 0;
  }
  ```
  The result is unpredictable and could vary different execution.
  - **Threads of a program share a single address space.In this,threads differ from process,which generally do not directly share data.Since threads share an address space,they can communicate through shared objects.Such communication is typically controlled by locks or other mechanism to prevent data races(uncontrolled concurrent access to a variable)**.
  - Passing arguments
    - Typically,a task needs data to work upon.We can easily pass data as arguments.
    ```c++
    void f(vector<double> &v);

    struct F
    {
        vector<double> &v;
        F(vector<double> &vv) : v{vv} {};
        void operator()() { cout << "world"
                                 << "\n"; };
        /* data */
    };

    int main()
    {

        vector<double> some_vec{1, 2, 3, 4};
        vector<double> vec2{10, 11, 12};

        thread t1{f, ref(some_vec)};
        thread t2{F{vec2}};
        t1.join();
        t2.join();

        return 0;
    }

    ```
    - Returning results
      - returning results through references.
    - Sharing data
      - The fundamental element of the solution is a `mutex`,"a mutual exclusion object".A thread acquires a `mutex` using a `lock` operation.
      ```c++
      mutex m;
      int sh;
      void f()
      {
          scoped_lock lck{m};
          sh += 7;
      }
      //the scoped_lock's constructor acquires the mutex(through a mlock()). If another thread acquires the mutex,the thread waits until the other thread completes its access to the data.Once a thread has completed its access,the `scoped_lock` releases the mutex(with m.unlock())
      scoped_lock lck {mutex1,mutex2,mutex3};
      //this `scoped_lock` will procedd only after acquiring all its `mutex` arguments and will never block("go to sleep"),while holding a `mutex`.The destructor for `scoped_lock` ensures that the `mutex` are released when a `thread` leaved the scope.
      ```
      - One of the most common ways of sharing data is among many readers and a single writer.This `reader-writing` lock idiom is supported be `shared_mutex`.A reader will acquire the mutex "shared" so that other readers can still gain access,whereas a writer will demand exclusive access.
      ```c++
      shared_mutex mx;

      void reader()
      {
          shared_lock lck{mx};
          // read
      }

      void writer()
      {
          unique_lock lck{mx};
          //write
      }
      ```
    - waiting for events
      - Sometimes,a thread has to wait for some kind of external event. 
      - The basic support for communicating using external events is provided by `condition_variable` found in `<condition_variable>`. A condition_variable is a mechanism allowing one thread to wait for another.In particular,it allows a thread to wait for some *condition*(often called the event) to occur as the result of work done by other threads.
      - `unique_lock` vs `shared_lock`:
        - A `scoped_lock` cann't be copied,but a `unique_lock` can be.
        - A `unique_lock` offers operations,such as `lock()` and `unlock()`,for lower level control of synchronization.
        - `unique_lock` can only handle a single mutex.
    - Communicating tasks(high level in `<future>`)
      - `future` and `promise` for returning a value from a task spawned on a separate thread.
        - The important point about `future` and `promise` is that they enable a transfer of a value between two tasks without explicit use of a lock,the system implements the transfer efficiently.
        - The main purpose of a `promise` is to provide simple "put" operations(called `set_value` and `set_exception`) to match *future's get()*.
      - `packaged_task` to help launch tasks and connect up the mechanisms for returning a result.`using task_type=double(double*,double*,double);
    //a double function(double*,double*,double)`
        - The packaged_task type is provided to simplify up tasks connected with future and promise to be run on threads.A packaged_task provides wrapper code to put the return value or exception from the task into a promise.The `packaged_task` templates takes the type of the task as its template argument(here `Task_type`,an `move` is needed,because `packaged_task` cannot be copied). The reason that a `packaged_type` cannot be copied is that it is a resource handle:It owns its promise and is responsible for whatever resources its task may own.
          ```c++
          double acc(double *start, double *end, double init)
          {
              return accumulate(start, end, init);
          }
          double comp2(vector<double> &v)
          {
              using Task_type = double(double *, double *, double);
              vector<double> v;
              packaged_task<Task_type> pt0{acc};
              packaged_task<Task_type> pt1{acc};
              future<double> f0{pt0.get_future()};
              future<double> f1{pt1.get_future()};
              double *first = &v[0];
              thread t1{move(pt0), first, first + v.size() / 2, 0};
              thread t2{move(pt1), first + v.size() / 2, first + v.size(), 0};
              return f0.get() + f1.get();
          }
        ```
      - `async` for launching of a task in a manner very similar to calling a function.
        - treat a task as a function that may happen to run concurrently with other tasks.
        ```c++
        double accum(double* start,double*end,double init)
        {
            return accumulate(start,end,init);
        }
        double compose(vector<double>& v)
        {
            if(v.size()<1000)
                return accum(v.begin(),v.end(),0.0);
            auto v0=&v[0];
            auto sz=v.size();
            auto f0=async(accum,v0,v0+sz/4,0.0);
            auto f1=async(accum,v0+sz/4,v0+sz/2,0.0);
            auto f2=async(accum,v0+sz/2,v0+3*sz/4,0.0);
            auto f3=async(accum,v0+3*sz/4,v0+sz,0.0);
            return f0.get()+f1.get()+f2.get()+f3.get();
        }
        ```