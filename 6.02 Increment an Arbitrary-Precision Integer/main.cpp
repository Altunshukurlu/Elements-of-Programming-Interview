/* 6.02 Increment an Arbitrary-Precision Integers */ 

#include <iostream>
#include <string>
#include <vector> 


using namespace std; 


void print_vector(vector<int> A){
	for(int i = 0; i < A.size(); i++){
		cout << A[i] << " "; 
	
	}
	cout << endl ;
}

vector<int> plus_one(vector<int> A){
	int n = A.size(); 
	int carry = 1; 
	for(int i=n-1; i >= 0; i--){
		A[i] = (A[i] + carry) % 10; 
		if(A[i] != 0){
			return A; 
		}
	}
	A.insert(A.begin(), 1)	;
	return A;
}

int main(){
	vector<int> A = {9, 9, 9, 9};
	print_vector(A); 
	A = plus_one(A); 
	print_vector(A); 
	return 1; 
}

