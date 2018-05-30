#include<bits/stdc++.h>
using namespace std;

int Search_Pattern(string s,string p,vector<int> F)
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
	string s,p;
	vector<int> v;
	cin>>p;
	cin>>s;
	v=CreatePrefix(p);
	int res=Search_Pattern(s,p,v);
	cout<<res<<endl;
}
