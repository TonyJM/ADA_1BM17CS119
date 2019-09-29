#include <iostream>
#include <time.h>
using namespace std;

int main(){
	clock_t start,end;
	double time;
	int n,i,j,k,d,x=0;
    int adj[10][10]={0};
	int indeg[10]={0};
	cout<<"Enter no. of tasks: ";
	cin>>n;
    cout<<"Enter Tasks with Dependencies:\n";
	for(i=0;i<n;i++){
        cout<<"Task "<<i+1<<" : Enter Dependencies: ";
        d=-1;
        while(d!=0){
            cin>>d;
            if(d!=0){
                indeg[i]++;
                adj[d-1][i]=1;
            }
        }
	}

	cout<<"\nOrder of Tasks:\n";
	start=clock();

	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(indeg[j]==0){
                cout<<j+1<<"\t";
                indeg[j]--;
                x++;
                for(k=0;k<n;k++){
                    if(adj[j][k]==1)
                        indeg[k]--;
                }
            }
        }
	}
	if(x<n)
        cout<<"\nCannot Order All Tasks";

	end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";


/* Sample Input and Output:

Enter no. of tasks: 6
Enter Tasks with Dependencies:
Task 1 : Enter Dependencies: 6 5 0
Task 2 : Enter Dependencies: 4 5 0
Task 3 : Enter Dependencies: 6 0
Task 4 : Enter Dependencies: 3 0
Task 5 : Enter Dependencies: 0
Task 6 : Enter Dependencies: 0

Order of Tasks:
5       6       1       3       4       2

*/
}
