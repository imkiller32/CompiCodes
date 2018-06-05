#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,fTree[100001],a[100001];

void update(int x,int type)
{
	for(;x<=n;x+=x&-x)
	{
		fTree[x]+=type;
	}
}

ll query(int x)
{
	ll ans=0;
	for(;x>0;x-=x&-x)
	{
		ans+=fTree[x];
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	ll temp,q,i,type,L,R;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]&1)
		update(i,1);
		else
		update(i,0);
	}
	cin>>q;
	ll ind;
	for(i=0;i<q;i++)
	{
		cin>>type;
		if(type==0)
		{
			cin>>ind>>temp;
			if(a[ind]&1)
			{
				if(!(temp&1))
				{
					a[ind]=2;
					update(ind,-1);
				}
			}
			else
			{
				if(temp&1)
				{
					a[ind]=3;
					update(ind,1);
				}
				
			}
		}
		else
		{
			cin>>L>>R;
			ll ans=query(R);
			if(L-1>0)
			ans-=query(L-1);
			if(type==2)
			cout<<ans<<endl;
			else
			cout<<(R-L+1)-ans<<endl;
		}
	}
}
