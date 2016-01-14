/* 5.12 Checking If Rectangles Intersect */ 

#include <iostream>
#include <string>
#include <algorithm> 

using namespace std; 

class Rectangle
{
	public:
		int x; 
		int y; 
		int h; 
		int w;
};

void print(Rectangle &R){
	cout << R.x << " " << R.y << " " << R.w << "" R.h << " ;" << endl;

}
bool isIntersect(Rectangle &R, Rectangle &S){
	if( S.y >= R.y + R.h || R.y >= S.y + S.h ){
		return false;
	}
	if( R.x >= S.x + S.w || S.x >= R.x + R.w ){
		return false; 
	}
	return true;


}

Rectangle intersection(Rectangle &R, Rectangle &S){
	Rectangle I; 
	if(isIntersect(R, S)){
		//determine y and Height 
		
		//case 1
		if(R.y+R.h > S.y || S.y + S.h > R.y){
			I.y = max(R.y, S.y);
			I.h = min(R.y+R.h, S.y+S.h) - max(R.y, S.y); 
		}
		
		//case 2
		if( (R.y+R.h >= S.y+S.h && S.y >= R.y) || (S.y+S.h >= R.y+R.h && R.y >= S.y)  ){
			I.y = max(R.y, S.y); 
			I.h = min(R.h, S.h) ;
		}
		
		//determine x and Width
		//case 1
		if(R.x+R.w > S.x || S.x + S.w > R.x){
			I.x = max(R.x, S.x);
			I.w = min(R.x+R.w, S.x+S.w) - max(R.x, S.x); 
		}
		
		//case 2
		if( (R.x+R.w >= S.x+S.w && S.x >= R.x) || (S.x+S.w >= R.x+R.w && R.x >= S.x)  ){
			I.x = max(R.x, S.x); 
			I.w = min(R.w, S.w) ;
		}
		return I; 		
	}	
	I.x = 0; I.y = 0; I.w = 0; I.h = 0; 
	return I; 
}
int main(int argc, char** argv){
	if(argc < 9){
		cout << "Err: R1.x R1.y R1.width R1.height R2.x R2.y R2.width R2.height" << endl ;
	}
		
	Rectangle R, S;

	R.x = stoi(argv[1]); 
	R.y = stoi(argv[2]); 
	R.w = stoi(argv[3]); 
	R.h = stoi(argv[4]); 
	
	S.x = stoi(argv[5]); 
	S.y = stoi(argv[6]); 
	S.w = stoi(argv[7]); 
	S.h = stoi(argv[8]); 
	
	cout << isIntersect(R, S) << endl; 
}

