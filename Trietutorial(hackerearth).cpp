#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<string,ll> m;

int main()
{
	ll n,q,i,w;
	string s,str;
	cin>>n>>q;
	while(n--)
	{
		cin>>s>>w;
		for(i=0;i<s.size();i++)
		{
			str+=s[i];
			if(m[str]==0||m[str]<w)
			m[str]=w;
		}
		str.clear();
	}
	while(q--)
	{
		cin>>str;
		if(m[str]==0)
		cout<<"-1\n";
		else
		cout<<m[str]<<endl;		
	}
}
