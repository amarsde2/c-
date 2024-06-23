#include<iostream>
#include<vector>
#include<string>
#include<ctime>
using namespace std;

int main(){

    vector<int> marks;
    short int n;
    cout << "Enter numbers of elements in vector \n";
    cin >> n;

    cout << "Enter the number to store \n";
    for (int i = 0 ; i < n; i++){
        marks.push_back(i); 
    }

    cout << "Vector size: " << marks.size() <<endl;

    for(int i = 0 ; i < marks.size(); i++){
        cout << marks[i] << endl;
    }
  
    vector<int>::iterator  v  = marks.begin();

    while(v != marks.end()){

        cout << "Number to store: " << *v << endl;
        v++;
    }

    return 0;
}