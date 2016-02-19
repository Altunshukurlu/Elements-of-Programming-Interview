/* */ 

#include <iostream>
#include <string>
#include <vector> 
using namespace std; 
#define ERROR 0.00000001


struct MinMax {
	int min; 
	int max; 
};


// Time complexity is 3/2n-2. Whereas normal is 2n-2. 0.5n improvement
MinMax findminmax(const vector<int>& A){
	if(A.size() <= 1){
		return {A.front(), A.front()};
	}
	
	pair<int, int> global_min_max = minmax(A[0], A[1]);
	
	//process two at a time
	for(int i = 2; i+1 < A.size(); i=i+2){
		pair<int, int> local_min_max = minmax(A[i], A[i+1]);
		global_min_max = { min(global_min_max.first, local_min_max.first), 
							max(global_min_max.second, local_min_max.second) };	
	}
	if(A.size() % 2 == 1){
		
		global_min_max = { min(global_min_max.first, A.back()), 
							max(global_min_max.second, A.back()) };	

	}
	return {global_min_max.first, global_min_max.second};

}
int main(){
	vector<int> A{5, 3, 1, 4, 2, 7, 12, 2, 15, 26,7, 8,8,2,132, 0 };
	MinMax x = findminmax(A); 
	cout << x.min << " " << x.max << endl;
	return 1;
}

