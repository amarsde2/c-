#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
const int M = 1e9+7;
int power[N];


int main(){
    power[0] = 1;
    for(int i = 1 ; i < N ; i++){
       power[i] = (power[i-1] * 31) % M;
    }

    string str = "ha";
    string word = "happyha";
    int T = word.size();
    int S = str.size();
    vector<long long> hash(T+1, 0);

    for(int i = 0; i < T; i++){
        hash[i+1] = (hash[i] + (word[i] - 'a' + 1) * power[i]) % M;  
    }

    long long strHas = 0;

    for(int i = 0; i < S; i++){
        strHas = (strHas + (str[i] - 'a' + 1)*power[i]) % M;
    }

    for(int i = 0 ; i <= T-S; i++){
        long long currentHas = (hash[i+S] - hash[i] + M) % M;
        long long expectedHas = (strHas * power[i]) % M;

        if(currentHas  ==  expectedHas){
             cout << "Found " << i  << endl;
        }
    }


    return 0;

}
