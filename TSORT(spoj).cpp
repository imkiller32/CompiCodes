#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int L,int m,int R)
{
	int n1=m-L+1;
	int n2=R-m;
	int Left[n1],Right[n2],i,j,k;
	for(i=0;i<n1;i++)
	Left[i]=a[L+i];
	for(i=0;i<n2;i++)
	Right[i]=a[m+1+i];
	
	i=0,j=0,k=L;
	while(i<n1 && j<n2)
	{
		if(Left[i]<=Right[j])
		{
			a[k]=Left[i];
			i++;
			k++;
		}
		else
		{
			a[k]=Right[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		a[k]=Left[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=Right[j];
		j++;
		k++;
	}
}

void mergeSort(int a[],int L,int R)
{
	if(L<R)
	{
		int mid=(L+R)>>1;
		mergeSort(a,L,mid);
		mergeSort(a,mid+1,R);
		merge(a,L,mid,R);
	}
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	int n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	mergeSort(a,0,n-1);
	for(i=0;i<n;i++)
	cout<<a[i]<<endl;
}
