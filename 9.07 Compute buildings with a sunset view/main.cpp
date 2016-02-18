/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <stack>
#include <sstream>

#define BSIZE 10 
using namespace std; 

struct building {
	int id; 
	int height; 
};

void whoSeesSunset(building *b){
	stack<building> s; 
	for(int i = BSIZE-1; i>=0; i--){
		if(s.empty() || s.top().height > b[i].height){
			s.push(b[i]);	
		}else{
			while(!s.empty() && s.top().height <= b[i].height){
				s.pop();
			}
			s.push(b[i]);
		}
	
	}
	
	cout << "ID of buildings seeing the sunset : "; 
	while(!s.empty()){
		cout << s.top().id << " ";
		s.pop();
	}
	cout << endl;


}
int main(){
	building *b = new building[BSIZE];
	for(int i =0; i < BSIZE; i++){
		b[i].id = i; 
		b[i].height = rand()%9;
	}
	
	cout << "ID     : sun ";
	for(int i = 0; i < BSIZE; i++){
		cout << b[i].id << " ";
	}
	cout << endl;
	cout << "HEIGHT : sun ";

	for(int i = 0; i < BSIZE; i++){
		cout << b[i].height << " ";
	}
	cout << endl;
	
	whoSeesSunset(b);
	return 1; 
}

