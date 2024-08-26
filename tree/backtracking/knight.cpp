#include<bits/stdc++.h>
using namespace std;
#define N 8
int sol[N][N];

void displayMove(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

bool isvalid(int x, int y, int sol[N][N]){
    if(x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1){
        return true;
    } 
    return false;
}

bool sovledNightTour(int x, int y, int move, int sol[N][N], int xMove[N], int yMove[N]){
    int xnext, ynext;
    if(move == N * N){
        return true;
    }

    for(int i = 0; i < N; i++){
        xnext = x + xMove[i];
        ynext = y + yMove[i];

        if(isvalid(xnext, ynext, sol) == true){
           sol[xnext][ynext]  = move;
           if(sovledNightTour(xnext, ynext, move+1, sol, xMove,yMove) == true){
              return true;
           } else{
              sol[xnext][ynext] = -1;
           }

          
        }
    }

    return false;
}


bool solveNightProble(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
          sol[i][j] = -1;
        }
    }
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
   int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    sol[0][0] = 0;
    if(sovledNightTour(0, 0, 1,  sol, xMove, yMove) == false){
        cout << "Solution is not possible" << endl;
        return false; 
    } else{
        displayMove();
       
    }

     return true;

}

int main(){
    solveNightProble();
}