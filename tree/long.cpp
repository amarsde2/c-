#include<bits/stdc++.h>
using namespace std;

int lcs(char* X, char* Y, int m, int n){
    int Long[m+1][n+1];
    int i, j, index;
    for(i = 0 ; i <= m; i++){
        for(j = 0; j <= n; j++){
            if(i == 0 || j == 0){
                Long[i][j] = 0;
            } else if(X[i-1] == Y[j-1]){
                Long[i][j] = Long[i-1][j-1] + 1;
            } else {
                Long[i][j] = max(Long[i-1][j], Long[i][j-1]);
            }
        }
    }

    index = Long[m][n];
    char LCS[index+1];
    LCS[index] = '\0';
    i = m, j = n;
    while(i > 0 && j > 0){
        if(X[i-1] == Y[j-1]){
           LCS[index-1] = X[i-1];
           i--;
           j--;
           index--;
        } else if(Long[i-1][j] > Long[i][j-1]){
           i--;
        } else{
           j--;
        }
    }
    printf("LCS %s\n", LCS);
    return Long[m][n];
}

int main(){
    char X[] = "ABSDHS";
    char Y[] = "ABDHSP";
    int m = strlen(X);
    int n = strlen(Y);
    printf("Length of LCS is %d\n", lcs(X, Y, m, n));
    return 0;
}