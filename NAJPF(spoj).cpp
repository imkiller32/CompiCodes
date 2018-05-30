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
	int t;
	cin>>t;
	while(t--)
	{
		string s,p;
		vector<int> v;
		cin>>s>>p;
		int a[s.length()];
		v=CreatePrefix(p);
		int res=Search_Pattern(s,p,v,a);
		if(res==0)
		cout<<"Not Found"<<endl<<endl;
		else
		{
			cout<<res<<endl;
			for(int i=0;i<res;i++)
			cout<<a[i]+1<<" ";
			cout<<endl<<endl;;
		}
	}
}
