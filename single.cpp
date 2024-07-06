#include<iostream>
#include<csignal>
using namespace std;

void signalHandler(int sinNo){
    cout << "signalHandler " << sinNo << endl;
    exit(sinNo);
}

int main(){

    signal(SIGINT, signalHandler);


    while(1){
      cout << "Single running..."<< endl;
      raise(SIGINT);
    }

    return 0;
}
