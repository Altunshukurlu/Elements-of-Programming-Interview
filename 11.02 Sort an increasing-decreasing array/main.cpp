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

vector<int> SortKIncreasingDecreasingArray(vector<int> A){
	vector<vector<int>> sorted_subarrays; 
	
	bool isIncreasing = true; 
	int start = 0;  
	int i ; 
	for(i = 1; i < A.size(); i++){
		if(isIncreasing){
			while(i < A.size() && A[i-1] < A[i]){
				i++;
			}
			sorted_subarrays.emplace_back(A.begin() + start, A.begin() + i);
			start = i; 
			isIncreasing = false; 
		}else{
			while(i < A.size() && A[i-1] >= A[i]){
				i++; 
			}
			sorted_subarrays.emplace_back(A.rbegin() + A.size() - i, A.rbegin() + A.size() - start); 
			start = i; 
			isIncreasing = true; 
		}
	}
	for(i = 0; i < sorted_subarrays.size(); i++){
		for(int j = 0; j < sorted_subarrays[i].size(); j++){
			cout << sorted_subarrays[i][j] << " " ; 
		}
		cout << endl;
	}
	
	return MergeSortedArrays(sorted_subarrays);
}

int main(){
	vector<int> a  = {57, 131, 493, 294, 221, 339, 418, 452, 440, 220};
	SortKIncreasingDecreasingArray(a);
	return 1; 
}

