#include<iostream>
using namespace std;

void fabSeries(int num){
   
    int i = 0, j = 1, nextStep;
    
    for(int k = 2; k < num; k++){
        cout << i << endl;
        nextStep = i + j;
        i = j; 
        j = nextStep;
    }

    return;
}

int main(){
    
    int num;

    cout << "Enter a number till you want to print series \n" ;
    cin >> num;
    
    fabSeries(num);

    return 0;
}