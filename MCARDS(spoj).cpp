/*MCARDS SPOJ (Can Be Solved SUing Concept of LCS)
Cpp practice code
Author- Ritesh Aggarwal
*/

#include<bits/stdc++.h>
using namespace std;
int arr[2][5000];
int brr[2][5000];
int lcs(int c,int n)
{
	int L[c*n+1][c*n+1];
	int i,j;
	for(i=0;i<=c*n;i++)
	{
		for(j=0;j<=c*n;j++)
		{
			if(i==0||j==0)
				L[i][j]=0;
			else if(arr[0][i-1]==brr[0][j-1] && arr[1][i-1]==brr[1][j-1])
				L[i][j]=L[i-1][j-1]+1;
			else
				L[i][j]=max(L[i-1][j],L[i][j-1]);
		}
	}
	return L[c*n][c*n];
}
int main()
{
	int c,n,i,a,b,j;
	vector<pair<int,int> > v[5];
	cin>>c>>n;
	for(i=0;i<c*n;i++)
	{
		cin>>a>>b;
		arr[0][i]=a;
		arr[1][i]=b;
		v[a-1].push_back(make_pair(b,a));
	}
	for(i=0;i<c;i++)
	sort(v[i].begin(),v[i].end());
	int x=0;
	int m=INT_MIN;
	do
	{
		x=0;
		for(i=0;i<c;i++)
		{
			for(j=0;j<v[i].size();j++)
			{
				brr[0][x]=v[i][j].second;
				brr[1][x]=v[i][j].first;
				x++;
			}
		}
		m=max(m,lcs(c,n));
	}
	while(next_permutation(v,v+c));
	cout<<c*n-m<<endl;
}
