/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <queue>
#include <stack>

#define MAX_SIZE 5;  
using namespace std; 

class Queue{
	public:
		void enqueue(int x){
			s.emplace(x);
		}
		
		int dequeue(){
			if(s.empty()){
				throw length_error("Queue is empty!");
			}
			while(!s.empty()){
				temp.emplace(s.top());			
				s.pop();
			}
			int ret = temp.top();
			temp.pop();
			while(!temp.empty()){
				s.emplace(temp.top());			
				temp.pop();
			}
			return ret; 
		}
		
	private: 
		stack<int> s; 
		stack<int> temp; 
};

int main(){
	Queue q; 
	q.enqueue(4);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(57);
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	return 1; 
}

