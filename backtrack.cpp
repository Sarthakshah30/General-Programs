/* Recursive Backtracking:-
	8 Queens Problems
	Sarthak Shah
*/
#include<iostream>
#include<algorithm>

using namespace std;

int col[8];
void backtrack(int c);
bool place(int c,int r);

int main(){
	backtrack(0);
}

void backtrack(int c){
	if(c==8){
		for(int i = 0 ; i< 8 ; i++)
		cout<<col[i]<<" ";
		cout<<endl;
	}
	for(int i = 0 ; i< 8 ; i++){
		if(place(c,i)){
			col[c]=i;
			backtrack(c+1);
		}
	}
}

bool place(int c,int r){
	for(int i = 0 ; i< c ; i++){
		if(col[i]==r || abs(col[i]-r) == abs(i-c))
		return false;	
	}
	return true;
}

