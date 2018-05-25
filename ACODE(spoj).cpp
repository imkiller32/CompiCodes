#include<bits/stdc++.h>
using namespace std;

int Sol(string s)
{
	int len=s.length();
	int dp[len];
	dp[0]=1;
	if(s[0]<'2'&&s[1]!='0')
	dp[1]=2;
	else if(s[0]<'2'&&s[1]=='0')
	dp[1]=1;
	else if(s[0]=='2'&&s[1]<='6'&&s[1]!='0')
	dp[1]=2;
	else
	dp[1]=1;
	for(int i=2;i<len;i++)
	{
		if(s[i-1]<'2'&&s[i-1]>'0'&&s[i]!='0')
		dp[i]=dp[i-1]+dp[i-2];
		else if(s[i-1]<'2'&&s[i-1]>'0'&&s[i]=='0')
		dp[i]=dp[i-2];
		else if(s[i-1]=='2'&&s[i]<='6'&&s[i]>'0')
		dp[i]=dp[i-1]+dp[i-2];
		else if(s[i-1]=='2'&&s[i]<='6'&&s[i]=='0')
		dp[i]=dp[i-2];
		else
		dp[i]=dp[i-1];
	}
	return dp[len-1];
}


int main()
{
	while(true)
	{
		int i,flag=0;
		string s;
		cin>>s;
		if(s=="0")
		break;
		if(s[0]=='0')
		{
			cout<<"0\n";
			flag=1;
		}
		for(i=1;i<s.length()-1;i++)
		{
			if(s[i]=='0'&&s[i+1]=='0')
			{
				cout<<"0\n";
				flag=1;
				break;
			}
		}
		if(flag==0)
		cout<<Sol(s)<<endl;
	}
}
