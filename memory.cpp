#include<iostream>
using namespace std;

class Box{
    public:
       Box(){
        cout << "Constructed" << endl;
       }

       ~Box(){
         cout << "Destroyed" << endl;
       }
};

int main(){
    
    Box *box = new Box[4];

    delete[] box;

    return 0;
}