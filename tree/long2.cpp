#include<bits/stdc++.h>
using namespace std;



int lcs(char *X, char *Y, int m, int n){
    int L[m+1][n+1];
    int i, j;
    for(i=0; i<=m; i++){
       for(j=0; j<=n; j++){
            if(i == 0 || j == 0){
               L[i][j] = 0;
            } else if(X[i-1] == Y[j-1]){
               L[i][j] = L[i-1][j-1]+1;
            } else {
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
       }
    }
    int index = L[m][n]; 
    char LSC[index+1];
    LSC[index] = '\0';
    i = m, j = n;

    while(i > 0  && j > 0){
        if(X[i-1] == Y[j-1]){
            LSC[index-1] = X[i-1];
            i--;
            j--;
            index--;
        } else if(L[i-1][j] > L[i][j-1]){
            i--;
        } else{
            j--;
        }
    }

    for(int i = 0 ; i < sizeof(LSC); i++){
        cout << LSC[i];
    }
    return sizeof(LSC)-1;
}


int main(){
    char X[] = "ABSDHS";
    char Y[] = "ABDHSP";
    int m = strlen(X);
    int n = strlen(Y);
    printf("Length of LCS is %d\n", lcs(X, Y, m, n));
    return 0;
}