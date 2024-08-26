#include<bits/stdc++.h>
using namespace std;
#define N 9

int suko[N][N]= {
    { 3, 1, 0, 5, 7, 8, 4, 0, 2 },
    { 0, 2, 9, 0, 3, 0, 0, 0, 8 },
    { 4, 0, 0, 6, 2, 9, 0, 3, 1 },
    { 2, 0, 3, 0, 1, 0, 0, 8, 0 },
    { 0, 7, 0, 8, 6, 3, 0, 0, 5 },
    { 8, 0, 1, 0, 9, 0, 6, 0, 0 },
    { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
    { 6, 9, 2, 0, 5, 0, 0, 7, 4 },
    { 7, 0, 0, 2, 0, 6, 3, 0, 0 }
};



void displayGrid(){
     
    for(int row  = 0; row < N; row++){
        for(int col = 0; col < N; col++){
            if(col == 3 || col == 6){
                cout << " | ";
            }
            cout << suko[row][col] << " ";
        }

        if(row == 2 || row == 5){
            cout << endl;
            for(int i = 0; i < N; i++){
               cout << "---";
            }
        }

        
        cout << endl;
    }

}

bool findEmptyPlace(int &row, int &col){
    for(row = 0; row < N; row++){
        for(col = 0; col < N; col++){
            if(suko[row][col] == 0){
              return true;
            }
        }
    }
    return false;
}

bool findinrow(int row, int num){
    for(int col = 0; col < N; col++){
        if(suko[row][col] == num){
            return true;
        }
    }

    return false;
}


bool findincol(int col, int num){
    for(int row = 0; row < N; row++){
        if(suko[row][col] == num){
            return true;
        }
    }
    return false;
}

bool findinbox(int rowIndex, int colIndex, int num){
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            if(suko[row+rowIndex][col+colIndex] == num){
                return true;
            }
        }
    }
    return false;
}

bool isvalid(int row, int col, int num){

    return !findinrow(row, num) && !findincol(col, num) && !findinbox(row - row%3, col - col%3, num);
}

bool solveSukdo(){
    int row, col;

    if(!findEmptyPlace(row, col)){
        return true;
    }

    for(int num = 1; num <= 9 ; num++){
        if(isvalid(row, col, num)){
            suko[row][col] = num;

            if(solveSukdo() == true){
               return true;
            }

            suko[row][col] = 0;
        }
    }

    return false;
}

int main(){

    if(solveSukdo() == true){
        displayGrid();
    } else{
        cout << "Solution does not exist!" << endl;
    }
}
