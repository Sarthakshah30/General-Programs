#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int n;
vector< pair<int,int> > adj[50];

int dijkstra(int src,int dest);

int main(){
	int m;
	cin>>n>>m;
	for(int i = 0 ; i< m ; i++){
		int x,y,w;
		cin>>x>>y>>w;
		adj[x].push_back(make_pair(y,w));
	}
	int q;
	cin>>q;
	for(int i = 0 ; i< q ; i++){
		int src,dest;
		cin>>src>>dest;
		cout<<dijkstra(src,dest)<<endl;
	}
}

int dijkstra(int src,int dest){
	vector<int> dist(n,9999999);
	dist[src]=0;
	priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > > pq;
	pq.push(make_pair(0,src));
	while(!pq.empty()){
		pair<int,int> temp = pq.top(); pq.pop();
		int d = temp.first;
		int u = temp.second;
		if(dist[u]<d)
		continue;
		for(int i = 0 ; i < adj[u].size() ; i++){
			pair<int,int> adjacent = adj[u][i];
			if(dist[u]+adjacent.second < dist[adjacent.first]){
				dist[adjacent.first]=dist[u]+adjacent.second;
				pq.push(make_pair(dist[adjacent.first],adjacent.first));
			}
		}
		if(u==dest)
		return dist[u];
	}
	return -1;
}
