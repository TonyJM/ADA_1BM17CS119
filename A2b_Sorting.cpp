#include <iostream>
#include <time.h>
using namespace std;

int main(){
	clock_t start,end;
	double time;
	int n,k,a[100],b[100],i,j,max,t;
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
		max=i;
		for(j=i+1;j<n;j++){
			if(a[max]<a[j]){
				t=a[max];
				a[max]=a[j];
				a[j]=t;
			}
		}
	}
	cout<<"\nSelection Sort:\n"<<k<<" largest elements:\n";
	for(i=0;i<k;i++)
		cout<<a[i]<<"\t";
	end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);///double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";
	
	start=clock();
	for(i=0;i<k;i++){
		for(j=0;j<n-1-i;j++){
			if(b[j+1]<b[j]){
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}
		}
	}
	cout<<"\nBubble Sort:\n"<<k<<" largest elements: \n";
	for(i=n-1;i>n-k-1;i--)
		cout<<b[i]<<"\t";
	end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);///double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";

}
