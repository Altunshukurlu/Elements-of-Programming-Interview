/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <queue>

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

vector<vector<int>> depth(BSTNode *&L){
	vector<vector<int>> result ; 
	vector<int> oneLevel; 
	queue<BSTNode *> q; 
	q.emplace(L);
	int curr_num = q.size();
	
	while(!q.empty()){
		BSTNode* curr = q.front();
		q.pop();
		curr_num--; 
		
		if(curr){
			oneLevel.emplace_back(curr->data);
			q.emplace(curr->left);
			q.emplace(curr->right);
		}
		
		if(curr_num == 0){
			curr_num = q.size();
			if(!oneLevel.empty()){
				result.emplace_back(move(oneLevel));
			}
		}
	
	}
	
	return result;
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
	cout << "Tree: "; 
	print(root);
	cout << endl;
	
	cout << "depth" << endl;
	vector<vector<int>> result = depth(root);
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " " ; 
		}	
		cout << endl;
	}
	return 1; 
}

