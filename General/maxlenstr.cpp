#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int> ch(256,-1);
    int maxLen = 0;
    string str;
    cin >> str;
    int start = -1;

    for(int i = 0 ; i < str.size() ; i++){
        if(ch[str[i]] > start){
            start = ch[str[i]];

        }
        ch[str[i]] = i;
        maxLen = max(maxLen, i - start);
    }

    cout << maxLen << endl;

    return 0;
}
