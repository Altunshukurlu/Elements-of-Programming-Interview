/* 5.1 Computing Parity */

#include <stdio.h>

typedef unsigned long int uint64_t;

int main()
{
	uint64_t x = 4223372036854775807LL;
	
	printf("Value of X: %lld\n", (long long)x);
	
	//combine all bits at the LSB
	x ^= x >> 32; 
	x ^= x >> 16; 
	x ^= x >> 8; 
	x ^= x >> 4; 
	x ^= x >> 2; 
	x ^= x >> 1; 
	
	//take the last bit
	x = x & 1; 
	
    printf("Parity of X: %lld\n", (long long)x);
    
    
    return 0; 

}


	