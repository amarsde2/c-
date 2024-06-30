#include<iostream>
using namespace std; 


class Shape{
    protected: 
      int width, height;
    public: 
      Shape(int a, int b) : width(a), height(b){}
      virtual void area() = 0;
};

class Rect: public Shape{    
    public: 
      Rect(int a, int b) : Shape(a, b){};
      void area() { cout << width * height << endl; }
};

class Triangle: public Shape{
    public:
      Triangle(int a, int b) : Shape(a, b){}
      void area()  { cout << 2* width* height << endl; }
};


int main(){
   
    Rect rect(2,2);
    Triangle tri(2,2);


     rect.area();
     tri.area();

    return 0;
}


