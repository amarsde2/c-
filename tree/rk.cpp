#include<bits/stdc++.h>
using namespace std;
#define MAXCHAR 256

void rpAlgorithm(string org, string patt, int out[],  int *index, int prime){
    int h = 1; 
    int strhash = 0, pathas = 0;
    int patlen = patt.length();
    int strlen = org.length();
    int charIndex;
    for(int i = 0; i < patlen-1; i++){
        h = (h * MAXCHAR) % prime;
    }

    for(int i = 0; i <patlen; i++){
        strhash = (strhash * MAXCHAR + org[i]) % prime;
        pathas = (pathas * MAXCHAR + patt[i]) % prime;
    }
    
    for(int i = 0 ; i <= (strlen - patlen); i++){
        
        if(pathas == strhash){
            for(charIndex = 0 ; charIndex < patlen; charIndex++){
                if(patt[charIndex] != org[i + charIndex]){
                  break;
                }
            }

            if(charIndex == patlen){
                (*index)++;
                out[*index] = i;
            }
        }

        if(i < (strlen -patlen)){
            strhash = (MAXCHAR*( strhash  - org[i]*h)+ org[ patlen +i]) % prime;
            if(strhash < 0){
                strhash += prime;
            }
        }

        
    }
}

int main(){
    string org = "AAAABCAEAAABCBDDAAAABC";
    string patt = "AABC";
    int out[org.length()];
    int index = -1;
    int prime = 101;
    rpAlgorithm(org, patt, out, &index, prime);
   
    for(int i = 0; i <= index; i++){
        cout << out[i] << endl;
    }

    return 0;
}