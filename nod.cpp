#include<iostream>
using namespace std;

int main(){

    int num, count = 0;
    cout << "Enter a number to count digit: \n";
    cin >> num;

    while(num > 0) {
        num /= 10;
        count++;
    }

    cout << "Enter a number of digit: " << count << endl;

    return 0;
}