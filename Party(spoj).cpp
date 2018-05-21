/*party sech. Knapsack Topic:Dp
Cpp practice code
Author- Ritesh Aggarwal
*/

#include<bits/stdc++.h>
using namespace std;

void Knapsack(int efee[],int fun[],int budget,int nop)
{
	int Sol[nop+1][budget+1],i,j,minMoney=0,maxFun;
	for(i=0;i<=nop;i++)
		for(j=0;j<=budget;j++)
			{
				if(i==0||j==0)
					Sol[i][j]=0;
				else if(efee[i-1]<=j)
					Sol[i][j]=max(fun[i-1]+Sol[i-1][j-efee[i-1]],Sol[i-1][j]);
				else
					Sol[i][j]=Sol[i-1][j];
			}
			
	maxFun=Sol[nop][budget];
	for(i=0;i<=budget;i++)
	{
		if(Sol[nop][i]==maxFun)
		{
			minMoney=i;
			break;
		}
	}
	cout<<minMoney<<" "<<maxFun<<endl;
}

int main()
{
	int budget,nop,i,efee[100],fun[100];
	while(1)
	{
		cin>>budget>>nop;
		if(budget==0&&nop==0)
		break;
		for(i=0;i<nop;i++)
			cin>>efee[i]>>fun[i];
		Knapsack(efee,fun,budget,nop);
	}
}
