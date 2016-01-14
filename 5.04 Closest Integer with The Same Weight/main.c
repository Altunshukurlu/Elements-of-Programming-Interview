/* 5.4 Closest integer with the same weight */

#include <stdio.h>

long find_closest(long x){
	int i = 0; 
	for(i=0; i<63; i++){
		int first_bit = (x >> i) & 1 ;
		int second_bit = (x >> (i+1)) & 1; 
		printf("%d %d\n", first_bit, second_bit); 
		if(first_bit != second_bit){
			//swap those consecutive bits, that's our y. 
			x = x ^ ( 1<<i | 1<<(i+1) ); 
			return x; 
		}
	}
	return -1; //weight is not in the range. 
}

int main()
{
	long x = 1000;
	printf("Closest integer to %ld is %ld \n", x, find_closest(x)); 
	return 0; 

}
