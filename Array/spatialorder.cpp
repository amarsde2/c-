#include<bits/stdc++.h>
using namespace std;
#define MAX 100

void spatialOrderTravesal(int spatial[MAX][MAX], int n, int m){
    int row_start = 0;
    int column_start = 0;
    int row_end  = n - 1;
    int column_end = m - 1;

    while(row_start <= row_end && column_start <= column_end){

        for(int i = column_start; i <= column_end; i++){
            cout << spatial[row_start][i] << " ";
        }

        row_start++;

        for(int i = row_start; i <= row_end; i++){
           cout << spatial[i][column_end] << " ";
        }
        column_end--;

        if(row_start <= row_end){
            for(int i = column_end; i >= column_start; i--){
            cout << spatial[row_end][i] << " ";
            }
            row_end--;
        }
        
       
        if(column_start <= column_end){
            for(int i = row_end; i >= row_start; i--){
                cout << spatial[i][column_start] << " ";
            }
            column_start++;
        }
    }
}

int main(){

    int n, m; 
    cout << "Enter row number and column number" << endl;
    cin >> n >> m;
    int spatial[MAX][MAX];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> spatial[i][j];
        }
    }

    cout << "Outputing spatial coordinates" << endl;

    spatialOrderTravesal(spatial, n, m);

    return 0;

}