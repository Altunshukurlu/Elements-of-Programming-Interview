/* 5.2 Swap Bits */

#include <stdio.h>
long swap_bits(); 

int main()
{
	printf("New value is %ld \n", swap_bits(147, 4, 2)); 

    return 0; 

}

long swap_bits(long x, int i, int j){
	//first compare if these two bits differ
	//otherwise just return x; 
	int bit_i = (x >> i) & 1 ; 
	int bit_j = (x >> j) & 1 ;
	
	//swap two bits
	if(bit_i != bit_j){
		x = x ^ ( (1L << i) | (1L << j) ) ; 
	}
	
	return x; 

}
	