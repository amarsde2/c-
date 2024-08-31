#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    char arr[n+1];
    cin.getline(arr,n);
    cin.ignore();
    int maxLength = 0;
    int count = 0;
    
    int i = 0;
    while(1){
        
        if(arr[i] == ' ' || arr[i] == '\0'){
          maxLength = max(maxLength, count);
          count = 0;
        }

        if(arr[i] == '\0'){
            break;
        }

        count++;
        i++;
    }

    cout << maxLength << endl;
    return 0;
}