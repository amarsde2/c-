#include<iostream>
using namespace std;

int sumFirstN(int num){
    return num * (num + 1) / 2;
}

int main(){
    
    int num, sum = 0; 

    cin >> num;

    sum = sumFirstN(num);

    cout << sum << endl;

    return 0;
  
}