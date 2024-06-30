#include<iostream>
using namespace std;

class callInvoke {
    public: 
        int x, y;
        callInvoke(){
           x=0;
           y=0;
        }
        callInvoke(int a, int b){
           x=a;
           y=b;
        }
       
        callInvoke operator () (int c, int d){
           callInvoke result;
           result.x = c; result.y = d;    
           return result;
        }
       
};


int main(){
     
     callInvoke c1(1, 2), c2;

     c1 = c2(1,3);

     cout << c1.x << " " << c1.y << endl;

     return 0;

}