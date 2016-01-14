/* 5.9 Elias Gamma Encoding */ 

#include <iostream>
#include <string>
using namespace std; 


string convert_to_elias(int n){
	string elias; 
	int len = -1; 
	while(n){
		elias.push_back('0'+ n%2); 
		n = n / 2;
		len ++;  
	}
	for(int i =0 ; i < len; i++){
		elias.push_back('0'); 
	}
	reverse(elias.begin(), elias.end()); 
	return elias; 
}

string encode(int* A, int n){
	string out; 
	for(int i = 0; i < n; i++){
		out.append(convert_to_elias(A[i])) ;
		//out.push_back(' ');  //this for testing purposes. 
	}
	return out;
}

int* decode(string in, int n){
	int * A = new int [n]; 
	int j;
	for(j=0; j < n; j++){
		A[j] = 0; 
	}
	
	int currentNumber = 0; 
	int index = 0
	; 
	while (index < in.size()){
		int len = 1; //length of the next integer
		while(in[index] == '0'){
			index ++ ;
			len ++ ; 
		}
		for(int i =index ; i < index+len; i++){
				A[currentNumber] = A[currentNumber] * 2 + (in[i] - '0') ;
		}
		currentNumber ++;
		index = index + len ; 
	}
	return A; 
}

int main(int argc, char** argv){
	int n = argc - 1; 
	int * A  = new int [n];
	for(int i = 0; i < n ; i++){
		A[i] = stoi(argv[i+1]); 
	}	
	cout << "Encoding: " << encode(A, n) << endl ;
	cout << "Decoding: "; 
	A = decode(encode(A, n), n);
	for(int j=0; j < n; j++){
		cout << A[j] << " "; 
	}
	cout << endl; 
	return 0; 
}

