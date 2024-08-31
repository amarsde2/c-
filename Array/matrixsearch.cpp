#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m, key;
    cin >> n >> m;
    int matrix[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           cin >> matrix[i][j];
        }
    }
    
    cout << "Enter search value: " << endl;

    cin >> key;

    int row = 0;
    int col = m-1;

    while(row < n && col >= 0){
        if(matrix[row][col] == key){
            cout << "item found at position " << row << col << endl;
            break;
        } else if(matrix[row][col] < key){
            row++;
        } else {
            col--;
        }
    }

    return 0;
}