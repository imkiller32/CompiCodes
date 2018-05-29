#include<bits/stdc++.h>
using namespace std;

int dp[1024][1024];

int sol(int i,int j,int a[])
{
	if(i>j)
	return 0;
	if(dp[i][j]!=-1)
	return dp[i][j];
	
	int sum1,sum2;
	if(a[i+1]>=a[j])
	sum1=a[i]+sol(i+2,j,a);
	else if(a[i+1]<a[j])
	sum1=a[i]+sol(i+1,j-1,a);
	
	if(a[i]>=a[j-1])
	sum2=a[j]+sol(i+1,j-1,a);
	else if(a[i]<a[j-1])
	sum2=a[j]+sol(i,j-2,a);
	
	if(sum1>sum2)
	dp[i][j]=sum1;
	else
	dp[i][j]=sum2;
	return dp[i][j];
}

int main()
{
	int game=0;
	while(1)
	{
		game++;
		int n,i,a[1001],sum1=0,sum2=0,sum=0,j;
		cin>>n;
		if(n==0)
		return 0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
		{
			dp[i][j]=-1;
		}
		for(i=0;i<n;i++)
		dp[i][i]=a[i];
		sum1=sol(0,n-1,a);
		sum2=sum-sum1;		
		cout<<"In game "<<game<<", the greedy strategy might lose by as many as "<<sum1-sum2<<" points.\n";
	}
}
