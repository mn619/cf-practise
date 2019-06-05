#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007
#define fr(i,a,b)for(i=a;i<b;i++)

using namespace std;
string s;
int k,ans=-1; char a[26];
struct node{
	node * n[26];
};
node *root;

void createnode(node *n)
{
	int i;
	fr(i,0,26)n->n[i]=NULL;
}

void createtrie(int l)
{
	node * temp=root;
	int i;
	fr(i,l,s.size())
	{
		if(temp->n[s[i]-'a'])temp=temp->n[s[i]-'a'];
		else temp->n[s[i]-'a']=new node,createnode(temp->n[s[i]-'a']),temp=temp->n[s[i]-'a'];
	}
}

void dfs(node * x,int cnt)
{
	int i;
	if(cnt>k)return;
	ans++;
	
	fr(i,0,26)
	{
		if(x->n[i])
		{
			if(a[i]=='0')dfs(x->n[i],cnt+1);
			else dfs(x->n[i],cnt);
		}
	}
}
signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>s;
	int n=s.size();
	root =new node;
	createnode(root);
	int i;
	fr(i,0,26)
	{
		cin>>a[i];
	}
	cin>>k;
	
	fr(i,0,n)createtrie(i);
	dfs(root,0);
	cout<<ans;
}



