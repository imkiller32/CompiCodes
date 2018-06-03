#include<bits/stdc++.h>
#define ll long long
using namespace std;

long double f(ll n,ll a)
{
	long double res=n*log(n)-n+(0.5*(log(2*3.14159*n)))-(n*log(a));
    return res;
}

ll find(ll a)
{
	ll start=4,end=3*a;
	ll mid;
	while(start<end)
	{
		mid=(start+end)>>1;
		long double x=f(mid,a);
		if(x<0)
		start=mid+1;
		else if(x>0)
		end=mid;
		else
		{
			start=mid+1;
			break;
		}
	}
	return start;
}

int main()
{
	ios::sync_with_stdio(false);
	ll test;
	cin>>test;
	while(test--)
	{
		ll a;
		cin>>a;
		cout<<find(a)<<endl;
	}
}
