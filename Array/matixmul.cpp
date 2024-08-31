#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1 ,n2,n3; 

    cout << "Enter dimensions of matrix " << endl;

    cin >> n1 >> n2 >> n3;

    int m1[n1][n2], m2[n2][n3], sol[n1][n3];

    for(int i = 0 ; i < n1 ; i++){
        for(int j = 0 ; j < n2 ; j++){
           cin >> m1[i][j];
        }
    }
    
    for(int i = 0 ; i < n2 ; i++){
        for(int j = 0 ; j < n3 ; j++){
           cin >> m2[i][j];
        }
    }

    for(int i = 0 ; i < n1 ; i++){
        for(int j = 0 ; j < n3 ; j++){
           sol[i][j] = 0;
        }
    }
    

    for(int i = 0 ; i < n1 ; i++){
       for(int j = 0; j < n3; j++){
           for(int k = 0 ; k < n2; k++){
              sol[i][j] += m1[i][k] * m2[k][j];
           }
       }
    }

    for(int i = 0 ; i < n1 ; i++){
        for(int j = 0 ; j < n3 ; j++){
           cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;

}