#include<bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int n, int v){
    if (v == 0) return 0;

    int res = INT_MAX;
    for (int i=0; i<n; i++){
        if (coins[i] <= v){
            int sub_res = minCoins(coins, n, v-coins[i]);
            if (sub_res != INT_MAX && sub_res + 1 < res)
                res = sub_res + 1;
        }
}
return res;
}
int main()
{
	int coins[20],n,v;
    cout<<"Enter no. of coins : ";
    cin>>n;
    for( int i =0;i<n;i++)
    {
        cout<<"Enter coin "<<i+1<<"'s value : ";
        cin>>coins[i];
    }
    cout<<"Enter value : ";
    cin>>v;
	cout << "Minimum coins required is : "<< minCoins(coins, n, v);
	return 0;
}
