#include <iostream>
#include <time.h>
using namespace std;

#define N 9
#define S 3

bool findEmpty(int grid[N][N],int &r,int &c){
    for(r=0;r<N;r++){
        for(c=0;c<N;c++){
            if(grid[r][c]==0)
                return true;
        }
    }
    return false;
}

bool inRow(int grid[N][N],int r,int x){
    for(int c=0;c<N;c++){
        if(grid[r][c]==x)
            return true;
    }
    return false;
}

bool inCol(int grid[N][N],int c,int x){
    for(int r=0;r<N;r++){
        if(grid[r][c]==x)
            return true;
    }
    return false;
}

bool inBox(int grid[N][N],int sr,int sc,int x){
    for(int r=0;r<S;r++){
        for(int c=0;c<S;c++){
            if(grid[r+sr][c+sc]==x)
                return true;
        }
    }
    return false;
}


bool isSafe(int grid[N][N],int r,int c,int x){
    return !inRow(grid,r,x) && !inCol(grid,c,x) && !inBox(grid,r-r%S,c-c%S,x);
}


bool solve(int grid[N][N]){
    int r,c;
    if(!findEmpty(grid,r,c))
        return true;
    for(int x=1;x<=N;x++){
        if(isSafe(grid,r,c,x)){
            grid[r][c]=x;
            if(solve(grid))
                return true;
            grid[r][c]=0;
        }
    }
    return false;
}

void disp(int grid[N][N]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cout<<grid[i][j]<<"\t";
        }
        cout<<"\n";
    }
}


int main(){

	clock_t start,end;
	double time;

//    int grid[N][N]={
//        {0,0,3,4},
//        {3,4,0,0},
//        {0,0,4,3},
//        {0,3,2,0}
//    };

    int grid[N][N]{
        {0,0,0,2,6,0,7,0,1},
        {6,8,0,0,7,0,0,9,0},
        {1,9,0,0,0,4,5,0,0},
        {8,2,0,1,0,0,0,4,0},
        {0,0,4,6,0,2,9,0,0},
        {0,5,0,0,0,3,0,2,8},
        {0,0,9,3,0,0,0,7,4},
        {0,4,0,0,5,0,0,3,6},
        {7,0,3,0,1,8,0,0,0}
    };

    cout<<"Grid:\n";
    disp(grid);

    start=clock();

    cout<<"\nSolution:\n";
    solve(grid);
    disp(grid);

	end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";

}
