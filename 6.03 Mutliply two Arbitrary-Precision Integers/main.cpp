/* 6.02 Increment an Arbitrary-Precision Integers */ 

#include <iostream>
#include <string>
#include <vector> 

using namespace std; 


void print_vector(vector<int> A){
	for(int i = 0; i < A.size(); i++){
		cout << A[i]; 
	
	}
	cout << endl ;
}

vector<int> multiply(vector<int> num1, vector<int> num2){
	bool is_negative = false; 
	if( (num1.front() < 0 && num2.front() >= 0) || 
		(num1.front() >= 0 && num2.front() < 0) ){
		is_negative = true;
	}
	num1.front() = abs(num1.front()) ;
	num2.front() = abs(num2.front()) ;
	
	vector<int> result(num1.size() + num2.size(), 0); 
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	
	for(int i = 0; i < num1.size() ; i++){
		for(int j = 0; j < num2.size() ; j++){
			result[i+j] += num1[i] * num2[j] ; 
			result[i+j+1] += result[i+j]/10; 
			result[i+j] %= 10; 
		}
	}
	//remove 0s in the beginning 
	while(result.size() != 0) {
		if(result.back() == 0){
			result.pop_back(); 
		}else{
			break;
		}	
	}
	
	reverse(result.begin(), result.end());
	if(is_negative){
		reverse.front() *= -1; 
	}
	print_vector(result); 
	
	return result;

}
int main(){
	vector<int> num1 = {1, 2, 3, 4};
	vector<int> num2 = {4, 8, 9};
	print_vector(num1); 
	print_vector(num2); 
	multiply(num1, num2); 
	return 1; 
}

