#include<iostream>
using namespace std; 

int main(){
    int ns, roll, marks; 
    cout << "Enter numbers of students: \n";
    cin >> ns;
    int table[ns][2];
    
    for(int i = 0; i < ns; i++){
        cout << "Enter student roll number and marks" << endl;
        cin >> roll >> marks;
        table[i][0] = roll;
        table[i][1] = marks;
    }

    /* print information */ 

    for(int i = 0; i < ns; i++){
        cout << "Roll Number:  " <<  table[i][0] << " and marks " << table[i][1] << endl;
    }

    return 0;
}