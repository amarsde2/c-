#include<bits/stdc++.h>
using namespace std;
#define MAX 256


void computeTransformTable(string pattern, int transform[][MAX]){
    int n = pattern.length();
    for(int i = 0; i < MAX; i++){
        transform[0][i] = 0;
    }
    transform[0][pattern[0]] = 1;
    int lsp = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < MAX; j++){
            transform[i][j] = transform[lsp][j];
        }
        transform[i][pattern[i]] = i+1;

        if(i < pattern.size()){
            lsp = transform[lsp][pattern[i]];
        }
    }
}

void createFiniteAuto(string text, string pattern, int output[], int *index){
    int strlen = text.length();
    int plen = pattern.length();
    int transform[plen+1][MAX];
    computeTransformTable(pattern, transform);

    int presentState = 0;
    for(int i = 0 ; i < strlen; i++){
        presentState = transform[presentState][text[i]];
        if(presentState == plen){
            (*index)++;
            output[*index] = i - plen + 1;
        }
    }
}

int main(){
    string text = "Hello, world!";
    string patt = "l";
    int index = -1;
    int output[text.length()];
    createFiniteAuto(text, patt, output, &index);

    for(int i = 0; i <= index; i++){
       cout << output[i] << " ";
    }
}