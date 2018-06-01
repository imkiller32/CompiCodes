#include<bits/stdc++.h>
using namespace std;

int main()
{
	while(1)
	{
		int n,x,i,c=1,temp;
		queue<int> q;
		stack<int> s;
		cin>>n;
		if(n==0)
		return 0;
		for(i=0;i<n;i++)
		{
			cin>>x;
			q.push(x);
		}
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			if(x==c)
			c++;
			else
			{
				if(s.empty())
				{
					s.push(x);
					continue;
				}
				else
				{
					temp=s.top();
					while(temp==c && !s.empty())
					{
						s.pop();
						if(!s.empty())
						temp=s.top();
						c++;
					}
					if(x==c)
					c++;
					else
					s.push(x);
				}
			}
		}
		if(s.empty())
		cout<<"yes\n";
		else
		{
			int flag=0;
			while(!s.empty())
			{
				x=s.top();
				if(x==c)
				{
					s.pop();
					c++;
				}
				else
				{
					flag=1;
					break;
				}
			}
			if(flag)
			cout<<"no\n";
			else
			cout<<"yes\n";
		}
	}
}
