/* 5.4 Closest integer with the same weight */

#include <stdio.h>
#include <math.h> 

struct node {
	char *element; 
	struct node* prev; 
}; 

void power_set(char **S, int size, struct node *up){
	printf("power set called with %d \n", size); 
	struct node me; 
	
	if(size == 0){ //if size is zero
		while(up){
			printf("%s ", up->element) ;
			up = up->prev; 
		}	
		printf("\n"); 
	}else{
		me.element = *S; 
		printf("element is -%s-\n", me.element) ; 
		me.prev = up; 
		power_set(S+1, size-1, up); 
		power_set(S+1, size-1, &me); 
	
	}


}
int main(int argc, char **argv)
{
	power_set(argv+1, argc-1, 0) ;
	return 0; 

}
