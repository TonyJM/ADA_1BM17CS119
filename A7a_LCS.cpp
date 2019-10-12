#include <iostream>
#include <time.h>


using namespace std;
#define N 10

void lcs(string s1,int n1,string s2,int n2){
	int a[n1+1][n2+1];
	int i,j;
	for(i=0;i<=n1;i++)
		a[i][0]=0;
	for(j=0;j<=n2;j++)
		a[0][j]=0;
	
	for(i=1;i<=n1;i++){
		for(j=1;j<=n2;j++){
			if(s1[i-1]==s2[j-1])
				a[i][j]=a[i-1][j-1]+1;
			else
				a[i][j]=max(a[i-1][j],a[i][j-1]);
		}
	}
	
	int r=1,alt=0;
	string old="";
	while(r==1){
		r=0;
		string res=old+"";
		i=n1;j=n2;
		while(i>0 && j>0){
			if(s1[i-1]==s2[j-1]){
				res=s1[i-1]+res;
				i--;j--;
			}
			else{
				if(a[i-1][j]==a[i][j-1] && a[i-1][j]!=0){
					old=res;
					n1=i;n2=j;
					r=1;
				}
				if(alt==0){
					if(a[i-1][j]>=a[i][j-1])
						i--;
					else
						j--;
				}
				else{
					if(a[i-1][j]<=a[i][j-1])
						j--;
					else
						i--;
					r=0;alt=0;
				}
			}
		}
		cout<<"LCS = "<<res<<"\n";
		if(r==1)
			alt=1;
	}
	 
}

int main(){
	clock_t start,end;
	double time;
	string s1,s2;
	int n1,n2;
	cout<<"Enter Strings : ";
	cin>>s1>>s2;
	n1=s1.size();
	n2=s2.size();
	start=clock();
	lcs(s1,n1,s2,n2);
	end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";
}
