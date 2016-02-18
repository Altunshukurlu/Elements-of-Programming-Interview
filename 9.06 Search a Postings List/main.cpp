/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <stack>
#include <sstream>

using namespace std; 


struct pnode{
	int data; 
	pnode *next;
	pnode *jump; 
};

//void compute(pnode *&L, int &order); 

void print(pnode* head){
	if(head){
		cout << head->data << " "; 
		print(head->next);
	}
}
pnode* newNode(int data, pnode* next){
	pnode* temp = new pnode; 
	temp->data = data ;
	temp->next = next ;
	temp->jump = NULL; 
	return temp;
}	

void compute(pnode *&L, int &order)
{
	if(L && L->data == -1){
		L->data = order++; 
		compute(L->jump, order);
		compute(L->next, order);
	}
}

void jump_order_with_stack(pnode *&L){
	int order = 0; 
	pnode* curr = L; 
	stack<pnode *> s; 
	s.push(L);
	while(!s.empty()){
		if(curr && curr->data == -1){
			curr->data = order++; 
			s.push(curr->next);
			curr = curr->jump;
		}else{
			curr = s.top();
			s.pop();
		}
	}
	
}
int main(){
	pnode* a0 = newNode(-1, NULL); 
	pnode* a1 = newNode(-1, NULL); 
	pnode* a2 = newNode(-1, NULL); 
	pnode* a3 = newNode(-1, NULL); 
	pnode* a4 = newNode(-1, NULL); 
	pnode* a5 = newNode(-1, NULL); 
	pnode* a6 = newNode(-1, NULL); 
	a0->next = a1; 
	a1->next = a2; 
	a2->next = a3; 
	a3->next = a4; 
	a4->next = a5; 
	a5->next = a6; 
	a0->jump=a2;
	a1->jump=a1;
	a2->jump=a3;
	a3->jump=a1;
	a4->jump=a6;
	a5->jump=a6;
	a6->jump=a6	;
	cout << "List: " ;
	print(a0);
	cout << endl;
//				Test recursion here 
// 	int order = 0; 
// 	compute(a0, order);
// 	cout << "Jump List: " ;
// 	print(a0);
// 	cout << endl;
jump_order_with_stack(a0);
	cout << "Jump: " ;
	print(a0);
	cout << endl;

	return 1; 
}

