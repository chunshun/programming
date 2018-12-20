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