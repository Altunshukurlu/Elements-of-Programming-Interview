/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <array>
using namespace std; 

//method 1: O(n) time but O(26) space
void countOccurences_withoutSort(string S)
{
	int alphabet[26] = {0}; 
	for(char c : S){
		int idx = c - 'a'; 
		alphabet[idx]++;
	}
	for(int i = 0; i < 26; i++){
		if(alphabet[i] != 0){
			cout << "(" << (char) (i+'a') << "," << alphabet[i] << "), "; 
		}	
	}

	cout << endl;


}


//method 2: O(n logn) time complexity with O(1) space
void countOccurences(string S)
{
	sort(S.begin(), S.end());
	
	char curr = S[0]; 
	int curr_count = 1; 
	for(int i = 1; i < S.size(); i++){
		while(S[i] == curr){
			i++;
			curr_count++;
		}
		cout << "(" << curr << "," << curr_count << "), " ;
		curr = S[i] ; 
		curr_count = 1; 
	
	}
	cout << endl;

}

int main(){
	string S = "bcdacebe";
	
	countOccurences(S);
	countOccurences_withoutSort(S);

	return 1; 
}

