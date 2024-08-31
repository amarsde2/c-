#include<bits/stdc++.h>
using namespace std;


int main(){
  
    string str;
    getline(cin, str);

    vector<string>ans;
 
   
    do{
        ans.push_back(str);
    }while(next_permutation(str.begin(), str.end()));

    for(auto v : ans){
       cout << v << endl;
       cout << endl;
    }

    return 0;
}