#include <iostream>
#include <time.h>
#include <queue>
using namespace std;

void BFS(int k,int adj [][10],int vis[],int n){
    int i,v;
    vis[k]=1;
    queue <int> q;
    q.push(k);
    while(!q.empty()){
        v=q.front();
        for(i=0;i<n;i++){
            if(adj[v][i]==1 && vis[i]==0){
                q.push(i);
                vis[i]=1;
            }
        }
        cout<<q.front()+1<<"\t";
        q.pop();
    }
}


int main(){
	clock_t start,end;
	double time;
	int n,i,j,k;
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

	cout<<"Enter start vertex: ";
	cin>>k;

	cout<<"\nBreadth First Order:\n";
	start=clock();

    BFS(k-1,adj,vis,n);
	for(i=0;i<n;i++){
		if (vis[i]==0){
			BFS(i,adj,vis,n);
		}
	}
	end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";


}
