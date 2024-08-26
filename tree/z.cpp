#include<bits/stdc++.h>
using namespace std;



void contractZArray(string cont , int z[]){
    int n = cont.length();
    int windleft = 0, windright = 0;
    int k;
    
    for(int i = 0; i < n; i++){
        if(i > windright){
            windright = windleft = i;
            while(windright < n && cont[windright-windleft] == cont[windright]){
                windright++;
            }
            z[i] = windright -windleft;
            windright--;
        } else{
            k = i - windleft;

            if(z[k] < windright -i+1){
                z[i] = z[k];
            } else{
                windleft = i;
                while(windright < n && cont[windright-windleft] == cont[windright]){
                   windright++;
                }

                  z[i] = windright -windleft;
                  windright--;
            }
        }
    }
}

void zIndexAlog(string main , string pattern, int out[], int *index){
    int patlen = pattern.length();
    string cont = pattern + "$"+main;
    int z[cont.size()];
    contractZArray(cont, z);

    for(int i = 0; i < cont.size(); i++){
        if(z[i] == patlen){
          (*index)++;
          out[*index] = i - (patlen + 1);
        }
    }
}

int main(){
    string main = "ABAAABCDBBABCDDEBCABC";
    string patt = "ABC";
    int out[main.size()];
    int index = -1;
    zIndexAlog(main, patt, out, &index);

    for(int i = 0; i <= index; i++){
        cout << out[i] << endl;
    }

    return 0;
}