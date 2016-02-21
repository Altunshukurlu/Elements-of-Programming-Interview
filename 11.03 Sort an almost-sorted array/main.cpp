/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <queue> 

using namespace std; 


vector<int> sort_almost_sorted_array(vector<int> a, int k){
	vector<int> result ; 
	
	priority_queue<int,vector<int>,greater<int> > min_heap;
	for(int i = 0; i < k && i < a.size(); i++){
		min_heap.push(a[i]);	
	}
	
	for(int i = 0; i + k < a.size(); i++){
		result.emplace_back( min_heap.top() );
		min_heap.pop();
		min_heap.push(a[i+k]);
	}	

	while(!min_heap.empty()){
		result.emplace_back( min_heap.top() );
		min_heap.pop();
		
	}
	
	cout << "After: " << endl;
	for(int i = 0; i < a.size(); i++){
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "After: " << endl;
	for(int i = 0; i < result.size(); i++){
		cout << result[i] << " " ;
	}
	cout << endl;
	return result;
}

int main(){
	vector<int> a = {3, -1, 2, 6, 4, 5, 8}; 
	int k = 2 ;
	sort_almost_sorted_array(a, k) ;
	return 1; 
}

