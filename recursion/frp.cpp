#include<bits/stdc++.h>
using namespace std;


void getRev(string str)
{
    if(str.length() == 0){
        return;
    }

    if(str[0] == 'p' && str[1] == 'i'){
       cout << "3.14";
       getRev(str.substr(2)); 
    }else{
       cout << str[0];
       getRev(str.substr(1)); 
    } 
  
}


int main(){
    string str = "piHelpilo";
    getRev(str);
    return 0;
}

