/* 5.8 Spreadsheet Column Encoding */ 
#include <iostream>
#include <string>
using namespace std; 

int ssDecodeColID(string s){
	int x = 0 ;
	for (char& c : s){ //only works C++11 extension
		x = x*26 + (c - 'A' + 1) ; 
	}
	return x; 

}

int main(int argc, char** argv){
	if(argc < 2){
		cout << "Function requires a column to convert"  << endl; 
		return -1; 
	}
	cout << ssDecodeColID(argv[1]) << endl; 
	
	
	
	
	return 0; 
}

