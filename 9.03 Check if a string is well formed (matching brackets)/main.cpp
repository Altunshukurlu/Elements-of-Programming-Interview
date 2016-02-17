/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <stack>
#include <sstream>

using namespace std; 

bool isLeftBracket(char c){
	if(c == '{' || c == '[' || c == '(')
		return true;
	return false;
}

bool bracketsMatch(char c1, char c2){
	if(c1 == '{' && c2 == '}')
		return true;
	if(c1 == '(' && c2 == ')')
		return true;
	if(c1 == '[' && c2 == ']')
		return true;
	return false;

}
bool isWellFormed(const string& s){
	stack<char> left; 
	for(int i=0; i<s.size(); i++){
		if(isLeftBracket(s[i])){
			left.emplace(s[i]);
		}else{
			if(left.empty()) return false; 
			if(bracketsMatch(left.top(), s[i])){
				left.pop();
			}else{
				return false;
			}
		}
	}
	return left.empty();



}
int main(){
 	string s = "[()[]{()()}]";
 	cout << isWellFormed(s) << endl;
 	s="
	return 1; 
}

