#include<iostream>
using namespace std;

class Distance{
    public:
       int feet = 0, inches = 0; 
       Distance(int a, int b){
          feet = a;
          inches = b;
       }

       bool operator==(const Distance& obj){
          return (feet == obj.feet) && (inches == obj.inches);
       }

};


int main(){
    Distance d1(1,2);
    Distance d2(1,2);
    
    if(d1 == d2){
        cout << "Equal distances" << endl;
    } else{
        cout << "Equal Not distances" << endl;
    }
    return 0;

}