/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <array>
using namespace std; 

struct endpoint{
		int val; 
		bool isClosed; 
};

struct interval{
	
	public: 
	
	bool operator<(const interval& i) const {
		if(left.val != i.left.val){
			return left.val < i.left.val; 
		}
		return left.isClosed && !i.left.isClosed ; 
	}
	
	void print(){
		if(left.isClosed){
			cout << "["; 
		}else{
			cout <<  "(" ; 
		}
		cout << left.val << "," << right.val ; 
		if(right.isClosed){
			cout <<   "] " ; 
		}else{
			cout << ") " ; 
		}
	}
	
	endpoint left, right;
};


void print(string s, vector<interval> in){
	cout << s; 
	for(int i = 0; i < in.size(); i++){
		in[i].print() ;
	}
	cout << endl;

}
vector<interval> unionOfIntervals(vector<interval> in)
{

	vector<interval> result ;
	sort(in.begin(), in.end()) ;
	
	result.emplace_back(in[0]);

	print("Sorted intervals: ", in);
	for(int i = 1; i < in.size(); i++){
		//cout << x.left.val << " " << x.right.val << endl; 
		//for testing purposes
		interval last = result[result.size()-1];
		interval curr = in[i];
		
		if(curr.left.val > last.right.val){ // (3,5)->(6,7)
			result.emplace_back(curr);
		}else{								// (3,5) vs (4,x) or (5,x) 
			if(curr.left.val == last.right.val){	// (3,5) vs (5,something)
				if(curr.left.isClosed || last.right.isClosed){ //if one is 
					result[result.size()-1].right = curr.right; 
				}else{ //(3,5) (5,6)
					//just ignore 
				}
			
			}else{
				if(curr.right.val > last.right.val){
					result[result.size()-1].right = curr.right;	
				}else{
					if(curr.right.val == last.right.val){
							result[result.size()-1].right.isClosed = (curr.right.isClosed || last.right.isClosed);
					}else{
						//do nothing 
						//3.7 .. 4.6
					}
				}
			}
		}
		
		print("Result: ", result);
		
	}


	return result;
}

int main(){
	vector<interval> set ; 
	set.emplace_back(interval{endpoint{7, true}, endpoint{8, false}}); 
	set.emplace_back(interval{endpoint{0, false}, endpoint{3, false}}); 
	set.emplace_back(interval{endpoint{3, true}, endpoint{4, false}}); 
	set.emplace_back(interval{endpoint{5, true}, endpoint{7, false}}); 
	set.emplace_back(interval{endpoint{8, true}, endpoint{11, true}}); 
	set.emplace_back(interval{endpoint{1, true}, endpoint{1, true}}); 
	set.emplace_back(interval{endpoint{2, true}, endpoint{4, true}}); 

	unionOfIntervals(set);
	return 1; 
	
}

