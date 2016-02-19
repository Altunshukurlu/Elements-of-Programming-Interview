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

void print_vector_with_mark(vector<int> a, int mark){
	if(mark < 0 || mark > a.size()-1){
		print_vector(a);
		cout << "NOT FOUND!" << endl;
	}else{
		for(int i = 0; i < a.size(); i++){
			if(i != mark){
				cout<< a[i] << " ";
			}else{
				cout<< "---" << a[i] << "--- "; 
			}
		}
		cout << endl;

	}

}
int SearchFirstGreaterThanK(vector<int> a, int k){
	int result = -1; 
	int left = 0; 
	int right = a.size() - 1; 
	while(left <= right){
		int mid = (left+right)/2; 
		if(a[mid] > k){
			result = mid; 
			right = mid-1; 
		}else{
			left = mid+1;
		}
	}
	return result;



}
int main(){
	cout << endl;
	
	vector<int> a{-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
	print_vector(a);
	print_vector_with_mark(a, SearchFirstGreaterThanK(a, 109));
	print_vector_with_mark(a, SearchFirstGreaterThanK(a, 285));
	print_vector_with_mark(a, SearchFirstGreaterThanK(a, -11));
	print_vector_with_mark(a, SearchFirstGreaterThanK(a, 500));

	cout << endl;
	return 1;
}

