#include<iostream>
#include<cstring>

using namespace std;

long long int dp[47][2][47][47];
int n;
long long int calculate(int index, int lastblue,int lastwhite,int lastred);

int main(){
	cin>>n;
	memset(dp,-1,sizeof(dp));
	long long ans = 0;
	ans+=calculate(1,0,0,-1);
	ans+=calculate(1,0,-1,0);
	cout<<ans<<endl;
}

long long int calculate(int idx,int lb,int lw,int lr){
	if(idx==n)
	return 1;
	if(dp[idx][lb][lw][lr]!=-1)
	return dp[idx][lb][lw][lr];
	long long int &ans = dp[idx][lb][lw][lr];
	ans=0;
	if(lb==1){
		if(lw>lr)
		ans=calculate(idx+1,0,lw,idx);
		else
		ans=calculate(idx+1,0,idx,lr);
		return ans;
	}
	if(lr>lw){
		if(idx+1!=n)
		ans+=calculate(idx+1,1,lw,lr);
		ans+=calculate(idx+1,0,idx,lr);
		return ans;
	}
	else{
		if(idx+1!=n)
		ans+=calculate(idx+1,1,lw,lr);
		ans+=calculate(idx+1,0,lw,idx);
		return ans;		
	}
}
