#include<bits/stdc++.h>
using namespace std;


void foundPattern(string main, string pattern, int output[], int *index){
    int m = main.length();
    int n = pattern.length();
    int i,j;
    for(i = 0; i < (m-n); i++){
        for(j = 0; j < n; j++){
            if(main[j+i] != pattern[j]){
                break;
            }
        }

        if(j == n){
          (*index)++;
          output[*index] = i;
        }
    }
}


int main(){
    string str = "Hello, World!";
    string pattern = "l";
    int found[str.length()] = {};
    int index = -1;
    foundPattern(str, pattern, found, &index);
    
    for(int i = 0; i <= index; i++){
        cout << found[i] << " " << endl;
    }

    return 0;
}
