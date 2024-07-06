#include<iostream>
#include<string>
using namespace std;

#define MAX 30
#define Test(x)  #x 
#define copy(x, y) x##y

int main() {

    int xy = 100;
    cout << MAX << endl;
    
    #ifdef MAX2 
   
      cout << "Testing " << endl;

    #endif

    cout << Test(hello) << endl;

    cout << copy(x,y) << endl;
    
    return 0;
}


