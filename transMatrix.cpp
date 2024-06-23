#include<iostream>
using namespace std;
#define N 4

void transpose(int A[][N], int B[][N]){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            B[i][j] = A[j][i];
        }
    }
}

int main(){
    
    int A[N][N] = {
        {1,1,1,1},
        {2,2,2,2},
        {3,3,3,3},
        {4,4,4,4}
    };
    
    int B[N][N];
    
    transpose(A, B);

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << B[i][j] << " " ;
        }
        cout << endl;
    }

}