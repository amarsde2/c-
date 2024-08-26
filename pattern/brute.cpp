#include<bits/stdc++.h>
#include<string>
using namespace std;


int main(){
    string  str = "Hello, World!"; 
    string  pattern = "leo";
    bool found = false;
    int m = str.length();  
    int n = pattern.length();

    for(int i = 0 ; i < m-n; i++){
        int j = 0;
        while(j < n && str[j+i] == pattern[j]){
            j++;
        }
          
        if(n == j){
            found = true;
            break;
        }
    }

    if(found){
        cout << "Pattern found " << endl;
    } else{
        cout << "Pattern not found " <<endl;
    }

    return 0;

}
