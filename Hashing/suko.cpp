#include<bits/stdc++.h>
using namespace std;




void helper(int row, int col, 
    vector<map<int,int>> &r, 
    vector<map<int,int>> &c,
    map<pair<int, int>,map<int,int>> &pm,
    vector<vector<char>> &a
){
    
    if(row == 9){
       for(auto i : a){
          for(auto j: i){
             cout << j << " " ;
          }
          cout << endl;
       }
       cout << endl;
       return;
    }

    if(col == 9){
       helper(row+1, 0, r, c, pm, a);
       return;
    }

    if(a[row][col] != '.'){
       helper(row, col+1, r, c, pm, a);
       return;
    }

    for(int i = 1; i <= 9; i++){
        if(!r[row][i] && !c[col][i] && !pm[{row/3,col/3}][i]){
            r[row][i] = c[col][i] = pm[{row/3, col/3}][i] = 1;
            a[row][col] = i+'0';
            helper(row, col+1,r, c, pm,a);
            r[row][i] = c[col][i] = pm[{row/3, col/3}][i] = 0;
            a[row][col] = '.';
        }
    }

}


void solveSuko(vector<vector<char> >&a){
    vector<map<int,int>> row(9);
    vector<map<int,int>> col(9);
    map<pair<int,int>, map<int,int>> pm;
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(a[i][j] != '.'){
                row[i][a[i][j]-'0'] = 1;
                col[j][a[i][j]-'0'] = 1;
                pm[{i/3, j/3}][a[i][j]-'0'] =1;
            }
        }
    }

    helper(0, 0, row, col, pm, a);

}

int main(){
    vector<vector<char>> suko = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'},
    };

    solveSuko(suko);
}