#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fTree[1000001],a[1000001],n;

void update(ll x,ll val)
{
	for(;x<=n;x+=x&-x)
	{
		fTree[x]+=val;
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
	ll i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		update(i,a[i]);
	}
	ll q;
	cin>>q;
	for(i=0;i<q;i++)
	{
		string type;
		cin>>type;
		if(type=="q")
		{
			ll l,r;
			cin>>l>>r;
			l--;
			ll ans=query(r);
			if(l>0)
			ans-=query(l);
			cout<<ans<<endl;
		}
		else
		{
			ll ind,val;
			cin>>ind>>val;
			update(ind,val);
		}
	}
}
