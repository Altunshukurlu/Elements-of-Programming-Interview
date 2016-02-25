/* */ 

#include <iostream>
#include <string>
#include <vector> 
using namespace std; 

void print_vector(vector<int> a){
	for(int i = 0; i < a.size(); i++){
		cout << a[i] << " "; 
	}
	cout << endl;

}

vector<int> find_intersection(vector<int> a, vector<int> b)
{
	vector<int> result; 
	int idx_a = 0; 
	int idx_b = 0; 
	
	while(idx_a < a.size() && idx_b < b.size()){
		if(a[idx_a] == b[idx_b]){
			if(idx_a == 0 || a[idx_a - 1] != a[idx_a]){
				result.emplace_back(a[idx_a]);
			}
			idx_a++;
			idx_b++;
		}else if(a[idx_a] < b[idx_b]){
				idx_a++;
		}else{
				idx_b++;
		}
	}
	print_vector(result);
	return result; 



}

int main(){
	vector<int> a = {2, 3, 3, 5, 5, 6, 7, 7, 8, 12}; 
	vector<int> b = {5, 5, 6, 8, 8, 9, 10, 10};
	find_intersection(a, b); 
	return 1; 
}

