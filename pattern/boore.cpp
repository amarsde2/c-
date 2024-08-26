#include<bits/stdc++.h>
using namespace std;



void computeFullShiftArray(string pattern, int shiftArray[], int fullShiftArray[]) {
    int n = pattern.length();
    int i = n;
    int j = n + 1;
    fullShiftArray[i] = j;

    while (i > 0) {
        while (j <= n && pattern[j - 1] != pattern[i - 1]) {
            if (shiftArray[j] == 0) {
                shiftArray[j] = j - 1;
            }
            j = fullShiftArray[j];
        }
        j--;
        i--;
        fullShiftArray[i] = j;
    }
}

void computeShiftArray(string pattern, int shiftArray[], int fullShiftArray[]) {
    int n = pattern.length();
    int j = fullShiftArray[0];
    for (int i = 0; i <= n; i++) {
        if (shiftArray[i] == 0) {
            shiftArray[i] = j;
            if (i == j) {
                j = fullShiftArray[j];
            }
        }
    }
}


void booreMoore(string str, string pattern, int output[], int *index){
    int m = str.length();
    int n = pattern.length();
    int shiftArray[n+1];
    int fullshiftArray[n+1];

    for(int i = 0 ; i < n+1 ; i++){
        shiftArray[i] = 0;
    }

    computeFullShiftArray(pattern, shiftArray, fullshiftArray);
    computeShiftArray(pattern, shiftArray, fullshiftArray);
   
    
    int shift = 0;

    while(shift <= (m-n)){
        int j = n - 1;
        while( j >= 0 && pattern[j] == str[j + shift]){
           j--;
        }

        if(j < 0){
            (*index)++;
            output[(*index)] = shift;
            shift += shiftArray[0];
        } else{
            shift += shiftArray[j+1];
        }

    }

}
int main(){
    string str = "Hello, world!";
    string pattern = "l";
    int index = -1;
    int output[str.length()];

    booreMoore(str, pattern,  output, &index);

    for(int i = 0 ; i <= index; i++){
        cout << output[i] << " ";
    }

    return 0;
}