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

int find(vector<int> a){
	int left = 0; 
	int right = a.size()-1;
	while(left <= right){
		int mid = (left+right)/2; 
		int diff = a[mid] - mid; 
		if(diff == 0){
			return mid; 
		}else if(diff > 0){
			right = mid - 1; 
		}else{
			left = mid + 1; 
		}

	}

	return -1;

}
int main(){
	cout << endl;
	
	vector<int> a{-2, 0, 1, 2, 3, 6, 7, 9};
	print_vector(a);
	cout << find(a) << endl;



	cout << endl;
	return 1;
}

