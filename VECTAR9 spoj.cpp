#include<bits/stdc++.h>
#define ll long long
#define cin(x) scanf("%lld",&x)
#define cout(x) printf("%lld\n",x)
using namespace std;

ll Temp[8200];
int a[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
void matrix()
{
	ll z=13;
	ll i,ans=0;
	for(i=1;i<(1<<z);i++)
	{
		ll j,c1=0,c2=0,temp=1;
		j=i;
		while(j)
		{
			if(j&1)
			{
				c2++;
				temp*=a[c1];
			}
			j>>=1;
			c1++;
		}
		if(c2&1)
		Temp[i]=temp;
		else
		Temp[i]=-temp;
	}
}
ll BM(ll n)
{
	ll z=13;
	ll i,ans=0;
	for(i=1;i<(1<<z);i++)
		ans+=(n/Temp[i]);
	return ans;
}

int main()
{
	ll t,i,k,n;
	matrix();
	cin(t);
	while(t--)
	{
		cin(k);
		ll mid,low=0,high=304250263527210;
		ll ans=0,temp=0;
		
		while(low<=high)
		{
			mid=low+(high-low)/2;
			temp=BM(mid);
			if(temp>=k)
			{
				high=mid-1;
				ans=mid;
			}
			else
			low=mid+1;
		}
		cout(ans);	
	}
}

