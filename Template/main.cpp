/* */ 

#include <iostream>
#include <string>
#include <vector> 
using namespace std; 

struct node{
	int data; 
	node *next; 
};

void print_list(node *head){
	while(head){
		cout << head->data << " " ; 
		head = head->next; 
	}
	cout << endl; 
}

int main(){
	node *root; 
	node *second; 
	second = new node; 
	root = new node; 
	root->next = second;
	root->data = 4; 
	second->data =2; 
	second->next = 0; 
	print_list(root);
	return 1; 
}

