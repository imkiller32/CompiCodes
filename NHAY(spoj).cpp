#include<bits/stdc++.h>
using namespace std;

int Search_Pattern(string s,string p,vector<int> F,int a[])
{
	int i,j,occur=0;
	i=0;
	j=-1;
	while(i<s.length())
	{
		if(s[i]==p[j+1])
		{
			i++;
			j++;
			if(j+1==p.length())
			{
				a[occur]=i-p.length();
				occur++;
				j=-1;
				i=i-p.length()+1;
			}
		}
		else
		{
			if(j==-1)
			i++;
			else
			j=F[j]-1;
		}
	}
	return occur;
}

vector<int> CreatePrefix(string s)
{
	int n = (int) s.length() ;
	vector<int> F(n);
	F[0]=0;
	for(int i=1;i<n;i++)
	{
		int j = F[i-1];
		while(j>0 && s[i]!=s[j])
		j=F[j-1];
		if(s[i]==s[j])
		j++;
		F[i]=j;
	}
	return F;
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	while(cin>>t)
	{
		string n,h;
		vector<int> v;
		cin>>n>>h;
		int a[h.length()];
		v=CreatePrefix(n);
		int res=Search_Pattern(h,n,v,a);
		if(res==0)
		cout<<endl<<endl;
		else
		{
			for(int i=0;i<res;i++)
			cout<<a[i]<<endl;
		}
	}
}
