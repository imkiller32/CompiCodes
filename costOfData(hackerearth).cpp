#include<bits/stdc++.h>
using namespace std;

int out=0;

struct node
{
	struct node *child[26];
	bool endOfWord;
};
struct node *createNode()
{
	struct node *temp;
	temp=new node;
	for(int i=0;i<26;i++)
	{
		temp->child[i]=NULL;
	}
	temp->endOfWord=false;
	return temp;
}
void Insert(struct node *root,string s)
{
	struct node *temp=root;
	for(int i=0;i<s.size();i++)
	{
		if(temp->child[s[i]-'a']==NULL)
		{
			temp->child[s[i]-'a']=createNode();
			out++;
		}
		temp=temp->child[s[i]-'a'];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	string s;
	struct node *root=createNode();
	out++;
	while(n--)
	{
		cin>>s;
		Insert(root,s);
	}
	cout<<out;
}
