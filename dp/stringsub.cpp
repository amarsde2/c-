#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    int e = 1;
    int a = 0;
    int ab = 0;
    int abc = 0;

    for(int i = 0; i < n; i++){
        if(str[i] == 'a'){
            a += e;
        } else if(str[i] == 'b'){
            ab += a;
        } else if(str[i] == 'c'){
            abc += ab;
        } else if(str[i] == '?'){
            abc = 3*abc + ab;
            ab = 3 *ab + a;
            a = 3*a + e;
        }
    }

    cout <<  abc << endl;
    return 0;
}