#include<iostream>
using namespace std;

int main() {

    int matrA[2][2] = {1,2,3,4};
    int matrB[2][2] = {1,2,3,4};
    int matrC[2][2];

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            matrC[i][j] = matrA[i][j] + matrB[i][j];
        }
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
           cout << matrC[i][j] << endl;
        }
    }
    
    return 0;
}