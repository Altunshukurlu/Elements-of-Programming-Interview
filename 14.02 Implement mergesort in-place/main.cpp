/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <array>
using namespace std; 

void print(int a[], int size){
	for(int i = 0; i < size; i++){
		cout << a[i] << " "; 
	}
	cout << endl;

}

void inPlaceMergeSort(int A[], int m, int B[], int n){
	int i = m-1; 
	int j = n-1; 
	int write_idx = m+n-1; 
	
	while(i >= 0 && j >=0 ){
		if(A[i] < B[j]){
			A[write_idx--] = B[j--]; 
		}else{
			A[write_idx--] = A[i--]; 
		}
	}
	
	while( j >= 0){
		A[write_idx--] = B[j--] ;
	}
	
	print(A, m+n);
	
}

int main(){
	int m = 3; 
	int n = 4; 
	int a[m+n];
	int b[n]; 
	a[0] = 5; a[1] = 13; a[2] = 17; 
	b[0] = 3; b[1] = 7; b[2] = 11; b[3] = 19; 
	inPlaceMergeSort(a, m, b, n);
	return 1; 
}

