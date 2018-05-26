#include<bits/stdc++.h>
using namespace std;

bool myComprator(pair<int,int> &a,pair<int,int> &b)
{
	if(a.second==b.second)
	return a.first > b.first;
	else 
	return a.second > b.second;
}

int main()
{
	int n,m,k,val[1001],i;
	vector<pair<int,int> > v[1001];
	cin>>n>>m>>k;
	k--;
	for(i=0;i<n;i++)
	{
		cin>>val[i];
	}
	int x,y,j;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		x--;y--;
		v[x].push_back(make_pair(y,val[y]));
		v[y].push_back(make_pair(x,val[x]));
	}
	for(i=0;i<n;i++)
	{
		sort(v[i].begin(),v[i].end(),myComprator);
	}
	for(i=0;i<n;i++)	
	{
		if(v[i].size()==0)
		{
			cout<<"-1\n";
		}
		else
		{
			if(v[i][k].first||v[i][k].second)
			cout<<v[i][k].first + 1<<endl;
			else
			cout<<"-1\n";
		}
	}
}
