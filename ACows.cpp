#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,c,pos[100000];

int F(ll x)
{
	ll cowsplaced=1,lastpos=pos[0];
	for(ll i=0;i<n;i++)
	{
		if(pos[i]-lastpos>=x)
		{
			cowsplaced++;
			if(cowsplaced==c)
			return 1;
			lastpos=pos[i];
		}
	}
	return 0;
}
int main()
{
	ll t,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		for(i=0;i<n;i++)
			cin>>pos[i];
		sort(pos,pos+n);
		ll start=0,end=pos[n-1]-pos[0]+1,mid;
		while(end-start>1)
		{
			mid=(start+end)/2;
			if(F(mid))
			start=mid;
			else
			end=mid;
		}
		cout<<start<<endl;
	}
}
