#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	ll t;
	cin>>t;
	while(t--)
	{
		ll i,n;
		map<string,ll> m;
		string a[6];
		map<string,ll>::iterator itr;
		cin>>n;
		for(i=0;i<n;i++)
		{
			string s;
			cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
			stringstream ss;
			s=a[0]+a[1]+a[2]+a[3]+a[4]+a[5];
			m[s]++;
		}
		for(itr=m.begin();itr!=m.end();++itr)
		{
			string s=itr->first;
			
			for(i=0;i<2;i++)
			cout<<s[i];
			cout<<" ";
			
			for(i=2;i<10;i++)
			cout<<s[i];
			cout<<" ";
			
			for(i=10;i<14;i++)
			cout<<s[i];
			cout<<" ";
	
			for(i=14;i<18;i++)
			cout<<s[i];
			cout<<" ";
			
			for(i=18;i<22;i++)
			cout<<s[i];
			cout<<" ";
			
			for(i=22;i<26;i++)
			cout<<s[i];
			cout<<" ";
			
			cout<<itr->second<<endl;
		}
	}
	
}
