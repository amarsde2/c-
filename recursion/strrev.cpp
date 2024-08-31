#include<bits/stdc++.h>
using namespace std;


string getRev(string str)
{
    if(str.length() == 0){
        return "";
    }
    
    string ros  = str.substr(1);
    return  getRev(ros) + str[0] ;   
}


int main(){
    string str = "Hello";
    cout << getRev(str) << endl;
    return 0;
}

