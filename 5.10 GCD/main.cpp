/* 5.9 Elias Gamma Encoding */ 

#include <iostream>
#include <string>
using namespace std; 

int gcd(int a, int b){
	if(a == 1 || b == 1) return 1; 
	if(a == 0 || b == 0) return a+b; 
	if(a < 0) a = -1*a; 
	if(b < 0) b = -1*b; 
	if(b > a) return gcd(b,a); 
	return gcd(a-b, b);
}

int main(int argc, char** argv){
	if(argc < 3){
		cout << "Enter two numbers" << endl ;
	}	
	cout << "GCD: " << gcd(stoi(argv[1]), stoi(argv[2])) << endl;

}

