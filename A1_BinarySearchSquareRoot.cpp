#include <iostream>
#include <time.h>
using namespace std;

void sr(int n){
	clock_t start,end;
	start=clock();	
	int b=0,e=n,m,r;
	while(b<=e){
		m=(b+e)/2;
		if (m*m==n){
			r=m;
			break;
		}
		else if(m*m<n){
			b=m+1;
			r=m;
		}
		else if(m*m>n){
			e=m-1;
		}
	}
	cout<<"\nSquare root of "<<n<<" is "<<r;
	end=clock();
	double t=double(end-start)/double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<t<<"s\n";
}

int main(){	
	
	int n,k;
	cout<<"Enter number of iterations: ";
	cin>>k;
	
	for(int i=0;i<k;i++){
		cout<<"\nEnter number: ";
		cin>>n;
		sr(n);
	}
}
