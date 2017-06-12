#include<iostream>
#include<cstring>
#define INF -9999999;
using namespace std;


int dp[202][21];
int M,C;
int price[25][25];
int calculate(int budget,int index);

int main(){
	cin>>M>>C;
	for(int i = 0 ; i< C ; i++){
		cin>>price[i][0];
		for(int j = 1 ; j<=price[i][0] ; j++ ){
			cin>>price[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	int res = calculate(M,0);
	if(res<0)
	cout<<"No Solution"<<endl;
	else
	cout<<res<<endl;
} 

int calculate(int budget,int index){
	if(budget <0 )
	return INF;
	
	if(index==C){
		if(budget>=0){
			return (M-budget);
		}
	}
	
	if(dp[budget][index]!=-1)
	return dp[budget][index];
	
	for(int i = 1 ; i <=price[index][0] ; i++){
		dp[budget][index]=max(dp[budget][index],calculate(budget-price[index][i],index+1));
	}
	
	return dp[budget][index];
}
