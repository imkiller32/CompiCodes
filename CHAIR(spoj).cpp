/*Spoj CHAIR DP
Cpp practice code
Author- Ritesh Aggarwal
LOGIC: PnC
*/

#include<bits/stdc++.h>
#define ll long long
#define p 1000000003
using namespace std;

ll binC(ll n, ll k)
{
    ll C[k+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = min(i, k); j > 0; j--)
            C[j] = (C[j]%p + C[j-1]%p)%p;
    }
    return C[k];
}

void find(ll n,ll k)
{
	ll sol1=0,sol2=0,ans=0;
	if(n-k-1>=k-1)
	sol1=(binC(n-k-1,k-1))%p;
	if(n-k-1>=k)
	sol2=(binC(n-k-1,k))%p;
	sol1=(2*sol1)%p;
	ans=(sol1%p+sol2%p)%p;
	cout<<ans;
	
}
int main()
{
	int n,k;
	cin>>n>>k;
	if(k>n/2)
		cout<<"0\n";
	else
		find(n,k);
}
