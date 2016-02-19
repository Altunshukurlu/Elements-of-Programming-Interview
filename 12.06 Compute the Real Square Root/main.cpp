/* */ 

#include <iostream>
#include <string>
#include <vector> 
using namespace std; 
#define ERROR 0.00000001

long double sqrt(long double k){
	cout << "ERROR is " << ERROR << endl;
	long double left, right; 
	if( k < 1.0){
		 left = k; 
		 right = 1.0; 
	}else{
		 left = 1.0; 
		 right = k;
	}
	while( (right - left) > ERROR){
		cout << left << " " << right << endl;
		long double mid = (left + right) / 2; 
		long double mid_sq = mid * mid ; 
		if (mid_sq < k){
			left = mid ;
		}else if(mid_sq > k){
			right = mid; 
		}else{
			return mid; 
		}
	}
	return (right + left)/2;
}

int main(){
	cout << endl;

	cout << sqrt(226.0) << endl; 		
	cout << endl;
	return 1;
}

