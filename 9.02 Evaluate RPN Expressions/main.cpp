/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <stack>
#include <sstream>

using namespace std; 

bool isOperand(string token){
	if(token.size() != 1){
		return false; 
	}
	char t = token.front();
	if(t == '+' || t == '-' || t == 'x' || t == '/')
			return true;
	return false;


}

int operation(int num1, int num2, string token){
	switch(token.front()){
		case '+':
			return num1+num2; 
		case '-': 
			return num1-num2; 
		case 'x':
			return num1*num2; 
		case '/':
			return num1/num2; 
	}
	return -1; 



}

int eval(const string& RPN){
	stack<int> s; 
	stringstream ss(RPN); 
	string token; 
	const char delim = ','; 
	
	while(getline(ss, token, delim)){
		if(isOperand(token)){
			
			int num2 = s.top(); 
			s.pop(); 
			int num1 = s.top(); 
			s.pop(); 
			s.emplace(operation(num1, num2, token));
		}else{
			s.emplace(stoi(token)); 
		}
	
	}

	return s.top(); 


}
int main(){

	string s = "3,4,+,2,x,1,+"; 
	cout << s << " ---- " << eval(s) << endl;
	s = "1,1,+,-2,x"; 
	cout << s << " ---- " << eval(s) << endl;
	s = "-641,6,/,28,/";
	cout << s << " ---- " << eval(s) << endl;
 
	return 1; 
}

