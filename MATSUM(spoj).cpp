#include<bits/stdc++.h>
using namespace std;

int n;
int BIT[1025][1025],data[1025][1025];

void update(int x,int y,int val)
{
	int i,j;
	for(i=x;i<=n;i+=i&-i)
	for(j=y;j<=n;j+=j&-j)
	BIT[i][j]+=val;
}

int getSum(int x, int y)
{
    int sum=0,i,j;
    for(i=x;i>0;i&=i-1)
    for(j=y;j>0;j&=j-1)
    sum+=BIT[i][j];
    return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	int test,x,y,num,x1,y1,x2,y2;
	cin>>test;
	while(test--)
	{
		cin>>n;
		for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			BIT[i][j]=0;
			data[i][j]=0;
		}
		string str;
		while(1)
		{
			cin>>str;
			if(str=="SET")
			{
				cin>>x>>y>>num;
				update(x+1,y+1,-data[x+1][y+1]+num);
				data[x+1][y+1]=num;				
			}
			else if(str=="SUM")
			{
				cin>>x1>>y1>>x2>>y2;
				x1++;y1++;x2++;y2++;
				int ans=0;
				ans+=getSum(x2, y2) ;
                ans-=getSum(x1 - 1, y2);
                ans-=getSum(x2, y1 - 1);
                ans+=getSum(x1 - 1, y1 - 1);	
				cout<<ans<<endl;
			}
			else
			break;
		}
		cout<<endl;
	}
}
