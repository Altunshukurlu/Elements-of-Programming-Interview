/* */ 

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map> 


using namespace std; 

void print2D(vector<vector<string>> array){
	for(int i = 0; i < array.size(); i++){
		for(int j = 0; j < array[i].size(); j++){
			cout << array[i][j] << " ";
		}
		cout << endl;
	}

}
vector<vector<string>> FindAnagrams(const vector<string>& dictionary)
{
	unordered_map<string, vector<string>> map; 
	for(const string& s : dictionary)
	{
		string ss(s);
		sort(ss.begin(), ss.end());
		map[ss].emplace_back(s);
	}

	vector<vector<string>> result; 
	for(const auto&p : map){
		if(p.second.size() >= 2){
			result.emplace_back(p.second);
		}
	}

	print2D(result);
	return result;

}

int main(){
	vector<string> dict = {"debitcard", "levis", "silent", "badcredit", "lives", "freedom", "listen", "elvis", "money"};
	FindAnagrams(dict);
	return 1; 
}

