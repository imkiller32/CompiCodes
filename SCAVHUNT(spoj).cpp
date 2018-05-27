/* 
Topological Sort
Solution is based on lexographical order
Solution can be used for SCACHUNT(spoj)
Author--> Ritesh Aggarwal
CSE IIT(ISM) DHANBAD
*/


#include<bits/stdc++.h>
#define max_nodes 100001
using namespace std;

vector<int> og[max_nodes];
map<string,int> myMap;
map<int,string> myRmap;
bool visited[max_nodes];

stack<int> startTime;

void DFS(int source)
{
	visited[source]=true;
	for(int i=0;i<og[source].size();i++)
		if(!visited[og[source][i]])
			DFS(og[source][i]);
	startTime.push(source);
}

int main()
{
	int t,test;
	cin>>test;
	for(t=1;t<=test;t++)
	{
		int n,m,i,assign=1;
		for(i=0;i<max_nodes;i++)
		og[i].clear();
		myMap.clear();
		myRmap.clear();
		
		cin>>n;
		m=n-1;
		string str1,str2;
		for(i=0;i<m;i++)
		{
			cin>>str1>>str2;
			if(!myMap[str1])
			{
				myMap[str1]=assign++;
				myRmap[assign-1]=str1;
			}
			if(!myMap[str2])
			{
				myMap[str2]=assign++;
				myRmap[assign-1]=str2;
			}
			og[myMap[str1]-1].push_back(myMap[str2]-1);
		}
	
		for(i=0;i<n;i++)
		{
			sort(og[i].begin(),og[i].end(),greater<int>());
			visited[i]=false;
		}
		for(i=n-1;i>=0;i--)
		if(visited[i]==false)
		DFS(i);
		int ans;
		cout<<"Scenario #"<<t<<":\n";
		while(!startTime.empty())
		{
			ans=startTime.top()+1;
			cout<<myRmap[ans]<<endl;
			startTime.pop();
		}
		cout<<endl;
	}
}
