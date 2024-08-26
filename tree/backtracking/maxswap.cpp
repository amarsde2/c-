#include<bits/stdc++.h>
using namespace std;




void maxwap(string &str, int swaps, string &maxstr){
    int n = str.length();
    if(swaps == 0){
        return ;
    }
    for(int i= 0; i < n -1 ; i++){
        for(int j = i+1; j < n; j++){
            if(str[i] < str[j]){
                swap(str[i], str[j]);
                if(str.compare(maxstr) > 0){
                    maxstr = str;
                }
                maxwap(str, swaps - 1, maxstr);
                swap(str[i], str[j]);
            }
        }
    }
    return ;
}


int main(){
    string str = "129814999";
    int swap = 4;
    string max = str;
    maxwap(str, swap, max);
    cout << max << endl;
    return 0;
}