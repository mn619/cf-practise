#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
/*
5
1 2
2 3
2 4
1 5
*/
using namespace std;

struct node
{
	vector <int> v;
	int level;
	bool visited;
	vector <int> child;
	int depth;
	int maxdepthchild;
};


int bfs(node a[],int root)
{
	a[root].level=1;
	int maxlevel=1;
	int potentialroot=root;
	
	queue <int> q;
	q.push(root);
	a[root].visited=1;
	while(!q.empty())
	{
		node n=a[q.front()];
		
		for(int i=0;i<n.v.size();i++)
		{
			if(!a[n.v[i]].visited)
			{	
				//a[q.front()].child.pb(n.v[i]);
				q.push(n.v[i]);
				a[n.v[i]].level=n.level+1;
				if(a[n.v[i]].level>maxlevel)
				{
					maxlevel=n.level+1;
					potentialroot=n.v[i];
				}
				a[n.v[i]].visited=1;
			}
		}
		q.pop();		
	}
	
	return potentialroot;
}

void child(node a[],int root, int n)
{
	for(int i=1;i<=n;i++)
	{
		a[i].visited=0;
	}
	
	queue <int> q;
	q.push(root);
	a[root].visited=1;
	while(!q.empty())
	{
		node n=a[q.front()];
		for(int i=0;i<n.v.size();i++)
		{			
			if(a[n.v[i]].visited==0)
			{
				a[n.v[i]].visited=1;
				a[q.front()].child.pb(n.v[i]);
				q.push(n.v[i]);
			}	
		}
		q.pop();

	}
}

int depth(node a[],int root)
{
	a[root].maxdepthchild=0;
	if(a[root].child.size()==0)
	{
		a[root].depth=1;
		return 1;
	}
	a[root].depth=0;
	
	for(int i=0;i<a[root].child.size();i++)
	{
		int k=depth(a,a[root].child[i]);
		if(a[root].depth<k+1)
		{
			a[root].depth=k+1;
			a[root].maxdepthchild=a[root].child[i];
		}
	}
	return a[root].depth;
}

inline int solve(node a[], multimap <int,int>  &q)
{
	multimap<int,int>::iterator it=q.end();
	if(it->second==0)it--;
	int t=it->second;
	
	
	//cout<<t<<" t is this\n";
	int ans=a[t].depth;
	//cout<<ans;
	int i=0;
	while(i<ans)
	{
		i++;
		node n=a[it->second];
		q.erase(it);
		it=q.lower_bound(a[n.maxdepthchild].depth);
		while(it->second!=n.maxdepthchild)
		{
			it++;
		}
		
		//cout<<it->first<<"hello\n";
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	
	node a[n+1];
	a[1].level=1;
	
	for(int i=1;i<n;i++)
	{
		int p,q;
		cin>>p>>q;
		
		a[p].v.pb(q);
		a[q].v.pb(p);
		a[p].visited=0;
		a[q].visited=0;
	}
	int root;
	root=bfs(a,1);
	child(a,root,n);
	depth(a,root);
	//cout<<root<<endl;
	
	//for(int i=1;i<=n;i++)a[i].visited=0;
	
	//for(int i=1;i<=n;i++) cout<<a[i].depth;
	
	multimap <int,int> q;
	//cout<<"root="<<root<<endl;
	for(int i=1;i<=n;i++)
	{
		if(i!=root)	q.insert(mp(a[i].depth,i));
	}
	
	
	multimap<int,int>::iterator it; it=q.end();
	it--;
	int ans=1,i=1;
	cout<<ans<<" ";
	while(q.size()!=0)
	{
		ans+=solve(a,q);
		cout<<ans<<" ";
		i++;
		//cout<<q.size()<<"size\n";
		//cout<<it->second<<endl;
	}
	
	while(++i<=n)cout<<ans<<" ";
	return 0;
	
}

