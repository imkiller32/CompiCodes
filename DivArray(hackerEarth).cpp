#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	ll n,i,d=1,x,q,maxi=0,flag=0;
	cin>>n;
	ll a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		maxi=max(a[i],maxi);
	}
	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>x;
		d=d*x;
		if(d>maxi)
		{
			flag=1;
			break;
		}
	}
	if(!flag)
	for(i=0;i<n;i++)
	{
		a[i]/=d;
		cout<<a[i]<<" ";
	}
	else
	for(i=0;i<n;i++)
	{
		a[i]=0;
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
