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

int main()
{
	int n,m,a,b,i;
	int answer[100001];
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
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
	int record=-1;
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
		int flag=0;
		for(i=0;i<n;i++)
		{
			if(visitedN[i]!=visited[i])
			{
				if(!flag)
				{
					record=i;
					flag=1;
				}
				answer[i]=record;
			}
		}
	}
	for(i=0;i<n;i++)
	cout<<answer[i]<<endl;
}
