/* */ 

#include <iostream>
#include <string>
#include <sstream>
#include <vector> 
#include <queue> 
#include <math.h>
using namespace std; 

void medianOnlineData(vector<int> a){
	priority_queue<int, vector<int>, greater<int>> min; 
	priority_queue<int, vector<int>, less<int>> max; 
	
	int x; 
	for(int i = 0; i < a.size() ; i++){
		x = a[i] ; 
		
		if(min.empty()){
			min.push(x);
		}else{
			if(x >= min.top()){
				min.push(x);
			}else{
				max.push(x);
			}
		}
			//make sure size difference is always one or zero.
		if(min.size() > max.size() + 1){
				max.push(min.top());
				min.pop();
		}else if(max.size() > min.size()){
				min.push(max.top());
				max.pop();
		}
			
		double median = 0; 
		if(min.size() - max.size() == 1){
			median = 1.0 * min.top(); 
		}else{
			median = (min.top() + max.top()) / 2.0; 
		}
		cout << median << " "; 
	}	

	cout << endl;
}


int main(){
	vector<int> data = {1, 0, 3, 5, 2, 0, 1}; 
	medianOnlineData(data);
	
	return 1; 
}

