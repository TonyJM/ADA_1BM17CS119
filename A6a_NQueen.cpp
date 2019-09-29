#include<iostream>
#include<time.h>
using namespace std;
#define N 10

void disp(int a[N][N],int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout <<"\n";
    }
}

bool isValid(int a[N][N],int r,int c,int n) {
    for (int i = 0; i < c; i++)
        if (a[r][i])
            return false;
    for (int i=r, j=c; i>=0 && j>=0; i--, j--)
        if (a[i][j])
            return false;
    for (int i=r, j=c; j>=0 && i<n; i++, j--)
        if (a[i][j])
            return false;
    return true;
}

bool NQueen(int a[N][N], int c,int n) {
    if (c >= n)
        return true;
    for (int i = 0; i < n; i++) {
        if (isValid(a,i,c,n) ) {
            a[i][c] = 1;
        if (NQueen(a,c+1,n))
            return true;
        a[i][c] = 0;
        }
    }
    return false;
}

bool check(int n) {
    int a[N][N];
    for(int i = 0; i<n; i++)
    for(int j = 0; j<n; j++)
    a[i][j] = 0;
    if (NQueen(a,0,n) == false ) {
        cout << "No Solution";
        return false;
    }
    disp(a,n);
    return true;
}
int main() {
    clock_t start,end;
	double time;
    int n;
    cout<<"Enter no. of Queens (<=10): ";
    cin>>n;
    cout<<"\n";
    start=clock();
    check(n);
    end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";
}
