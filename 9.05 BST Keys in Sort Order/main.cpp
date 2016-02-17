/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <stack>
#include <sstream>

using namespace std; 

struct BSTNode{
	int data; 
	BSTNode *left;
	BSTNode *right; 
};

void insert(BSTNode *&root, int data){
	if(root == NULL){
		BSTNode *temp = new BSTNode; 
		temp->data = data; 
		temp->left = NULL; 
		temp->right = NULL; 
		root = temp; 
	}else{
		if(data < root->data){
			insert(root->left, data); 
		}else{
			insert(root->right, data);
		}
	
	
	}
}

void print(BSTNode *root){
	if(root != NULL){
		print(root->left); 
		cout << root->data << " " ;
		print(root->right);
	}
}

void print_without_recursion(BSTNode *root){
	vector<int> result; 
	stack<BSTNode*> s; 
	BSTNode* curr = root; 
	while(!s.empty() || curr){
		if(curr){
			s.push(curr);
			curr = curr->left;
		}else{
			curr = s.top();
			s.pop();
			result.emplace_back(curr->data);
			curr = curr->right;
		}
	}
	
	cout << "Result" << endl;
	for(int i = 0; i < result.size(); i++){
		cout << result[i] << " " ;
	}
	cout << endl;
}
int main(){
	BSTNode* root = new BSTNode; 
	root->data = 43;
	root->left = NULL; 
	root->right = NULL; 
	insert(root, 23);
	insert(root, 37);
	insert(root, 29);
	insert(root, 31);
	insert(root, 41);
	insert(root, 47);
	insert(root, 53);

	print(root);
	cout << endl;
	print_without_recursion(root);
	return 1; 
}

