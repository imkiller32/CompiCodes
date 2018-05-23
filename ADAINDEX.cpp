#include<bits/stdc++.h>
using namespace std;

struct node
{
	struct node *child[26];
	int countWord;
};

struct node* CreateNode()
{
	struct node *temp=new node;
	temp->countWord=0;
	for(int i=0;i<26;i++)
	temp->child[i]=NULL;
	return temp;
}
void insert(string s,struct node *root)
{
	struct node *temp=root;
	int i,ind;
	for(i=0;i<s.size();i++)
	{
		if(temp->child[s[i]-'a']==NULL)
			{
				temp->child[s[i]-'a']=CreateNode();
				temp=temp->child[s[i]-'a'];
				temp->countWord+=1;
			}
		else
		{
			temp=temp->child[s[i]-'a'];
			temp->countWord+=1;
		}
	}
}
int find(string s,struct node *root)
{
	int i,ind;
	struct node *temp=root;
	for(i=0;i<s.size();i++)
	{
		if(temp->child[s[i]-'a']==NULL)
		return 0;
		temp=temp->child[s[i]-'a'];
	}
	return temp->countWord;
}
int main()
{
	int n,q,i;
	string s;
	struct node *root=CreateNode();
	cin>>n>>q;
	for(i=0;i<n;i++)
	{
		cin>>s;
		insert(s,root);
	}
	for(i=0;i<q;i++)
	{
		cin>>s;
		cout<<find(s,root)<<endl;
	}
}
