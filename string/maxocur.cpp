#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "asdagasfdsafs";

    int arr[26] = {0};

    for(int i = 0; i < str.length(); i++){
        arr[str[i]-'a']++;
    }

    char ch = 'a';
    int max = arr[0];

    for(int i = 0; i < 26; i++){
        if(arr[i] > max){
            max = arr[i];
            ch = char(i+'a');
        }
    }

    cout << "max: " << max << " " << ch << endl;

    return 0;
}
