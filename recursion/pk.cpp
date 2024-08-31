#include<bits/stdc++.h>
using namespace std;

string keys[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void subseq(string str, string ans)
{
    if(str.length() == 0){
        cout << ans << endl;
        return;
    }

    char c = str[0];
    string code = keys[c-'0'];
    string res = str.substr(1);
    
    for(int i = 0 ; i< code.length(); i++){
        subseq(res, ans + code[i]);
    
    }
}


int main(){
    string str = "23";
    subseq(str, "");
    return 0;
}

