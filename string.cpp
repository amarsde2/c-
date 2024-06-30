#include<iostream>
#include<string>
using namespace std; 

int main(){
    string filename;
    string path = "http://localhost";

    cout << "Enter a filename: \n";

    getline(cin, filename);
    path = path + filename;
    cout << path << endl;
    
    return 0;

}