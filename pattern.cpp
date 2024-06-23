#include<iostream>
using namespace std;

int main(){
    
    /* simple pattern 
     
       * * * *
       * * * *
       * * * *
       * * * *
    */

    /* int r = 4, c = 4; 

    /* 
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
           cout << " * ";
        }
        cout << endl;
    }
    */


    /* simple pattern 
       1 2 3 4
       1 2 3 4 
       1 2 3 4
       1 2 3 4
    */

 
    /* for(int i = 0; i < r; i++){
        for(int j = 1; j <= c; j++){
           cout << " " << j << " " ;
        }
        cout << endl;
    }
    */

    /*
       print pattern 
       A B C D 
       A B C D
       A B C D 
       A B C D
    */

    /*
    int n = 5; 
    int start = 65;
     
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << " " << char(start) << " ";
            start++;
        }
        start = 65;
        cout << endl;
    }

    return 0;
    */

    /* 
       * 
       * * 
       * * * 
       * * * *
       * * * * *
    */

    /*
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < i+1; j++){
            cout << " " << "*" << " "; 
        }
        cout << endl;
    }
    */

    /* 
       1 
       A B 
       1 2 3 
       A B C D
       1 2 3 4 5
    */
    
    /*
    int start = 65;
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= i; j++){
            if(i % 2 == 0){
                cout << " " << char(start) << " "; 
                start++;
            } else{
                cout << " " << j << " "; 
            } 
        }
        start = 65;
        cout << endl;
    }
 
    */

    /*
      pattern 
      1
      1 3 
      1 3 5 
      1 3 5 7
    */

    /*
    
    for(int i = 1; i <= 5; i++){
      for(int j = 1; j <= i; j++){
         cout << " " << j*2 -1 << " ";
      }
      cout << endl;
    }
    
    */
    
    
    /*
      pattern 
      1
      2 3 
      4 5 6 
      7 8 9 10
    */
    
    /* 
    
    int start = 1;
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= i; j++){
            cout << " " << start++ << " ";
        }
        cout << endl;
    }
    */
    
    /*
    for(int i = 1 ; i <= 5; i++){
       for(int j = 1; j <= i; j++){
          if((i + j) % 2 == 0) cout << " " << 1 << " "; 
          else cout << " " << 0 << " "; 
       }
       cout << endl;
    }
    */
  
    /* 
    
    int n; 
    cout << "Enter a value of n : \n";
    cin >> n;
    
    for(int i = 1 ; i <= n; i++){
       for(int j = 1; j <= n; j++){
            if((n/2)+1 == j || (n/2) + 1 == i){
                cout << " " << "*"  << " ";
            } else{
                cout << " " << "#"  << " ";
            }
       }

       cout << endl;
    }
    */
    
    /*
    int r = 4, c = 6; 
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(i == 1 or j == 1 or i == r or j == c){
                cout << " " << "*" << " ";
            } else {
                cout << " "  << "-" << " ";
            }
        }

        cout << endl;
    }
    */
    
    /*
       *  -  -  -  * 
       -  *  -  *  -
       -  -  *  -  - 
       -  *  -  *  -
       *  -  - -   * 
    */
   
    /* 
    int n ; 
    cout << "Enter number n : \n";
    cin >> n;

    for(int i = 1; i <= n; i++){
       for(int j = 1; j <=n; j++){
          if(j == i || j == (n + 1 - i)) cout << " * ";
          else cout << " - ";
       }
       cout << endl;
    }
    */
    
    /*
       -  -  -  * 
       -  -  *  * 
       -  *  *  *  
       *  *  *  * 

    */

    /* 
    int n; 
    cout << "Enter number n : \n";
    cin >> n;
     
    for(int i = 1; i <= n; i++){   
        for(int j = 1; j <= n-i; j++){
            cout <<  " - ";
        }
        for(int k = 1; k <= i; k++){
            cout <<  " * ";
        }
        cout << endl;
    }
    */

    /*
            * 
          * * *
        * * * * *
      * * * * * * *
   
    */

    int n; 
    cout << "Enter number n : \n";
    cin >> n;

    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= n - i; j++){
            cout << "   ";
        }

        for(int k = 1; k <= 2 * i-1; k++){
            cout << " * ";
        }
    
        cout << endl;
    }     

    return 0;
}