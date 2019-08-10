#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char **argv)
{
	/*
	 * T is number of test cases
	 * n is number of elements
	 * K is number to search for
	 * 
	 */
	 
	 
	int T,n,K,a[100];
	int i,j;
	int b,m,e,x;
	
	std::fstream f("/home/bmsce/Documents/Test.txt", std::ios_base::in);
	
	f>>T;
	for(i=0;i<T;i++){
		f>>n>>K;
		for(j=0;j<n;j++){
			f>>a[j];
		}
		
		b=0;e=n-1;
		
		while(b<=e){
			//r[p]=-1;
			m=(b+e)/2;
			x=a[m];
			if(K>x)
				b=m+1;
			else if(K<x)
				e=m-1;
			else if(K==x){
				//r[p]=1;
				cout<<"1\n";
				break;
			}
		}
		if(K!=x)
			cout<<"-1\n";
	}

	
	
	
	return 0;
}