#include<iostream>
using namespace std;
 
class Minus{
    
    public:
        int x; 
        int y;

    Minus(int a, int b){
        x = a; y = b;
    }

    Minus operator-(){
        x = -x; y = -y;
        return Minus(x,y);
    }
};

int main(){
    
    Minus minx(-1,4);

    -minx;

    cout << minx.x << " " << minx.y << endl;

    return 0;
}

