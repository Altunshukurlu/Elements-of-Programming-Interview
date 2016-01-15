/* 5.13 Multiplying x and y using bitwise operations */ 

#include <iostream>
#include <string>
#include <algorithm> 

using namespace std; 


int add(int x, int y){
	
	//iterate till there is no carry
	while( y != 0){
            int carry = (x & y) ; //CARRY is AND of two bits
          
            x = x ^y; //SUM of two bits is A XOR B
          
            y = carry << 1; //shifts carry to 1 bit to calculate sum
    }
	return x; 
}
int main(int argc, char** argv){
	if(argc < 3){
		cout << "Err: ./a.out x y" << endl ;
	}
	int x = stoi(argv[1]); 
	int y = stoi(argv[2]);
	
	if(y > x){
		int temp = y; 
		y = x; 
		x = temp; 
	} 
	
	int result = 0; 
	while (y != 0){
		if(y&01){
			result = add(result, x); 
		}
		x = x << 1; 
		y = y >> 1; 
	}
	
	cout << result << endl; 
}

