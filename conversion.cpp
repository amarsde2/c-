#include<iostream>
#include<cmath>
#include<string>
using namespace std;


/* function to convert binary into decimal number */

int convertBinaryToDecimal(int num){
    
    int ans = 0;
    int start = 0;

    while(num > 0){
        int rem = num % 10;
        ans = ans  + rem * pow(2,start);
        num /= 10;
        start++;
    }
 
    return ans;
}


/* function to convert octal number into decimal */
int convertOctalToDecimal(int num){

    int ans = 0;
    int start = 0;

    while(num > 0){
        int rem = num % 10;
        ans = ans  + rem * pow(8,start);
        num /= 10;
        start++;
    }
 
    return ans;
    
}

int convertHexicalToDecimal(string hex){
    int ans = 0, start = 0;
    
    for(int i = hex.size() - 1; i >= 0; i--){
        if(hex[i] >= '0' && hex[i] <= '9'){
            ans = ans + (hex[i] - '0') * pow(16, start);
        } else{
            ans = ans + (int(hex[i]) - 'A' + 10) * pow(16,start);
        }
        start++;
    }

    return ans;
}


int convertDecimalToBinary(int num){
    int ans = 0, x = 1;

    while(x <= num){
        x *= 2;
    }
 
    x /= 2;

    while(x > 0){
        int lastDigit = num / x; 
        num -= x * lastDigit;  
        ans = ans * 10 + lastDigit;
        x /= 2;
    }

    return ans;
}

int convertDecimalToOct(int num){
    int x = 1, ans = 0;
    while(x  <= num) {
        x *= 8;
    }

    x /= 8;

    while(x > 0){
      int lastDigit = num / x;
      num -= x * lastDigit;
      ans = ans * 10 + lastDigit;
      x /= 8;
    }

    return ans;
}

string convertDecimalToHex(int num){
    int x = 1; 
    string out = "";
     
    while(x <= num){
        x *= 16;

    }

    x /= 16;

    while(x > 0){
        int lastDigit = num / x;
        num -= x * lastDigit;
        x /= 16;

        if(lastDigit <= 9){
            out = out + to_string(lastDigit); 
        } else{
            out.push_back('A' + lastDigit -10);
        }
    }
   
    return out;
}

int main(){
    int num, ans;
    string hex;
    cin >> num;
   // getline(cin, hex);

   /*
      ans = convertBinaryToDecimal(num);
      ans = convertOctalToDecimal(num);
      ans = convertHexicalToDecimal(hex);
      ans = convertDecimalToBinary(num);
      ans = convertDecimalToOct(num);
   
   */
    
    hex = convertDecimalToHex(num);
    

    cout << hex << endl;

    return 0;
}