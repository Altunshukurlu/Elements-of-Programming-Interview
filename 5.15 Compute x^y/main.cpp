/* */ 

#include <iostream>
#include <string>
#include <vector> 
using namespace std; 


double power(double x, int y){
	double res = 1.0; 
	long long power = y ;
	if(y < 0){
		power *= -1; 
		x = 1.0/x; 
	}
	
	while(power){
		if(power & 1) //if power is odd
			res *= x; 
		x *= x; 
		power = power >> 1; //divide power by 2
	}

	return res;


}
int main(){
	cout << power(3.0, 4) << endl;
	cout << power(3.0, 5) << endl;
	cout << power(3.0, 6) << endl;

	return 1; 
}

