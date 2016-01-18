/* 5.14 Dividing x by y using addition, subtraction and multiplication */ 

#include <iostream>
#include <string>
#include <algorithm> 

using namespace std; 

int divide(int x, int y){
	if(x < y) return 0; 
	return 1 + divide(x-y, y); 
}

int main(int argc, char** argv){
	
	if(argc < 3){
		cout << "Err: ./a.out x y" << endl ;
	}
	int x = stoi(argv[1]); 
	int y = stoi(argv[2]);
	cout << divide(x,y) << endl; 

}

