/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <stack>
#include <sstream>

using namespace std; 

string shortestPath(const string& long_path){
	stringstream ss(long_path);
	stack<string> path; 
	string token;
	const char delim = '/';
	if(long_path.empty()){
		throw invalid_argument("Empty path is not valid");
	}
	while(getline(ss, token, delim)){
		if(token == ".."){
			if(path.empty()){
				throw invalid_argument("Path error");
			}else{
				path.pop();
			}
		}else if(token != "." && token != ""){
			path.emplace(token);
		}else{ 
			//just ignore if its . or /
		}
	}
	string result = ""; 
	while(!path.empty()){
		string next = path.top(); 
		result.insert(0, next+"/");
		path.pop();
	}
	return result;



}

int main(){
 	string s = "usr/lib/../bin/gcc";
 	cout << shortestPath(s) << endl;
 	 s = "scripts//./../scripts/awkscripts/././";
 	cout << shortestPath(s) << endl;
 	 s = "sc//./../tc/awk/././";
 	cout << shortestPath(s) << endl;

	return 1; 
}

