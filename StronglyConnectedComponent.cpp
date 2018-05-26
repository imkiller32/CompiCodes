#include<bits/stdc++.h>
using namespace std;

stack<int> startTime;
bool visited[16];

vector<int> og[16];
vector<int> rg[16];

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
	int n,m,a,b,i,mini;
	cin>>n>>m;
	mini=17;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		a--;b--;
		mini=min(mini,min(a,b));
		og[a].push_back(b);
		rg[b].push_back(a);
	}
	
	for(i=0;i<=16;i++)
	visited[i]=false;
	//DFS(mini);
	for(i=0;i<n;i++)
	{
		if(visited[i]==false)
		DFSO(i);
	}
	
	for(i=0;i<=16;i++)
	visited[i]=false;
	
	int outFalse=0,sumEven=0,sumOdd=0,outTrue=0,out;
	
	while(!startTime.empty())
	{
		outFalse=0,outTrue=0;
		if(visited[startTime.top()]==true)
		{
			startTime.pop();
			continue;
		}
		for(i=0;i<n;i++)
		{
			if(visited[i]==false)
			outFalse++;
		}
		DFSR(startTime.top());
		startTime.pop();
		for(i=0;i<n;i++)
		{
			if(visited[i]==false)
			outTrue++;
		}
		out=outFalse-outTrue;
		if(out%2==0)
		sumEven+=out;
		else
		sumOdd+=out;	
	}
	cout<<sumOdd-sumEven<<endl;
}
