#include<bits/stdc++.h>
using namespace std;


void subseq(string str, string ans)
{
    if(str.length() == 0){
        cout << ans << endl;
        return;
    }

    char c = str[0];
    int code = c;
    string res = str.substr(1);
    
    subseq(res, ans);
    subseq(res, ans+c);
    subseq(res, ans + to_string(code));
}


int main(){
    string str = "AB";
    subseq(str, "");
    return 0;
}

