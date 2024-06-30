#include<iostream>
using namespace std;

class OverLoadInputoutPut{
public: 
	int feed;
	int inch;
    OverLoadInputoutPut(){
		feed = 0;
		inch = 0;
	}
    
	friend ostream &operator << (ostream &output, const OverLoadInputoutPut &obj){
		output << "Field of object feed: " << obj.feed << " \n inch: " << obj.inch << endl;
		return output;
	}

	friend istream &operator >> (istream &input, OverLoadInputoutPut &obj){
		input >> obj.feed>>obj.inch;
		return input;
	}
};

int main(){
    OverLoadInputoutPut obj;
    
	cin >> obj;
    
	cout << obj << endl;

	return 0;
}