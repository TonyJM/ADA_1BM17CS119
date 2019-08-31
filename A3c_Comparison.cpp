#include <iostream>
#include <time.h>
using namespace std;

int mergeCount=0;

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
		mergeCount++;
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
        mergeSort(b,p);
        mergeSort(c,q);
        Merge(b,p,c,q,a);
	}
}

int main(){
	clock_t start,end;
	double time;
	int n,i,j,min,t;
	int bblCount=0,selCount=0;
	cout<<"Enter no. of elements: ";
	cin>>n;
	int a[n],b[n],c[n];
	cout<<"Enter elements: ";
	for(i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}

	start=clock();
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(a[min]>a[j]){
				t=a[min];
				a[min]=a[j];
				a[j]=t;
			}
			selCount++;
		}
	}
	cout<<"\nSelection Sort: "<<selCount<<" Comparisons \n";
	for(i=0;i<n;i++)
        cout<<a[i]<<"\t";
	end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);///double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";

	start=clock();
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(b[j+1]>b[j]){
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}
			bblCount++;
		}
	}
	cout<<"\nBubble Sort: "<<bblCount<<" Comparisons \n";
	for(i=0;i<n;i++)
        cout<<a[i]<<"\t";
	end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);///double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";

	start=clock();

	mergeSort(a,n);

	cout<<"\nMerge Sort: "<<mergeCount<<" Comparisons \n";

	for(i=0;i<n;i++)
		cout<<a[i]<<"\t";
	end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";


}
