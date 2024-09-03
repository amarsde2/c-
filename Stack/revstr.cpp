#include<bits/stdc++.h>
#include<stack>
using namespace std;

void reverseStr(string str){
    stack<string> s;
   
    for(int i=0; i<str.length(); i++){
        string word = "";
        while(str[i] != ' ' && i < str.length()){
            word += str[i];
            i++;
        } 
        s.push(word);
    }

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    } cout << endl;

    return;

}

int main(){
    string str ="Hope, you are doing well!";
    reverseStr(str);
    return 0;
}