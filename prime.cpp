#include<iostream>
using namespace std;

int main(){

    int num;
    bool flag = true;

    cin >> num;

    for(int i = 2; i < num ; i++){
        if(num % 2 == 0){
            flag = false;
            break;
        }
    }


    if(num <= 1){
        flag = false;
    }


    if(flag){
        cout << num << " is prime " <<endl;
    } else{
        cout << num << " is not prime "<<endl;
    }

    return 0;
}