#include<bits/stdc++.h>
using namespace std;

void prefixSearch(string pattern, int m, int prefixArray[]){
    int i = 1;
    int length = 0;
    prefixArray[0] = 0;

    while(i < m){
        if(pattern[i] == pattern[length]){
            length++;
            prefixArray[i] = length;
        } else{
            if(length != 0){
               length = prefixArray[length -1];
               i--;
            }else{
                prefixArray[0] = 0;
            }
        }
        i++;
    }
}

void kmpsearch(string main, string pattern, int *output, int& loc){
    int m,n, i= 0, j = 0;
    m = main.size();
    n = pattern.size();
    int prefixArray[n];
    prefixSearch(pattern, n, prefixArray); 
    loc = 0;

    while(i < m){
        if(main[i] == pattern[j]){
            i++;
            j++;
        }

        if(j == n){
            output[loc] = i-j;
            loc++;
            j = prefixArray[j-1];
        } else if(j < n && main[i] !=  pattern[j]){
            if(j != 0){
                j = prefixArray[j-1];
            } else{
                i++;
            }
        }
      
    }

}


int main(){
    string str = "Hello, world!";
    string pattern = "l";
    int output[str.length()];
    int index;
    
    kmpsearch(str, pattern, output, index);

    for(int i = 0; i < index; i++){
        cout << output[i] << " " << endl;
    }

    return 0;
}