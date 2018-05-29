#include<bits/stdc++.h>
using namespace std;

int a[2100];
int dp[2100][2100];

int sol(int i,int j,int day)
{
	if(i>j)
	return 0;
	if(dp[i][j]!=-1)
	return dp[i][j];
	
	if(i==j)
	{
		dp[i][j]=a[i]*day;
		return dp[i][j];
	}
	int sum1,sum2;
	sum1=a[i]*day+sol(i+1,j,day+1);
	sum2=a[j]*day+sol(i,j-1,day+1);
	if(sum1>sum2)
	dp[i][j]=sum1;
	else
	dp[i][j]=sum2;
	return dp[i][j];
}


int main()
{
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];

	for(i=0;i<=n;i++)
	for(j=0;j<=n;j++)
	dp[i][j]=-1;
	
	cout<<sol(0,n-1,1)<<endl;
}
