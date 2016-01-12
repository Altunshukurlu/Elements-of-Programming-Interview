/* 5.4 Closest integer with the same weight */

#include <stdio.h>

long find_closest(long x){
	x = x ^ (!0); 
	x = x & !(x-1) ;
	return x; 
}

int main()
{

    return 0; 

}
