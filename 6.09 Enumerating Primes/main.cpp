/* 6.09 Enumerate all Primes to N */ 

#include <iostream>
#include <string>
#include <vector> 

using namespace std; 


void print_vector(vector<int> A){
	for(int i = 0; i < A.size(); i++){
		cout << A[i] << " "; 
	
	}
	cout << endl ;
}

vector<int> generatePrimes(int n){
	vector<int> primes;  //to store primes.
	
	vector<bool> isPrime(n+1, true);
	isPrime[0] = isPrime[1] = false; //since these are not primes;
	for(int i = 2; i <= n; i++){
		if(isPrime[i]){
			primes.emplace_back(i);
			for(int j = i; j <= n; j=j+i){
				isPrime[j] = false;
			}
		
		}
	
	
	}
	return primes;

}
int main(){
	vector<int> primes; 
	primes = generatePrimes(20);
	print_vector(primes);
	return 1; 
}

