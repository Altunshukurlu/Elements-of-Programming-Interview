/* */ 

#include <iostream>
#include <string>
#include <vector> 
using namespace std; 


void print_vector(vector<int> a){
	for(int i = 0; i < a.size(); i++){
		cout<< a[i] << " ";
	}
	cout << endl;
}

int findMin(vector<int> a){
	int left = 0; 
	int right = a.size() - 1 ;
	while(left <  right){
		int mid = (left+right)/2 ; 
		if(a[mid] > a[right]){  // min must be in right
			left = mid+1; 
		}else{
			right = mid; 
		}	
	
	}
	return left; 
}
int main(){
	cout << endl;
	
	vector<int> a{6, 7, 8, 0, 1, 2, 3, 4, 5};
	print_vector(a);
	cout << findMin(a) << endl;



	cout << endl;
	return 1;
}

