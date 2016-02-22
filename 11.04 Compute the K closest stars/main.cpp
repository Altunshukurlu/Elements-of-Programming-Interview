/* */ 

#include <iostream>
#include <string>
#include <sstream>
#include <vector> 
#include <queue> 
#include <math.h>
using namespace std; 

struct Star {
	bool operator<(const Star& that) const {
		return Distance() < that.Distance(); 
	}
	
	double Distance() const{
		return sqrt(x*x + y*y + z*z); 
	}
	
	double x, y, z; 

};

vector<Star> FindClosestKStars(int k, string stars){
	stringstream ss(stars); 
	priority_queue<Star, vector<Star>> max_heap; 
	vector<double> data;
	data.reserve(3); 
	string buf;
	while(getline(ss, buf, ',')){
		for(int i = 0; i < 3; i++){
			data[i] = stod(buf); 
			getline(ss, buf, ',');
		}
		
		max_heap.emplace(Star{data[0], data[1], data[2]});
		if(max_heap.size() == k+1){
			max_heap.pop();
		}
	
	
	}
	
	vector<Star> closest_stars ; 
	while(!max_heap.empty()){
		closest_stars.emplace_back(max_heap.top());
		max_heap.pop();
	}
	
	reverse(closest_stars.begin(), closest_stars.end());
	
	for(int i = 0; i < closest_stars.size(); i++){
		cout << closest_stars[i].x << " " ;
	}
	cout << endl;
	return closest_stars; 


}


int main(){
	string stars = "1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7" ;
	FindClosestKStars(5, stars);
	return 1; 
}

