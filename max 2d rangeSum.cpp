#include<bits/stdc++.h>

using namespace std;

long long matrix[301][301];

int main(){
	int row,col;
	cin>>row>>col;
	for(int i = 0 ; i<row ; i++){
		for(int j = 0 ; j<col ; j++){
			cin>>matrix[i][j];
			if(i-1>0)
			matrix[i][j]+=matrix[i-1][j];
			if(j-1>0)
			matrix[i][j]+=matrix[i][j-1];
			if(i-1>0 && j-1>0)
			matrix[i][j]-=matrix[i-1][j-1];
		}
	}
	
	long long maximum=-9999999;
	for(int i = 0 ; i<row ; i++){
		for(int j = 0 ; j<col ; j++){
			for(int k=i ; k<row ; k++){
				for(int l=j ; l<col ; l++){
					long long subrect=matrix[k][l];
					if(j-1>0)
					subrect-=matrix[k][j-1];
					if(i-1>0)
					subrect-=matrix[i-1][k];
					if(i-1 >0 && j-1 >0)
					subrect+=matrix[i-1][j-1];
					maximum=max(maximum,subrect);
				}
			}
		}
	}
	cout<<maximum<<endl;
}
