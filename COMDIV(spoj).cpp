#include<bits/stdc++.h>
#define cin(a) scanf("%d",&a)
#define cout(a) printf("%d\n",a)
using namespace std;

inline int gcd(int a,int b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}
	
int main()
{
	int test;
	cin(test);
	while(test--)
	{
		int a,b,out=0,i,temp;
		cin(a);cin(b);
		temp=gcd(a,b);
		for(i=1;i*i<=temp;i++)
		{
			if(temp%i==0)
			out+=2;			
		}
		i--;
		if(i*i==temp)
		out--;
		cout(out);
	}
}
