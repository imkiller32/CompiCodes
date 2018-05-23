#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t,len,u[100000],l[10000],i;
    cin>>t;
    while(t--)
    {
        cin>>len;
        for(i=0;i<len-1;i++)
        cin>>u[i];
        for(i=0;i<len-1;i++)
        cin>>l[i];
        int tim=0;
        int flag=0;
        for(i=0;i<len;i++)
        {
            tim++;
        }
        int maxi=-1000;
        for(i=0;i<len-1;i++)
        {
            if(u[i]<(tim-i-1))
            u[i]=0;
            else
            u[i]-=tim-i-1;
            if(l[i]<(tim-i-1))
            l[i]=0;
            else
            l[i]-=tim-i-1;
            maxi=max(maxi,max(l[i],u[i]));
        }
        cout<<maxi+tim<<endl;
    }
}
