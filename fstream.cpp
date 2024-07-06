#include<iostream>
#include<fstream>
using namespace std;

int main(){
    
    char data[1024];

    fstream mstream;
   
    // mstream.open("myfile.txt",ios::out)

    mstream.open("myfile.txt",ios::in);
    
    /*  used to write into file */
    /*  mstream <<  "3 Hello, world!" << endl */;
  
    mstream.seekg(5, ios::beg);

    mstream >> data;

    cout << data << endl;

    mstream.close();

    return 0;
    
}