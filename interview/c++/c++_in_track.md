- Polymorphism in C++
  - compile time polymorphism
    - function overloading
    ```c++
    // C++ program for function overloading 
    #include <bits/stdc++.h> 

    using namespace std; 
    class Geeks 
    { 
        public: 
        
        // function with 1 int parameter 
        void func(int x) 
        { 
            cout << "value of x is " << x << endl; 
        } 
        
        // function with same name but 1 double parameter 
        void func(double x) 
        { 
            cout << "value of x is " << x << endl; 
        } 
        
        // function with same name and 2 int parameters 
        void func(int x, int y) 
        { 
            cout << "value of x and y is " << x << ", " << y << endl; 
        } 
    }; 

    int main() { 
        
        Geeks obj1; 
        
        // Which function is called will depend on the parameters passed 
        // The first 'func' is called 
        obj1.func(7); 
        
        // The second 'func' is called 
        obj1.func(9.132); 
        
        // The third 'func' is called 
        obj1.func(85,64); 
        return 0; 
    } 

    ```
    - operator overloading
    ```c++
    // CPP program to illustrate 
    // Operator Overloading 
    #include<iostream> 
    using namespace std; 

    class Complex { 
    private: 
        int real, imag; 
    public: 
        Complex(int r = 0, int i =0) {real = r; imag = i;} 
        
        // This is automatically called when '+' is used with 
        // between two Complex objects 
        Complex operator + (Complex const &obj) { 
            Complex res; 
            res.real = real + obj.real; 
            res.imag = imag + obj.imag; 
            return res; 
        } 
        void print() { cout << real << " + i" << imag << endl; } 
    }; 

    int main() 
    { 
        Complex c1(10, 5), c2(2, 4); 
        Complex c3 = c1 + c2; // An example call to "operator+" 
        c3.print(); 
    } 

    ```
  
  - runtime polymorphism
    - function overriding(virtual function)
    ```c++
    // C++ program for function overriding 

    #include <bits/stdc++.h> 
    using namespace std; 

    class base 
    { 
    public: 
        virtual void print () 
        { cout<< "print base class" <<endl; } 

        void show () 
        { cout<< "show base class" <<endl; } 
    }; 

    class derived:public base 
    { 
    public: 
        void print () //print () is already virtual function in derived class, we could also declared as virtual void print () explicitly 
        { cout<< "print derived class" <<endl; } 

        void show () 
        { cout<< "show derived class" <<endl; } 
    }; 

    //main function 
    int main() 
    { 
        base *bptr; 
        derived d; 
        bptr = &d; 
        
        //virtual function, binded at runtime (Runtime polymorphism) 
        bptr->print(); 
        
        // Non-virtual function, binded at compile time 
        bptr->show(); 

        return 0; 
    } 

    ```
- interface:Empty class where all functions are pure and hence have to derive and then implement all of the functions.Pure functions are actually functions which have no implementation in base and have to be implemented in derived class.
- abstract class:These base classes where you have to derive from and then implement the pure virtual functions.**A class with a pure virtual function is called an abstract class**
- reflection in C++: use the RTTI(runtime type information)
- operator new:
```c++
// operator new example
#include <iostream>     // std::cout
#include <new>          // ::operator new

struct MyClass {
  int data[100];
  MyClass() {std::cout << "constructed [" << this << "]\n";}
};

int main () {

  std::cout << "1: ";
  MyClass * p1 = new MyClass;// this is a pointer
      // allocates memory by calling: operator new (sizeof(MyClass))
      // and then constructs an object at the newly allocated space



  std::cout << "2: ";
  MyClass * p2 = new (std::nothrow) MyClass;
      // allocates memory by calling: operator new (sizeof(MyClass),std::nothrow)
      // and then constructs an object at the newly allocated space


  std::cout << "3: ";
  new (p2) MyClass;
      // does not allocate memory -- calls: operator new (sizeof(MyClass),p2)
      // but constructs an object at p2

  // Notice though that calling this function directly does not construct an object:
  std::cout << "4: ";
  MyClass * p3 = (MyClass*) ::operator new (sizeof(MyClass));
      // allocates memory by calling: operator new (sizeof(MyClass))
      // but does not call MyClass's constructor

  delete p1;
  delete p2;
  delete p3;

  return 0;
}

```
- virtual function
  - they are meanly used to achieve runtime polymorphism 
  - functions are declared with virtual word
  - Virtual functions should be accessed using pointer or reference of base class type to achieve run time polymorphism
  - A class can not have virtual constructor function,but virtual destructor function. 
  - They are always defined in base class and overridden in derived class. It is not mandatory for derived class to override (or re-define the virtual function), in that case base class version of function is used.
    - early binding(compile time)
    - late binding(runtime)
    ```c++
        // CPP program to illustrate  
        // concept of Virtual Functions 
        #include<iostream> 
        using namespace std; 
        
        class base 
        { 
        public: 
            virtual void print () 
            { cout<< "print base class" <<endl; } 
        
            void show () 
            { cout<< "show base class" <<endl; } 
        }; 
        
        class derived:public base 
        { 
        public: 
            void print () 
            { cout<< "print derived class" <<endl; } 
        
            void show () 
            { cout<< "show derived class" <<endl; } 
        }; 
        
        int main() 
        { 
            base *bptr; 
            derived d; 
            bptr = &d; 
            
            //virtual function, binded at runtime 
            bptr->print();  
            
            // Non-virtual function, binded at compile time 
            bptr->show();  
        } 
    ``` 