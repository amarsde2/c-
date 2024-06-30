#include<iostream>
#include<cstring>
using namespace std;


struct user {
    string name;
    int age;
};

int main(){
    
    struct user amar;

    getline(cin, amar.name);

    amar.age = 20;

    cout << amar.name << amar.age << endl;

    return 0;
}