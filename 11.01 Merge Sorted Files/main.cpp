/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <queue>
using namespace std; 

struct iter{
	bool operator<(const iter& that) const{
	
		return *current > *that.current; 
	}
	vector<int>::const_iterator current; 
	vector<int>::const_iterator end; 
};

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays)
{
	
	priority_queue<iter,vector<iter>> min_heap;
	
	for( const vector<int>& sorted_array : sorted_arrays ){
		min_heap.emplace( iter{sorted_array.cbegin(), sorted_array.cend()} ); 
	}
	
	
	vector<int> result ;
	while(!min_heap.empty()){
		auto smallest_array = min_heap.top(); 
		min_heap.pop();
		
		if(smallest_array.current != smallest_array.end){
		
			result.emplace_back(*smallest_array.current);
			min_heap.emplace( iter{next(smallest_array.current), smallest_array.end});
		
		}

	}
	
	cout << "Sorted and Merged" << endl;
	for(int i = 0; i < result.size(); i++){
		cout << result[i] << " " ;
	}
	cout << endl;
	return result;
}

int main(){
   	//priority_queue<int,vector<int>,greater<int> > q;
	vector<vector<int>> arrays ;
	
	vector<int> a1 = {3,5,7};
	vector<int> a2 = {0,6};
	vector<int> a3 = {0,6,28};
	arrays.emplace_back(move(a1));
	arrays.emplace_back(move(a2));
	arrays.emplace_back(move(a3));
	cout << "Arrays to sort" << endl;
	for(int i = 0; i < arrays.size(); i++){
		for(int j = 0; j < arrays[i].size(); j++){
			cout << arrays[i][j] << " "; 
		}
		cout << endl;
	}
	cout << endl;
	
	MergeSortedArrays(arrays);
	return 1; 
}

