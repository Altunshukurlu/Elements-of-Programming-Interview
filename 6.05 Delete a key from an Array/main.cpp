/* 6.05 Delete a key from an array */ 

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

vector<int> deleteKey(int key, vector<int> A){
	int pointer = 0 ;
	
	for(int i = 0 ; i < A.size() ; i++){
		if(A[i] != key){
			A[pointer] = A[i] ; 
			pointer ++ ; 
		}
	}
	
	while(pointer < A.size()){
		A[pointer++] = 0;
	}
	return A; 
}
int main(){
	vector<int> A = {1, 2, 2, 2, 3, 4, 2, 6, 7};
	print_vector(A); 
	A =  deleteKey(2, A); 
	print_vector(A) ;
	return 1; 
}

