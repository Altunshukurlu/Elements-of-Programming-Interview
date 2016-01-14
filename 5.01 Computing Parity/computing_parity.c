/* 5.1 Computing Parity */

#include <stdio.h>

typedef unsigned long int uint64_t;

int main()
{
	uint64_t x = 14;
	
	printf("Value of X: %lld\n", (long long)x);
	
	//combine all bits at the LSB
	x ^= x >> 32;  //XOR's first 32 bits with last 32 bits, stores in x 
	x ^= x >> 16;  //same fashion 
	x ^= x >> 8; 
	x ^= x >> 4; 
	x ^= x >> 2; 
	x ^= x >> 1; 
	
	//take the last bit
	x = x & 1; 
    printf("Parity of X: %lld\n", (long long)x);
    
    
    return 0; 

}


	