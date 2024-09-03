#include<bits/stdc++.h>
using namespace std;

/**
 * @brief demo for oops concept
 * @author Amar kumar
 * @cite Senior software engineer
 */


class Oops{ 

    /*private propertie*/
    string _name;
    int _age;
    int _contact_number;
    
    public:  
    /* default constructor */
    Oops(){
        cout << "Default Constructor create for class Oops" << endl;
    }

    /* paramenterized constructor*/
    Oops(string name, int age, int contact_number){
       _name = name;
       _age = age;
       _contact_number = contact_number;
    }

    /* copy constructor */

    Oops(const Oops &obj) { // Added const
        _name = obj.getName();
        _age = obj.getAge();
        _contact_number = obj.getContactNumber();
    }

    /* destructor*/

    ~Oops(){
        cout << "Oops destructor" << endl;
    }
    
    string getName() const{
       return _name;
    }

    void setName(string name){
        _name = name;
    }

    int getAge() const{
        return _age; 
    }

    void setAge(int age){
       _age = age;
    }
    
    int getContactNumber() const{ 
      return _contact_number;
    }
     
    void setContactNumber(int contact){
        _contact_number = contact;
    }


    /**
     * @brief compare two objects
     * @return boolean
     */

    bool operator ==  (Oops &b){
        return _name == b.getName() && _age == b.getAge() && _contact_number == b.getContactNumber();
    }


};


int main(){

    Oops defautObj;
    defautObj.setName("Amar");
    defautObj.setAge(28);
    defautObj.setContactNumber(1234567890);

    Oops paramter("Amar1", 28, 122132121);
   
    Oops copyc = defautObj;

    /* vector used to store collection of objects of Oops class */
    vector<Oops> objcollections;
    objcollections.push_back(defautObj);
    objcollections.push_back(paramter);
    objcollections.push_back(copyc);
   
    for(auto &a: objcollections){
        cout << a.getName() << " " << a.getAge() << " " << a.getContactNumber() << endl;
    }


    /**
     * Opeator overloading
     * @brief overwrite == operator
     */
     
    if(defautObj == paramter){
        cout << "Same object" << endl;
    } else{
        cout << "Not Same object" << endl;
    }

    return 0;
}