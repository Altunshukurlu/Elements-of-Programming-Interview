/* 6.06 Delete duplicates from a sorted array */ 

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

vector<int> deleteDuplicas(vector<int> A){
	int key = A[0] - 1; 
	int pointer = 0; 
	
	for(int i = 0; i < A.size(); i++){
		if(A[i] != key){
			A[pointer++] = A[i]; 
			key = A[i]; 
		}
	}
 	while(pointer < A.size()){
 		A[pointer++] = 0;
 	}
	return A; 
}
int main(){
	vector<int> A = {2,2,2, 3, 5, 5,5,5,5,5,5, 7, 11, 11, 11, 13, 13};
	print_vector(A); 
	A =  deleteDuplicas( A); 
	print_vector(A) ;
	return 1; 
}

