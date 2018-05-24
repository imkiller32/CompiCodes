#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,i,j;
	int val[5];
	cin>>n>>k;
	for(i=0;i<k;i++)
	{
		cin>>val[i];
		if(i>0)
		val[i]+=val[i-1];
	}
	bool in[n+1];
	in[0]=true;
	for(i=1;i<n+1;i++)
	in[i]=false;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<k;j++)
		{
			if(i-val[j]>=0)
			{
				in[i]= in[i] | in[i-val[j]];
			}
		}
	}
	if(in[n])
	cout<<"YES";
	else
	cout<<"NO";
}
