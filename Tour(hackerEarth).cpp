#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll cost[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	ll n,p,i,j,sum=0,now;
	string s;
	map<string,ll> m;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s;
		m[s]=i;
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>cost[i][j];			
	cin>>p;
	j=0;
	for(i=0;i<p;i++)
	{
		cin>>s;
		now=m[s];
		sum+=cost[j][now];
		j=now;
	}
	cout<<sum<<endl;
}
