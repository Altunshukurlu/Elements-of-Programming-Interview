/* 5.11 Enumerating Primes */ 

#include <iostream>
#include <string>
#include <vector>

using namespace std; 

void print(vector<int> a){
	for(int i = 0; i < a.size(); i++){
		cout << a[i] << " " ;
	}
	cout << endl; 

}

vector<int> primes(int n){
	vector<int> numbers(n-1); 
	for(int i = 0; i < n-1; i++){
		numbers[i] = i + 2; 
	}
	vector<int> primes;
	
	while(numbers.size()){
		int top = numbers.front(); 
		primes.push_back(top); 
		int composite = top; 
		while(composite <= n){
			vector<int>::iterator i = find(numbers.begin(), numbers.end(), composite); 
			if( i != numbers.end() )
				numbers.erase(i); 
			composite = composite + top; 
		}
	}

	return primes; 

}
int main(int argc, char** argv){
	if(argc < 2){
		cout << "Enter a number" << endl ;
	}	
	
	print(primes(stoi(argv[1]))); 
}

