#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll Sol(ll n,ll k)
{
	if(n==0)
    return 0;
    else if (k==0)
    return 1;
    ll res=1;
    ll m=10000007;
    while(k)
    {
    	if(k&1)
        res=(res%m*n%m)%m;
        n=(n%m*n%m);
        k/=2;
	}
    return res%m;
}

int main()
{ 
	ios::sync_with_stdio(false);
	while(1)
	{
		ll n,k,a,b,c,d,m;
		cin>>n>>k;
		if(n==0&&k==0)
		return 0;
		m=10000007;
		if(k<n-1)
		{
			a=Sol(n-1,k)%m;
        	c=(Sol(n-1,n-1-k)%m*a)%m;
		}
    	else
        {
        	c=Sol(n-1,n-1)%m;
        	a=(Sol(n-1,k+1-n)%m * c)%m;
		}
    	if(k<n)
    	{
    		b=Sol(n,k)%m;
        	d=(Sol(n,n-k)%m * b)%m;
		}
    	else
        {
        	d=Sol(n,n)%m;
        	b=(Sol(n,k-n)%m * d)%m;
		}
		cout<<(2*a+b+2*c+d)%m<<endl;
	}
}
