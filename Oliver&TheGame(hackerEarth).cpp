/* 
Graph with depthFirstSearch
GoodQusetion for learning concept of arrival and dept.Time
Solution can be used for Oliver And The Game problem Of HackerEarth
Problrm Link->  https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/
Author--> Ritesh Aggarwal
CSE IIT(ISM) DHANBAD
*/

#include<bits/stdc++.h>
#define max_nodes 100001
using namespace std;

vector<int> G[max_nodes];
bool visited[max_nodes];
int arrTime[max_nodes];
int depTime[max_nodes];
int Time=1;

void DFS(int source)
{
	visited[source]=true;
	arrTime[source]=Time++;
	int i,v;
	for(i=0;i<G[source].size();i++)
	{
		v=G[source][i];
		if(!visited[v])
		DFS(v);
	}	
	depTime[source]=Time++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(false);
	cout.tie(false);
	int n,i,a,b,q,type,d,s;
	cin>>n; //No. Of Houses In City
	for(i=0;i<n-1;i++)
	{
		visited[i]=false;
		arrTime[i]=0;
		depTime[i]=0;
		cin>>a>>b;
		a--;b--;
		G[a].push_back(b);
	}
	for(i=0;i<n;i++)
	if(!visited[i])
	DFS(i);
	
	cin>>q; //No. of Queries
	for(i=0;i<q;i++)
	{
		cin>>type>>d>>s;
		d--;s--;
		if(type==0)
		{
			if(arrTime[s]>arrTime[d] && depTime[s]<depTime[d])
			cout<<"YES\n";
			else
			cout<<"NO\n";
		}
		else
		{
			if(arrTime[s]<arrTime[d] && depTime[s]>depTime[d])
			cout<<"YES\n";
			else
			cout<<"NO\n";
		}
	}
}
