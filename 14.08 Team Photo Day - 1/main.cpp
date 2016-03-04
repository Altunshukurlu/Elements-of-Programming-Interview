/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <array>
using namespace std; 

struct Player
{
	bool operator<(const Player& that) const{
		return h < that.h; 
	}

	int h; //height
};

bool validPlacementExists(vector<Player> A, vector<Player> B)
{
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	if(B[0] < A[0]){
		swap(A, B);
	}
	
	for(int i = 1; i < A.size(); i++){
		if( ! (A[i] < B[i]) )
			return false;
	}
	return true; 
}
int main(){
	vector<Player> A = {Player{1}, Player{2}, Player{3}, Player{4}, Player{5}};
	vector<Player> B = {Player{1}, Player{1}, Player{3}, Player{4}, Player{5}};
	cout << validPlacementExists(A, B) << endl;
	return 1; 
	
}

