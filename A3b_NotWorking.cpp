#include <iostream>
#include <time.h>
using namespace std;

void Merge(int b[],int p,int c[],int q,int a[]){
	int i=0,j=0,k=0;
	while(i<p && j<q){
		if(b[i]<=c[j]){
			a[k]=b[i];
			i++;
		}
		else{
			a[k]=c[j];
			j++;
		}
		k++;
	}
	if(i==p){
		while(j<q){
			a[k]=c[j];
			j++;k++;
		}
	}
	else{
		while(i<p){
			a[k]=b[i];
			i++;k++;
		}
	}
}

void mergeSort(int a[],int n){
	int p=n/2,q=n/2;
	if(n%2==1) q++;
	int b[p],c[q],i;
	if(n>1){
		for(i=0;i<p;i++)
			b[i]=a[i];
		for(i=0;i<q;i++)
			c[i]=a[i+p];
	}
	mergeSort(b,p);
	mergeSort(c,q);
	Merge(b,p,c,q,a);
}

int main(){
	int n,i;
	clock_t start,end;
	double time;
	
	/*
	cin>>n;
	cout<<floor(float(n)/2);
	cout<<ceil(float(n)/2);
	*/
	//
	/*
	int x[4]={1,3,5,6};
	int y[4]={2,4,7,8};
	int z[8];
	Merge(x,4,y,4,z);
	for(i=0;i<8;i++)
		cout<<z[i];
	*/
	//
	/*
	int x[4]={2,6,1,4};
	mergeSort(x,4);
	*/
	
	cout<<"Enter no. of elements: ";
	cin>>n;int a[n];
	cout<<"Enter elements: ";
	for(i=0;i<n;i++)
		cin>>a[i];
		
		
	//mergeSort(a,n);

	start=clock();
	cout<<"\nMege Sort:\n";
	
	mergeSort(a,n);
	
	for(i=0;i<n;i++)
		cout<<a[i]<<"\t";
	end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";
/*Test
	cin>>n;
	int b[n];
	for(i=0;i<n;i++){
		cin>>b[i];
	}
	cout<<"\n";
	for(i=0;i<n;i++){
		cout<<b[i]<<"\t";
	}
	 */
}

