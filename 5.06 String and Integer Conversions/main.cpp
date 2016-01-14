/* 5.6 String and Integer conversions */ 
#include <iostream>
#include <string>
using namespace std; 


string intToString(int x){
	string s; 
	bool isNegative = false; 
	if(x < 0){
		x = -1 * x;
		isNegative = true;
	}
	while(x){
		s.push_back('0'+x%10) ; 
		x = x/10 ;
	}
	if(s.empty()){
		return "0"; 
	}else{
		if(isNegative){
			s.push_back('-');
		}
		reverse(s.begin(), s.end());
	}
	return s; 

}

int stringToInt(string s){
	int x = 0; 
	bool isNegative = false;
	int i ; 
	if(s[0] == '-'){
		isNegative = true; 
		i = 1; 
	}
	for(; i < s.size(); i++){
		x = x*10 + (s[i]-'0'); 
	}
	if(isNegative){
		return -1*x; 
	}
	return x;

}

int main(){
	cout << intToString(1993) << endl; 
	cout << stringToInt("1993") << endl; 
	cout << intToString(-123) << endl; 
	cout << stringToInt("-123") << endl; 

	return 0; 

}

