#include <iostream>
#include <time.h>
using namespace std;

int partition(int a[],int low,int high){
	int i,j,pivot;
	pivot=a[low];
	i=low+1;
	j=high;
	while(1){
		while(a[i]<=pivot && i<=high){i++;}
		while(a[j]>pivot && j>=low){j--;}
		if(i<j){
			a[i]=a[i]+a[j];
			a[j]=a[i]-a[j];
			a[i]=a[i]-a[j];
		}
		else{
			a[low]=a[j];
			a[j]=pivot;
			return j;
		}
	}
}

void quickSort(int a[],int low,int high){
	if(low<high){
		int pivot_pos=partition(a,low,high);
		quickSort(a,low,pivot_pos-1);
		quickSort(a,pivot_pos+1,high);
	}
}

int main(){
	int a[100],low=0,high,i;
	clock_t start,end;
	double time;
	cout<<"Enter no. of elements: ";
	cin>>high;
	cout<<"Enter elements: ";
	for(i=0;i<high;i++)
		cin>>a[i];

	start=clock();
	cout<<"\nQuick Sort:\n";
	quickSort(a,low,high-1);
	for(i=0;i<high;i++)
		cout<<a[i]<<"\t";
	end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";
}

