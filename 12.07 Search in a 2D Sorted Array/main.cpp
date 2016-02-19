/* */ 

#include <iostream>
#include <string>
#include <vector> 
using namespace std; 
#define ERROR 0.00000001


bool find(vector<vector<int>> a, int k){
	int row = 0; 
	int col = a[0].size() - 1; 
	while(row < a.size() && col >= 0){
		if(a[row][col] > k){
			col--;
		}else if(a[row][col] < k){
			row++;
		}else{
			return true;
		}
	}

	return false; 
}

void find_k(vector<vector<int>> a, int k){
	if(find(a, k)){
		cout << k << " is in the 2d array!" << endl;
	}else{
		cout << k << " isn't in the array :( " << endl;
	}

}
int main(){
	vector<vector<int>> a { { -1, 2, 4, 4, 6 },
                              { 1, 5, 5, 9, 21 },
                              { 3, 6, 6, 9, 22 },
                              { 3, 6, 8, 10, 24 },
                              { 6, 8, 9, 12, 25 },
                              { 8, 10,12, 13, 40 },
                            };
	for(int row = 0; row < 6; row++){
		for(int col = 0; col < 5; col++){
			cout << a[row][col] << " "; 
		}
		cout << endl;
	}
	cout << endl;
	for(int i = 5; i < 10; i++)
		find_k(a, i);
	return 1;
}

