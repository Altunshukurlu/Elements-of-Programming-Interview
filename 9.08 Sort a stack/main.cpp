/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <stack>

using namespace std; 

void insert(int val, stack<int> *s){
	if(s->empty() || s->top() <= val){
		s->push(val);
	}else{
		int curr = s->top();
		s->pop();
		insert(val, s);
		s->push(curr);

	}


}
void sort(stack<int> *s){
	if(!s->empty()){
		int curr = s->top();
		s->pop();
		sort(s);
		insert(curr, s);	
	}

}

int main(){
	stack<int> s; 
	for(int i = 0; i < 12; i++){
		int x = rand()%30 + 1 ;
		s.push(x);
		cout << x << " " ;
	}
	cout << endl;
	sort(&s);
	cout << "Stack" << endl;
	while(!s.empty()){
		cout << s.top() << " " ;
		s.pop();
	}
	cout << endl;
	return 1; 
}

