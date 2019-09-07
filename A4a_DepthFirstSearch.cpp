#include <iostream>
#include <time.h>
using namespace std;

void DFS(int v,int adj[][10],int vis[],int n){
	vis[v]=1;
	for(int i=0;i<n;i++){
		if(adj[v][i]==1 && vis[i]==0){
			cout<<v+1<<" --> "<<i+1<<endl;
			DFS(i,adj,vis,n);
		}
	}
}


int main(){
	clock_t start,end;
	double time;
	int n,i,j;
	int adj[10][10]={0};
	int vis[10]={0};
	cout<<"Enter no. of vertices: ";
	cin>>n;
	cout<<"Enter adjacency matrix:\n";
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>adj[i][j];
		}
	}
	cout<<"\nConnected vertices in DFS Tree:\n";
	start=clock();
	
	for(i=0;i<n;i++){
		if (vis[i]==0){
			DFS(i,adj,vis,n);
		}
	}
	end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";
	
	
}

