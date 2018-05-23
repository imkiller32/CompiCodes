#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll t,n,a,b,i,j;
	cin>>t;
	ll arr[10000],dep[10000];
	while(t--)
	{
		cin>>n;
		i=n;
		while(i--)
		cin>>arr[i]>>dep[i];	
		sort(arr,arr+n);
		sort(dep,dep+n);
		ll theory=0,out=0;
		i=0,j=0;
		while(i<n && j<n)
		{
			if(arr[i]<dep[j])
			{
				theory++;
				i++;
			}
			else
			{
				theory--;
				j++;
			}
			out=max(theory,out);
		}
		cout<<out<<endl;
	}
}
