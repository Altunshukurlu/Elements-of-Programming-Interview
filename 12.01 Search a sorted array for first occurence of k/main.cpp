/* */ 

#include <iostream>
#include <string>
#include <vector> 
using namespace std; 

void print_array(int* array, int len){
	cout << "Array: " << endl;
	for(int i = 0; i < len; i++){
		cout << array[i] << "[" << i << "]" << " " ;
	}
	cout << endl;
}
int find_k(int start, int finish, int k, int* array){
	if(start == finish){
		if(array[start] != k)
			return -1; 
		else
			return start; 
	}

	int len = finish - start + 1 ; 
	int middle = (start+finish)/2; 
	if(array[middle] == k){
		//find the first occurence
		while(array[middle] == k && middle >= 0){
			middle-- ;
		}
		return middle+1;
	}else if(array[middle] < k){
		// look right
		return find_k(middle+1, finish, k, array);
	}else{
		//look left
		return find_k(start, middle-1, k, array);
	}
}

int main(){
	int a1[] = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
	int len = sizeof(a1)/sizeof(a1[0]);
	print_array(a1, len);
	cout << "108 at " << find_k(0, len-1, 108, a1) << endl;
	cout << "-14 at " << find_k(0, len-1, -14, a1) << endl;
	cout << "285 at " << find_k(0, len-1, 285, a1) << endl;
	cout << "401 at " << find_k(0, len-1, 401, a1) << endl;

	int a2[] = {5, 5, 5, 5, 5};
	print_array(a2, 5);
	cout << "5 at " << find_k(0, 5-1, 5, a2) << endl;

	return 1;
}

