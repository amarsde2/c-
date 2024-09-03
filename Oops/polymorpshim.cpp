#include<bits/stdc++.h>
using namespace std;


class Parent{
    public:
    virtual void display(){
        cout << "Parent" << endl;
    }
};


class Child:public Parent{
    public:
    void display(){
        cout << "Child" << endl;
    }
};




class FunctionOverload {
   
    public:
    int real, img;
    FunctionOverload(){};
    FunctionOverload(int _real, int _img){
       real = _real;
       img = _img;
    }
    void display(){
        cout << "Function Overload without parameters" << endl;
    }
    void display(int num){
        cout << "Function Overload int parameters" << num << endl;
    }

    void display(double num){
        cout << "Function Overload double parameters " << num << endl;
    }

    FunctionOverload operator + (FunctionOverload const &obj){
       FunctionOverload result; 
       result.real = real + obj.real;
       result.img = img + obj.img;
       return result;
    }
};



int main(){

    Parent *p;
    Child child;
    p = &child;

    p->display();
   
    // FunctionOverload obj(2,4), obj2(3,6);
    // FunctionOverload result = obj + obj2;

    // cout << result.real << " + i" << result.img << endl; 

   
    // obj.display();
    // obj.display(5);
    // obj.display(5.5);

    return 0;

}