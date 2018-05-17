#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n,q,i;
	string s;
	cin>>n;
	unordered_map<string,ll> m;
	while(n--)
	{
		cin>>s;
		if(m.find(s)==m.end())
		{
			m[s]=0;
			cout<<s<<endl;
		}
		else
		{
			stringstream ss;
			ll k=m[s];
			ss<<k;
			string temp=s+ss.str();
			while(m.find(temp)!=m.end())
			{
				stringstream ss1;
				++k;
				ss1<<k;
				temp=s+ss1.str();
			}
			cout<<temp<<endl;
			m[temp]=0;
			m[s]=k+1;
		}
	}
}
