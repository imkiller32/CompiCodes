/*
Bottom Spoj
SINK BASED STRONGLY CONNECTED COMPONENTS
AUTHOR-Ritesh Aggarwal
*/


#include<bits/stdc++.h>
#define max_nodes 100001
using namespace std;

stack<int> startTime;
bool visited[max_nodes];
bool visitedN[max_nodes];
vector<int> og[max_nodes];
vector<int> rg[max_nodes];

//For Original Graph
void DFSO(int source)
{
	int i;
	visited[source]=true;
	for(i=0;i<og[source].size();i++)
	{
		if(visited[og[source][i]]==false)
			DFSO(og[source][i]);
	}
	startTime.push(source);
}

//For Reverse Graph
void DFSR(int source)
{
	int i;
	visited[source]=true;
	for(i=0;i<rg[source].size();i++)
	{
		if(visited[rg[source][i]]==false)
			DFSR(rg[source][i]);
	}
}

bool find(int nBour,int check[],int y)
{
	bool res=false;
	for(int i=0;i<y;i++)
	{
		if(check[i]==nBour)
		res=true;
	}
	return res;
}

int main()
{
	while(1)
	{
		int n,m,a,b,i;
		for(i=0;i<max_nodes;i++)
		{
			og[i].clear();
			rg[i].clear();
		}
		int answer[100001];
		cin>>n;
		if(n==0)
		break;
		cin>>m;
		for(i=0;i<m;i++)
		{
			cin>>a>>b;
			a--;b--;
			og[a].push_back(b);
			rg[b].push_back(a);
		}
		for(i=0;i<=max_nodes;i++)
		visited[i]=false;
		for(i=0;i<n;i++)
		{
			if(visited[i]==false)
			DFSO(i);
		}
	
		for(i=0;i<=max_nodes;i++)
		visited[i]=false;
		int x=0;
		while(!startTime.empty())
		{
			if(visited[startTime.top()]==true)
			{
				startTime.pop();
				continue;
			}
			for(i=0;i<n;i++)
			{
				visitedN[i]=visited[i];
			}
			DFSR(startTime.top());
			startTime.pop();
			
			int check[max_nodes];
			int j,k,cf=0,y=0,cff=0;
			for(i=0;i<n;i++)
			{
				if(visited[i]!=visitedN[i])
				{
					check[y]=i;
					y++;
				}
			}
			
			for(i=0;i<y;i++)
			{
				k=check[i];
				if(og[k].size()==0)
				break;
				for(j=0;j<og[k].size();j++)
				{
					int nBour=og[k][j];
					if(!find(nBour,check,y))
					{
						cff=1;
						break;
					}
				}
				if(cff)
				break;
			}
			if(!cff)
			{
				for(i=0;i<n;i++)
				{
					if(visited[i]!=visitedN[i])
					{
						answer[x]=i+1;
						x++;
					}
				}
			}
		}
		sort(answer,answer+x);
		if(x==0)
		cout<<endl;
		else
		for(i=0;i<x;i++)
		cout<<answer[i]<<" ";
		cout<<endl;
		while(!startTime.empty())
		startTime.pop();
	}
}
