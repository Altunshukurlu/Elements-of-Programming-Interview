/* */ 

#include <iostream>
#include <string>
#include <vector> 
using namespace std; 

#define STACK_MAX 100

class Stack {
	private:
		int data[STACK_MAX];
		int curr_max[STACK_MAX];
		int size; 
		
	public:
		Stack() {	//constructor
			size = 0;
		}
		~Stack() {} //destructor
		
		int peek(){
			if(size == 0){
				cout << "Empty stack" << endl;
				return -1;
			}
			else return data[size-1];
		}
		
		void push(int d){
			if(size < STACK_MAX){
				if(d > curr_max[size-1]){
					curr_max[size] = d; 
				}else{
					curr_max[size] = curr_max[size-1];
				}
				data[size++] = d; 
			}else{
				cout << "Stack is full" << endl;
			}
		}
		
		int pop() {
			if(size == 0){
				cout << "Empty stack" << endl; 
				return -1;
			}else{
				return data[--size];	
			}
		}
		
		int max() {
			if(size == 0){
				cout << "Empty stack" << endl; 
				return -1;
			}else{
				return curr_max[size-1];	
			}
		}
		//just for testing purposes.
		void print(){
			cout << "STACK-CURR MAX" << endl;
			for(int i = 0; i < size; i++){
				cout << data[i] << " " << curr_max[i] << endl;
			}
		}

};
int main(){
	cout << "hi" << endl;
	Stack stack; 
	for(int i = 0; i < 10; i++){
		int v = rand() % 30 + 1; 
		stack.push(v);
	}
	stack.print(); 

	return 1; 
}

