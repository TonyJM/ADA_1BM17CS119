//#include <stdio.h>
#include <iostream>
using namespace std;


int main(int argc, char **argv)
{
	int n,i,m;
	int a[100];
	
	cout<<"Enter number of integers: ";
	cin>>n;
	
	if(n>0){
		cout<<"Enter Numbers: ";
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		
		m=a[0];
		for(i=1;i<n;i++){
			if (a[i]>m){
				m=a[i];
			}
		}
		
		cout<<"Maximum = "<<m;
		
	}
	else{
		cout<<"Empty List";
	}
	
	
	return 0;
}
