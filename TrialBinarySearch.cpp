#include <iostream>
using namespace std;


int main(int argc, char **argv)
{
	/*
	 * T is number of test cases
	 * n is number of elements
	 * K is number to search for
	 * 
	 */
	 
	 
	int T,n,K,a[100],r[100];
	int i,j,p=0;
	int b,m,e,x;
	
	cout<<"Enter number of test cases: ";
	cin>>T;
	for(i=0;i<T;i++){
		cout<<"\nEnter number of elements, element to search for: ";
		cin>>n>>K;
		cout<<"\nEnter elements: ";
		for(j=0;j<n;j++){
			cin>>a[j];
		}
		
		b=0;e=n-1;
		
		while(b<=e){
			r[p]=-1;
			m=(b+e)/2;
			x=a[m];
			if(K>x)
				b=m+1;
			else if(K<x)
				e=m-1;
			else if(K==x){
				r[p]=1;
				break;
			}
		}
		p++;
	}
	cout<<"\nOutput:\n";
	for(i=0;i<T;i++){
		cout<<r[i]<<"\n";
	}
	
	
	
	return 0;
}
