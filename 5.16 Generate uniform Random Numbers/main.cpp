/* */ 

#include <iostream>
#include <string>
#include <vector> 
using namespace std; 


int randomOneZero(){
	return rand()%2; 

}

int generateRandom(int a, int b){
	int total_num = b-a+1; 
	int result = total_num; 
	
	while(result >= total_num){
		result = 0; 
		for(int i = 0; (1 << i) < total_num; i++){
			result = (result << 1) | randomOneZero() ; 
		}
		
	}
	
	return result + a;



}
int main(){
	for(int i = 1; i < 10; i ++ ){
		cout << generateRandom(4, 6) << endl;
	}
	return 1; 
}

