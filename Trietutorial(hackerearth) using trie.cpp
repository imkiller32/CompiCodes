#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Trie
{
	struct Trie *child[26];
	ll weight;
	bool endOfWord;
	
};

struct Trie* createNode()
{
	struct Trie *t=new Trie;
	t->endOfWord=false;
	t->weight=0;
	for(int i=0;i<26;i++)
	t->child[i]=NULL;
	return t;
}
void Insert(struct Trie *root,string s,ll w)
{
	ll i;
	struct Trie *temp=root;
	for(i=0;i<s.size();i++)
	{
		if(temp->child[s[i]-'a']==NULL)
		{
			temp->child[s[i]-'a']=createNode();
			temp->weight=max(temp->weight,w);
		}
		temp->weight=max(temp->weight,w);
		temp=temp->child[s[i]-'a'];
	}
	temp->endOfWord=true;
}

ll Find(struct Trie *root,string s)
{
	struct Trie *temp=root;
	ll i;
	for(i=0;i<s.size();i++)
	{
		if(temp->child[s[i]-'a']==NULL)
			return -1;
		temp=temp->child[s[i]-'a'];
	}
	return temp->weight;
}

int main()
{
	ll n,q,i,w;
	string s,str;
	cin>>n>>q;
	struct Trie *root=createNode();
	while(n--)
	{
		cin>>s>>w;
		Insert(root,s,w);
	}
	while(q--)
	{
		cin>>s;
		cout<<Find(root,s)<<endl;
	}
}
