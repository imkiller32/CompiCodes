#include<bits/stdc++.h>
using namespace std;

struct node
{
	struct node *child[26];
	int a[26];
	bool endOfWord;
};
struct node *createNode()
{
	struct node *temp=new node;
	for(int i=0;i<26;i++)
	temp->child[i]=NULL;
	for(int i=0;i<26;i++)
	temp->a[i]=0;
	temp->endOfWord=false;
	return temp;
}
void Insert(struct node *root,string s)
{
	struct node *temp=root;
	for(int i=0;i<s.size();i++)
	{
		int ind=s[i]-'a';
		if(temp->child[ind]==NULL)
		{
			temp->child[ind]=createNode();
		}
		temp->a[ind]++;
		temp=temp->child[ind];
	}
	temp->endOfWord=true;
}
int Find(struct node *root,string s)
{
	int out=0,i;
	struct node *temp=root;
	for(i=0;i<s.size();i++)
	{
		if(temp->child[s[i]-'a']==NULL)
		return 0;
		temp=temp->child[s[i]-'a'];
	}
	for(i=0;i<26;i++)
	if(temp->child[i]!=NULL)
	out+=temp->a[i];
	if(temp->endOfWord==true)
	out++;
	return out;
}
int main()
{
	int n;
	cin>>n;
	string s;
	getline(cin,s);
	struct node *root=createNode();
	while(n--)
	{
		getline(cin,s);
		if(s[0]=='a')
			Insert(root,s.substr(4,s.size()));
		else
			cout<<Find(root,s.substr(5,s.size()))<<endl;
	}
}
