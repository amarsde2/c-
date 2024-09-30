#include<bits/stdc++.h>
using namespace std;

vector<int> getPrefixArray(string st){
    vector<int> prefix(st.size(), 0);
    
    for(int i = 1; i < st.size(); i++){
        int j =  prefix[i-1];
        while(j > 0 && st[j] != st[i]){
            j = prefix[j-1];
        }

        if(st[i] == st[j]){
            j++;
        }

        prefix[i] = j;
    }
    return prefix;
}
int main(){
    string sr = "na";
    string word = "happyhana";
    vector<int> prefix = getPrefixArray(word);
    int pos = -1;
    int i(0),j(0);

    while(i < word.size()){
        if(word[i] == sr[j]){
            i++;
            j++;
        } else{
            if(j != 0){
                j = prefix[j-1];
            } else{
                i++;
            }
        }

        if(j == sr.size()){
           pos = i - sr.size();
           break;
        }
    }

    cout << pos << endl;

    return 0;
}