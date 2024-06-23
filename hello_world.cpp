#include <iostream>
using namespace std;

int main()
{ 
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  
  int a, b, c; 

  cout << "Enter three values for which you want to generate maximum \n"; 
  cin >>a>>b>>c;
  
  if (a > b){
    if(c > a){
       cout << "Maximum values c \n";
    } else{
       cout << "Maximum values a \n";
    }
  } else{
    if(c > b){
       cout << "Maximum values c \n";
    } else{
       cout << "Maximum values b \n";
    }
  }
  
  return 0;
}