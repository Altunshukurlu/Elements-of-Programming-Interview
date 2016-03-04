/* */ 

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map> 


using namespace std; 

bool canFormPalindromicPermutation(const string& s){
	unordered_map<char, int> map; 
	for(char c : s){
		map[c]++;
	}	

	for(const auto& p : map){
		if(p.second % 2 == 1){
			return false; 
		}
	}
	return true;

}

void test(const string& s){
	cout << s << " can"; 
	if(!canFormPalindromicPermutation(s)){
		cout << "not"; 
	}
	cout << " be palindromic" << endl;
}



int main(){
	test("xxaaa");
	return 1; 
}

