#include<iostream>
using namespace std;

int main(){
   
    int n;
    cin >> n;
    
    int space = n-1;

    for(int i = 1; i <= n ; i++){
        for(int k = 1 ; k <= space ; k++){
          cout << "*";
        }
        for(int j = 1; j <= 2*i-1; j++){
            if(j == 1 || j == 2*i-1){
                cout << "*";
            } else{
                cout << " ";
            }
        }
        for(int k = 1 ; k <= space ; k++){
          cout << "*";
        }
        space--;
        cout << endl;
    }

    space = 1;
    for(int i = n; i >= 1; i--){
        for(int k = 1 ; k < space ; k++){
          cout << "*";
        }
        for(int j = 1; j <= 2*i-1; j++){
            if(j == 1 || j == 2*i-1){
                cout << "*";
            } else{
                cout << " ";
            }
        }
        for(int k = 1 ; k < space ; k++){
         cout << "*";
        }
        space++;
        cout << endl;
    }
    
    return 0;

}