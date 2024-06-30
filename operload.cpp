#include<iostream>
using namespace std; 

class Test{
    public:
       int width;
       int height;
    
    Test(int x, int y){
       width = x; height = y;
    }

    Test operator+(const Test& obj){
        Test test(0,0);

        test.width = this->width + obj.width;
        test.height = this->height + obj.height;

        return test;
    }
};


int main(){
     
    Test t1(1,2); 
    Test t2(2,3);

    Test t3 =  t1 + t2;

    cout << t3.width << endl;
    cout << t3.height << endl;

    return 0;

}