#include<bits/stdc++.h>
using namespace std;

struct coods{
   double x, y;
};

struct sement {
   struct coods start, end;
};



coods getCoointrdinate(struct sement s1 , struct sement s2){
     
       double a1 = s1.start.x , b1 = s1.start.y;
       double a2 = s1.end.x , b2 = s1.end.y;
       double a3 = s2.start.x , b3 = s2.start.y;
       double a4 = s2.end.x , b4 = s2.end.y;

       double dominator =  (b4-b3) * (a2-a1) - (a4-a3) *(b2-b1);
       double nominator1 = (a4-a3)*(b1-b3) - (b4-b3) * (a1-a3);
       double nominator2 = (a2-a1)*(b1-b3) - (b2-b1) * (a1-a3);

        if(dominator == 0){
            return {INFINITY, INFINITY};
        }

        double u = nominator1 / dominator;
        double v = nominator2 / dominator;


        if(u >= 0 && u <= 1 && v>= 0 && v<=1){
           double a = a1 + u *(a2- a1);
           double b = b1 + u *(b2- b1);

           return {a , b};
        }

        return  {INFINITY, INFINITY};

}


int main(){
    struct sement s1 = {{ 1, 2 }, { 3, 2 }};
    struct sement s2 = {{ 2, 1 }, { 2, 3 } };

    struct coods codinate = getCoointrdinate(s1, s2);

    cout << codinate.x << " " << codinate.y << endl;

    return 0;
}