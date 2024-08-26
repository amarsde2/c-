#include<bits/stdc++.h>
using namespace std;
int getSize(long x){
    int count = 0;

    while(x > 0){
        count++;
        x = x/10;
    }

    return count;
}

long kart(long x, long y){
    if(x < 10 && y < 10){
        return x *y;
    }

    int size = fmax(getSize(x),getSize(y));

    if(size < 10){
        return x*y;
    }

     size = size / 2 + size %2;

    int multiplier = pow(10, size);

    int b = x / multiplier;
    int a  = x - (b * multiplier);
    int d = y / multiplier;
    int c = y - (d * multiplier);
    int u = kart(a,c);
    int v = kart(b,d);
    int z = kart(a+b, c+d);

    return u + ((z- u - v) * multiplier + v *(long)pow(10, 2*size));

    
}




int main(){
    long a = 150, b = 10;
    long result; 
    result = kart(a,b);
    cout << result << endl;

    return 0;
}