#include<iostream>
using namespace std; 

class File {   
   public: 
      double getFileSize(); 
      File();
      ~File();
};

File::File(){
    cout << "Construct called" << endl;
}

File::~File(){
    cout << "Destruct called" << endl;
}

double File::getFileSize(){
    return 10.11;
}

int main(){

   File myFile;

   cout << myFile.getFileSize() << endl;

   return 0;

}