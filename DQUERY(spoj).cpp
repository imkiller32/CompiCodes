#include<bits/stdc++.h>
#define cin(n) scanf("%d",&n)
#define cout(n) printf("%d\n",n)
#define N 311111
#define A 1111111
using namespace std;

int Block;
int ans[N],answer=0,frequency[A],a[N];
struct node
{
	int L,R,i;
}query[N];

bool myCompare(node x,node y)
{
	if(x.L/Block!=y.L/Block)
		return x.L/Block<y.L/Block;
	return  x.R<y.R;
}
void remove(int position)
{
	frequency[a[position]]--;
	if(frequency[a[position]]==0)
	answer--;
}
void add(int position)
{
	frequency[a[position]]++;
	if(frequency[a[position]]==1)
	answer++;
}
int main()
{
	int n,i,q,l,r;
	cin(n);
	Block=sqrt(n);
	for(i=0;i<n;i++)
	cin(a[i]);
	cin(q);
	for(i=0;i<q;i++)
	{
		cin(query[i].L);
		cin(query[i].R);
		query[i].L--;
		query[i].R--;
		query[i].i=i;
	}
	sort(query,query+q,myCompare);
	int currentL=0,currentR=0;
	for(i=0;i<q;i++)
	{
		l=query[i].L;r=query[i].R;
		while(currentL<l)
		{
			remove(currentL);
			currentL++;
		}
		while(currentL>l)
		{
			add(currentL-1);
			currentL--;
		}
		while(currentR<=r)
		{
			add(currentR);
			currentR++;
		}
		while(currentR>r+1)
		{
			remove(currentR-1);
			currentR--;
		}
		ans[query[i].i]=answer;		
	}
	for(i=0;i<q;i++)
	cout(ans[i]);
}
