/* 6.04 Advancing Through an Array */ 

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

bool possible_to_win(vector<int> A)
{
	int n = A.size() ; 
	int current_max = 0; 
	for(int i =0; i <= current_max && current_max < n; i++){
		if(current_max < A[i] + i){
			current_max = A[i] + i; 
		}
		cout << current_max << " " ; 
	}
	cout << endl ;
	
	if(current_max >= n-1) 
		return true; 
	return false;

}
int main(){
	vector<int> A = {3,2,0,0,2,0,1};
	print_vector(A); 
	cout << possible_to_win(A) << endl;
	return 1; 
}

