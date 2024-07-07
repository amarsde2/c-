#include<iostream>
#include<cmath>
using namespace std;


bool checkPyth(int a, int b, int c){
    int x, y;
    int maxNum = max(a, max(b,c));
    
    if(maxNum == a){
       x = b; y = c; 
    } else if(maxNum == b){
       x = a; y = c; 
    } else{
       x = a; y = b;
    }

    return maxNum * maxNum  == x * x + y * y;
}

int main(){

    int a, b, c; 
     
    cin >> a >> b >> c;

    if(checkPyth(a,b,c)){
        cout << "Triange is python  ";
    } else{
        cout << "Triange is not python  ";
    }

    cout << endl;

    return 0;
}