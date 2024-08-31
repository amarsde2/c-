#include<bits/stdc++.h>
using namespace std;


bool isSafer(int **arr, int row, int col, int n){
    for(int i = 0; i < row; i++){
        if(arr[i][col] == 1){
            return false;
        }
    }

    for(int i = col; i < n; i++){
        if(arr[row][i] == 1){
            return false;
        }
    }

    int x = row;
    int y = col;

    while(x >= 0 && y >= 0){
        if(arr[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;

    while(x >= 0 && y < n){
        if(arr[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }

    return true;


}



bool solveNqueen(int **arr, int row, int n){

    if(row >= n){
       return true;
    }
    
    for(int col = 0; col < n; col++){
        if(isSafer(arr, row, col, n) == true){
            arr[row][col] = 1;
            if(solveNqueen(arr, row+1, n) == true){
                return true;
            }
            arr[row][col] = 0;
         }
    }

    return false;
}



int main(){
    int n; 
    cin >> n;
    int** arr = new int*[n];

    for(int i = 0 ; i < n ; i++){
        arr[i] = new int[n];
    }
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
          arr[i][j] = 0;
        }
    }

    if(solveNqueen(arr, 0, n)){
        cout << "Solution found!" << endl;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
            cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    } else{
        cout << "Solution not found!" << endl;
    }

    return 0;
}