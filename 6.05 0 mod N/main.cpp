/* 6.05 0 mod N */ 

#include <iostream>
#include <string>
#include <vector> 

using namespace std; 


void print_vector(vector<int> A){
	int n = A.size();
	for(int i = 0; i < n; i++){
		cout << A[i] % n << " "; 
	
	}
	cout << endl ;
}

int find_subset(vector<int> A){
	int n = A.size(); 
	int B[n];
	int flag[n];
	for(int i = 0; i < n; i++){
		flag[i] = -1; 
	}
	
	B[0] = A[0] % n; 
	if(B[0] == 0){
		return 0; 
	}
	flag[B[0]] = 1; 
	
	for(int i = 1; i < n; i++){
		B[i] = (B[i-1] + A[i]) % n; 
		if(B[i] == 0){
			return i; 
		}
		if(flag[ B[i] ] != -1){
			cout << flag[B[i]] << ".." << i << endl; 
			return -2; 
		}else{
			flag[B[i]] = i; 
		}
		
	}
	
	return -1; 
	

}

int main(){
	vector<int> A = { 4, 2, 1, 1, 1} ;
	print_vector(A); 
	cout << find_subset(A) << endl; 
	return 1; 
}

