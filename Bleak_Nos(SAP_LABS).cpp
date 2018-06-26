/*
Cpp practice code
Author- Ritesh Aggarwal
*/

#include<iostream>
#include<algorithm>
using namespace std;

int countSet(int n)
{
    int out=0;
    while(n)
    {
        if(n&1)
        out++;
        n/=2;
    }
    return out;
}
int main()
{
	int i,temp,x=1;
	int a[100001];
	a[0]=0;
	for(i=1;i<100001;i++)
	{
	    temp=i+countSet(i);
	    if(temp!=a[x-1])
	    {
	    	a[x]=temp;
	    	x++;
		}
	}
	sort(a,a+x);
	int test,n;
	cin>>test;
	while(test--)
	{
		cin>>n;
		int start=1,end=x-1,flag=0;
		while(start<=end)
		{
			int mid=start+end>>1;
			if(a[mid]==n)
			{
				flag=1;
				break;
			}
			if(a[mid]<n)
			start=mid+1;
			else
			end=mid-1;
		}
		if(flag)
		cout<<"0\n";
		else
		cout<<"1\n";
	}
	return 0;
}
