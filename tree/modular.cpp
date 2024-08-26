#include<bits/stdc++.h>
using namespace std;

int getModularEXp(int value1 , int value2, int module){

    if(value1 < 0){
        value1 = (value1 % module + module) %module ;
    }

    if(value2 < 0){
        value2 = (value2 % module + module) % module;
    }

    int sum  = (value1 + value2) % module;

    return (sum +  module)% module;


}

int main(){
    int valueone = 22;
    int valuetwo = 26;
    int module = 5;

    cout << getModularEXp(valueone, valuetwo, module) << endl;
}