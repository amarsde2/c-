#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "ha";
    string word = "hatestha";
    
    for(int i = 0; i < word.size() - str.size() + 1; i++){
        if(word.substr(i, str.size()) == str){
            cout << "Found substr at index " << i << endl;
        }
    }

    return 0;
}