#include<iostream>
#include<algorithm>

using namespace std;

int array[500];
int n;
int kthSmallest(int k,int start,int end);
int partition(int start,int end);

int main(){
	cin>>n;
	for(int i = 0 ; i< n ;i++)
	cin>>array[i];
	int k;
	cin>>k;
	cout<<kthSmallest(k,0,n-1)<<endl;
}

int kthSmallest(int k,int start,int end){
	int pIndex=partition(start,end);
	if(pIndex+1==k)
	return array[pIndex];
	else if(pIndex+1 > k)
	return kthSmallest(k,start,pIndex-1);
	else
	return kthSmallest(k,pIndex+1,end);
}

int partition(int start,int end){
	int pIndex=start;
	int pivot=array[end];
	for(int i = start ; i<end ; i++){
		if(array[i]<=pivot){
			int temp=array[i];
			array[i]=array[pIndex];
			array[pIndex]=temp;
			pIndex++;
		}
	}
	int temp= pivot;
	array[end]=array[pIndex];
	array[pIndex]=pivot;
	return pIndex;
}

