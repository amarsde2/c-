#include<bits/stdc++.h>
using namespace std;

string addTwoBinaryString(string a, string b){
    
    if (b.length() > a.length()){
        return addTwoBinaryString(b, a);
    }
    
    string res;
    char charry = '0';
    int diff = a.length() - b.length();

    string padding;

    for(int i = 0; i < diff; i++){
       padding.push_back('0');
    }

    b = padding + b;
    
    for(int i = a.length()-1 ; i >= 0 ; i--){
        if(a[i] == '1' && b[i] == '1'){
            if(charry == '1'){
              res.push_back('1');
              charry = '1';
            } else{
              res.push_back('0');
              charry = '1';
            }
        } else if( (a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0')){
            if(charry == '1'){
              res.push_back('0');
              charry = '1';
            } else{
              res.push_back('1');
              charry = '0';
            }
        } else{
            if(charry == '1'){
              res.push_back('1');
              charry = '0';
            } else{
              res.push_back('0');
              charry = '0';
            }
        }
    }

    if(charry == '1'){
        res.push_back(charry);
    }

    reverse(res.begin() , res.end());
    
    int index = 0;

    while(index + 1 < res.length() && res[index] == '0'){
        index++;
    }

    return res.substr(index);

}

int main(){
    
    string a, b; 

    cin >> a >> b; 

    cout << addTwoBinaryString(a, b) << endl;

    return 0;
}