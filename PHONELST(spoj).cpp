#include<bits/stdc++.h>
using namespace std;

struct Trie
{
	struct Trie *child[10];
	bool end;
};

struct Trie *CreateNode()
{
	struct Trie *t=new Trie;
	t->end=false;
	for(int i=0;i<10;i++)
	t->child[i]=NULL;
	return t;
}

bool Insert(struct Trie *root,string s)
{
	struct Trie *temp=root;
	int i,flag=0;
	for(i=0;i<s.size();i++)
	{
		if(temp->child[s[i]-'0']==NULL)
			temp->child[s[i]-'0']=CreateNode();
			
		temp=temp->child[s[i]-'0'];
		if(temp->end)
		{
			flag=1;
			break;
		}
	}
	temp->end=true;
	if(flag)
	return false;
	else
	return true;
}

int main()
{
	int t,n,i;
	cin>>t;
	while(t--)
	{
		struct Trie *root=CreateNode();
		cin>>n;
		string s[n+1];
		bool res=true;
		for(i=0;i<n;i++)
		{
			cin>>s[i];
		}
		sort(s,s+n);
		for(i=0;i<n;i++)
		{
			res = res and Insert(root,s[i]);
			if(!res)
			break;
		}
		if(res)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
}
