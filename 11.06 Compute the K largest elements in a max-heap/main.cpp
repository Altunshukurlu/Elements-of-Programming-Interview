/* */ 

#include <iostream>
#include <string>
#include <sstream>
#include <vector> 
#include <queue> 
#include <math.h>
using namespace std; 



vector<int> largestK(vector<int> A, int k){

	struct HeapEntry {
		int index; 
		int value; 
	};
	priority_queue<HeapEntry, vector<HeapEntry>, function<bool(HeapEntry, HeapEntry)>>
	max([](const HeapEntry &a, const HeapEntry &b) -> bool {
		return a.value < b.value; 
	}); 
	
	vector<int> result; 
	max.push(HeapEntry{0, A[0]});
	for(int i = 0; i < k; i++){
		int idx = max.top().index; 
		result.emplace_back(max.top().value);
		max.pop(); 
		
		int left_idx = 2*idx + 1; 
		if(left_idx< A.size())
			max.push(HeapEntry{left_idx, A[left_idx]});
			
		int right_idx = 2*idx + 2; 
		if(right_idx < A.size())
			max.push(HeapEntry{right_idx, A[right_idx]});
	
	}
	
	cout << "Biggest " << k << " numbers:" << endl;
	for(int i = 0; i < result.size(); i++){
		cout << result[i] << " "; 
	}
	cout << endl;
	return result;

}
int main(){
	vector<int> heap = {1000, 600, 900, 500, 400, 501, 800, 7, 8, 9, 10, 11, 12, 13, 700}; 
	cout << "Heap:" << endl;
	for(int i = 0; i < heap.size(); i++){
		cout << heap[i] << " "; 
	}
	cout << endl;

	largestK(heap, 4);	
	return 1; 
}

