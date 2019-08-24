#include <iostream>
#include <time.h>
using namespace std;

int main(){
	clock_t start,end;
	double time;
	int n,k,a[100],b[100],i,j,min,t;
	cout<<"Enter no. of elements: ";
	cin>>n;
	cout<<"Enter elements: ";
	for(i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	cout<<"Enter k: ";
	cin>>k;
	
	start=clock();
	for(i=0;i<k;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(a[min]>a[j]){
				t=a[min];
				a[min]=a[j];
				a[j]=t;
			}
		}
	}
	cout<<"\nSelection Sort:\nkth smallest element (k="<<k<<") is "<<a[k-1];
	end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);///double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";
	
	start=clock();
	for(i=0;i<k;i++){
		for(j=0;j<n-1-i;j++){
			if(b[j+1]>b[j]){
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}
		}
	}
	cout<<"\nBubble Sort:\nkth smallest element (k="<<k<<") is "<<b[n-k];
	end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);///double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";

}
