#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,i,j;
	cin>>t;
	while(t--)
	{
		int n,energy[21][3];
		cin>>n;
		energy[0][0]=energy[0][1]=energy[0][2]=0;
		for(i=1;i<=n;i++)
		for(j=0;j<3;j++)
		cin>>energy[i][j];
		
		for(i=1;i<=n;i++)
		{
			energy[i][0]+=min(energy[i-1][1],energy[i-1][2]);
			energy[i][1]+=min(energy[i-1][0],energy[i-1][2]);
			energy[i][2]+=min(energy[i-1][0],energy[i-1][1]);
		}
		cout<<min(energy[n][0],min(energy[n][1],energy[n][2]))<<endl;
	}
}
