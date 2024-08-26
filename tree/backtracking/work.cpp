#include<bits/stdc++.h>
using namespace std;
#define N 13
string dir[N] = {"mobile","samsung","sam","sung","man","mango", "icecream","and", "go","i","love","ice","cream"};


bool isValid(string word){
    for(int i = 0; i < N; i++){
        if(dir[i].compare(word) == 0){
            return true;
        }
    }
    return false;
}

void solveWorkBreak(string str, int n, string result){

    for(int i = 1; i <= n; i++){
       string subtr = str.substr(0,i);
       if(isValid(subtr)){
          if(i == n){
             result += subtr;
             cout << result << endl;
             return;
          }
          solveWorkBreak(str.substr(i, n-1),  n - i, result + subtr +" ");
       }
    }
}

int main(){
    string str = "iloveicecreamandmango";

    solveWorkBreak(str, str.size(), " ");

    return 0;
}