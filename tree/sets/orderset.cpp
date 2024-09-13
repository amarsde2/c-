#include<iostream>
#include<set>
using namespace std;


int main(){
    set<int, greater<int>> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(8);
    s.insert(16);


    for(auto i: s){
        cout << i << " " << endl;
    }

    cout << *s.lower_bound(4) << endl;

    return 0;
}