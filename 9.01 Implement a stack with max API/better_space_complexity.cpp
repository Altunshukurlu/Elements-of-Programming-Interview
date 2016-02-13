/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <stack>

using namespace std; 

#define STACK_MAX 100

class Stack {
	public: 
		bool empty() const{
			return data.empty();
		}
		int max() const{
			if(empty()){
				throw length_error("Pop() : Empty stack");
			}
			return max_count.top().max;
		
		}
				
		int pop(){
			if(empty()){
				throw length_error("Pop() : Empty stack");
			}
			int pop = data.top();
			data.pop();
			int top_max = max_count.top().max; 
			if(pop == top_max){
				int& max_frequency = max_count.top().count; 
					if(max_frequency == 1){
						max_count.pop();
					}else{
						max_frequency--;
					}
			}
			return pop;	
		}		
		
		void push(int d){
			data.emplace(d);
			if(max_count.empty()){
					max_count.emplace(maxWithCount{d,1});			
			}else{
				const int current_max = max_count.top().max; 
				if(d == current_max){ //if this max is last max 
					int& max_frequency = max_count.top().count; 
					max_frequency++; 
				}else if(d > current_max){ // if there is a new max
					max_count.emplace(maxWithCount{d, 1});
				}else{
					//do nothing 
				}
			
			}
		}
		
	private:
		stack<int> data; 
		struct maxWithCount{
			int max; 
			int count; 
		};
		stack<maxWithCount> max_count; 
};

int main(){
	Stack st; 
	st.push(2);
	cout << st.max() << endl;
	st.push(2);
	cout << st.max() << endl;
	st.push(1);
	cout << st.max() << endl;
	st.push(4);
	cout << st.max() << endl;
	st.push(5);
	cout << st.max() << endl;
	st.push(5);
	cout << st.max() << endl;
	st.push(3);
	cout << st.max() << endl;
	st.pop(); 
	cout << "max : " << st.max() << endl;
	st.pop(); 
	cout << "max : " << st.max() << endl;
	st.pop(); 
	cout << "max : " << st.max() << endl;
	st.pop(); 
	cout << "max : " << st.max() << endl;
	st.pop(); 
	cout << "max : " << st.max() << endl;
	st.pop(); 
	cout << "max : " << st.max() << endl;

	return 1; 
}

