/* 5.7 Base Conversion */ 
#include <iostream>
#include <string>
using namespace std; 


int convert_to_decimal(string s, int b){
	bool isNegative = false; 
	int i = 0 ;
	if(s[0] == '-'){
		isNegative = true; 
		i = 1; 
	}
	int len = s.size(); 
	int output = 0 ;
	for(; i < len; i++){
		output = output*b + (s[i]-'0');
	}	
	if(isNegative) output *= -1 ;
	return output;
}

int digit_code(int x){
	if(x >= 0 && x <= 9){
		return x + '0'; 
	}
	if(x >= 10 && x <= 15){
		return x - 10 + 'A';
	}
	return -1; //not valid option 
}

string convert_decimal_to_base(int input, int b){
	bool isNegative = false; 
	if(input < 0 ){
		isNegative = true; 
		input *= -1; 
	}
	string output; 
	while(input){
		output.push_back(digit_code(input%b)); //put digit into output
		input = input/b; 
	}
	if(output.empty()){
		return "0" ;
	}	
	if(isNegative) output.push_back('-');
	reverse(output.begin(), output.end());
	return output;
}

string convert(string s, int base1, int base2){
		
		int input_in_decimal = convert_to_decimal(s, base1);
		return convert_decimal_to_base( input_in_decimal, base2 ) ; 

}

int main(int argc, char** argv){
	if(argc < 3){
		cout << "Function requires at least 2 arguments. First = number, Second = base"  << endl; 
		return -1; 
	}
	
	string decimal =  convert(argv[1], stoi(argv[2]), 10) ;
	
	for(int i = 2; i <= 16; i++){
		cout << "Base " << i << ": " << convert(decimal, 10, i) << endl; 
	}
	return 0; 
}

