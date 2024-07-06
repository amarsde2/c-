#include<iostream>
#include<string>
#include<cstring>
using namespace std; 

namespace first{
    string getMessage() {
        return "Hello, First!";
    }
}

namespace second{
    string getMessage(){
        return "Hello, Second!";
    }
}

using second::getMessage;

int main(){
    cout << getMessage() << endl;
    return 0;
}