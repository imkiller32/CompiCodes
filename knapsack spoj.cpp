/*Knapsack Problem Spoj Topic: DP
Cpp practice code
Author- Ritesh Aggarwal
*/

#include<bits/stdc++.h>
using namespace std;

int Knapsack(int k,int v[],int w[],int n)
{
	int knap[n+1][k+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=k;j++)
			{
				if(i==0||j==0)
					knap[i][j]=0;
				else if(w[i-1]<=j)
					knap[i][j]=max(v[i-1]+knap[i-1][j-w[i-1]],knap[i-1][j]);
				else
					knap[i][j]=knap[i-1][j];
			}
	return knap[n][k];
}

int main()
{
	int n,k,i,v[2000],w[2000];
	cin>>k>>n;
	for(i=0;i<n;i++)
	{
		cin>>w[i]>>v[i];
	}
	cout<<Knapsack(k,v,w,n);
	
}
