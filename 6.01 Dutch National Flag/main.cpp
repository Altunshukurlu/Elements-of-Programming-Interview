/* 6.01 Dutch National Flag */ 

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
vector<int> sort(int pivot_index, vector<int> A){
	int pivot = A[pivot_index]; 
	int n = A.size(); 
	//structure as follows
	//bottom group : 0..smaller-1
	//middle group : smaller..equal-1
	//unclassified : equal..larger-1
	//large group  : large..A.size()-1
	int equal = 0, smaller = 0, larger = n; 
	while(equal < larger){
		if(A[equal] < pivot){
			swap(A[equal], A[smaller]);
			equal++; 
			smaller++;
		
		}else if(A[equal] == pivot){
			equal++; 	
		}else{ //A[equal] > pivot
			swap(A[equal], A[larger-1]);
			larger -- ; 
		}
	}
	return A; 
}

int main(){
	vector<int> A = { 1, 2, 3, 4, 3, 2 ,1, -1, 5, 6, 7};
	print_vector(A); 
	A =	sort(2, A); 
	print_vector(A); 
	return 1; 
}

