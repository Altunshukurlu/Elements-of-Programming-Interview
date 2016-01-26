/* 6.07 Buy and Sell a stock once */ 

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

int max_difference(vector<int> A){
	int max  = A[1] - A[0];
	int local_max = 0; 
	int local_min = A[0]; 
	for(int i = 1; i < A.size(); i++){
		if(A[i] >= A[i-1]){
			local_max = A[i] - local_min; 
		}
		else{
			if(local_max > max) max=local_max; 
			local_min = A[i]; 
		}
	}	

	return max ;
}
int main(){
	vector<int> A = {110, 115, 75, 95, 60, 70, 90, 30, 55, 50};
	print_vector(A); 
	cout << max_difference(A) << endl; 
	return 1; 
}

