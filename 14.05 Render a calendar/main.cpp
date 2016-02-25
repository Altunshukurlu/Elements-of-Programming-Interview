/* */ 

#include <iostream>
#include <string>
#include <vector> 
#include <array>
using namespace std; 


struct Event{
	int start; 
	int end; 
};

struct Endpoint{
	bool operator<(const Endpoint& e) const{
		if(time != e.time){
			return time < e.time; 
		}else{
			return (isStart && !e.isStart);
		}
	}	

	int time; 
	bool isStart; 
};

int findMaxSimultaneousEvents(vector<Event> A)
{
	vector<Endpoint> E ;
	for(Event e : A){
		E.emplace_back(Endpoint{e.start, true});
		E.emplace_back(Endpoint{e.end, false});
	}
	
	sort(E.begin(), E.end());
	
	for(int i = 0 ; i < E.size() ; i++){
		cout << E[i].time << "(" << (E[i].isStart ? "start" : "end") << "), "; 
	}
	cout << endl;
	
	int max = 0; 
	int curr = 0; 
	for(int idx = 0; idx < E.size(); idx++){
		if(E[idx].isStart){
			curr++; 
			if(max < curr) max = curr; 
		}else{
			curr--;
		}
	}
	
	cout << "MAX: " << max << endl;
	return max; 

}
int main(){
	vector<Event> A = {Event{1,5}, Event{2,7},Event{4,5},Event{6,10},Event{8,9}};
	findMaxSimultaneousEvents(A); 
	return 1; 
}

