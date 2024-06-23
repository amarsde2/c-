#include<iostream>
#include<string>
using namespace std;

void reverse(string& str){
    int n = str.length();
    for(int i = 0; i < n/2; i++){
        swap(str[i], str[n-i-1]);
    }
}

int main(){
    string name; 
    cout << "Enter a name: \n";
    getline(cin, name);
    reverse(name);
    cout << name<<endl;
    return 0;
}
