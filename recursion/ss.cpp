#include<bits/stdc++.h>
using namespace std;


void subseq(string str, string ans)
{
    if(str.length() == 0){
        cout << ans << endl;
        return;
    }

    char c = str[0];
    string res = str.substr(1);
    
    subseq(res, ans);
    subseq(res, ans+c);
}


int main(){
    string str = "abc";
    subseq(str, "");
    return 0;
}

