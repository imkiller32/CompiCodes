#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n,m,x,t=0,i,first,second;
		int a[1000];
		priority_queue<int>pq;
		queue<pair<int,int> >q;
		cin>>n>>m;
		for(i=0;i<n;i++)
		{
			cin>>x;
			q.push(make_pair(x,i));
			pq.push(x);
		}
		while(!q.empty())
		{
			first=q.front().first;
			second=q.front().second;
			q.pop();
			if(first!=pq.top())
			{
				q.push(make_pair(first,second));
			}
			else
			{
				t++;
				pq.pop();
				if(second==m)
				break;
			}
		}
		cout<<t<<endl;
	}
}
