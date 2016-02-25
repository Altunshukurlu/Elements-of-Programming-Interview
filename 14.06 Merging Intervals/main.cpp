/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <array>
using namespace std; 

struct interval{
	int left; 
	int right; 

};

vector<interval> merge(vector<interval> set, interval x){
	
	for(int i = 0; i < set.size(); i++){
		cout << "[" << set[i].left << "," << set[i].right << "]" << " "; 
	}
	cout << endl;
	
	int i = 0; 
	vector<interval> result; 

	while( i < set.size() && x.left > set[i].right){
		result.emplace_back(set[i++]);
	}
	
	interval new_interval = interval{x.left, x.right}; 
	while( i < set.size() && set[i].left <= x.right ){
		new_interval.left = min(set[i].left, new_interval.left); 
		new_interval.right = max(set[i].right, new_interval.right); 
		i++;
	}
	result.emplace_back(new_interval);
	
	result.insert(result.end(), set.begin() + i, set.end());

	for(int i = 0; i < result.size(); i++){
		cout << "[" << result[i].left << "," << result[i].right << "]" << " "; 
	}
	

	cout << endl;
	return result;

}

int main(){
	vector<interval> set = {interval{-4,-1},interval{0,2},interval{3,6},interval{8,9},interval{11,15}};
	merge(set, interval{1,8});
	return 1; 
}

