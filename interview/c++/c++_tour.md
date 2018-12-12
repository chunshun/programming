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
    - enumerations
The new operator allocates memory from an area called the *free store*(also known as *dynamic memory* and *heap*).Objects allocated
on the free store are independent of the scope from which they are created and live until they are destroyed using the *delete* operator.
 
