#include<bits/stdc++.h>
using namespace std;

void permuation(string str,  string ans){
    if(str.length() == 0){
      cout << ans << endl;
      return;
    }
    
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];
        string res = str.substr(0, i) + str.substr(i+1);
        permuation(res, ans + ch);
    }

}

int main(){
    string str = "ABC";

    permuation(str," ");
    
    return 0;
}