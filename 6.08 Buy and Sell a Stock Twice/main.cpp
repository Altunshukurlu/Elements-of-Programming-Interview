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

int sell_stock_twice(vector<int> A){
	int n = A.size();
	
	vector<int> phase1(n);
	int max_so_far = 0; 
	int min_price_so_far = A[0]; 
	for(int i = 0; i < n; i++){
		min_price_so_far = min( min_price_so_far , A[i] ) ;
		max_so_far = max( max_so_far, A[i] - min_price_so_far); 
		phase1[i] = max_so_far; 
	}
	print_vector(phase1);
	
	vector<int> phase2(n);
	max_so_far = 0; 
	int max_price_so_far = A[n-1]; 
	for(int i = n-1; i>=0; i--){
		max_price_so_far = max(max_price_so_far, A[i]);
		max_so_far = max(max_so_far, max_price_so_far - A[i]);
		phase2[i] = max_so_far;
	}
	print_vector(phase2);

	int total_max = 0; 
	for(int i=1; i <= n-3; i++){
		total_max = max (total_max, phase1[i] + phase2[i+1] ); 
	}
	
	return total_max ;
}
int main(){
	vector<int> A = {12, 11, 13, 9, 12, 8, 14, 13, 15};
	print_vector(A); 
	cout << sell_stock_twice(A) << endl; 
	return 1; 
}

