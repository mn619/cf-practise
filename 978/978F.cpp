#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;
bs(vector <ll> v[], int i, int l,int r)
{
	int mid=(l+r)/2;
	if(l==r) return mid;
	if(mid==0)  if(v[1][0]>v[0][0])return 1; else return 0;
	
	if(v[mid][0]==i and v[mid-1][0]<i)return mid;
	if(v[mid][0]<i)return bs(v,i,mid+1,r);
	return bs(v,i,l,mid-1);
}

int main()
{
	int n,k;
	cin>>n>>k;
	vector <ll> v[n];ll r[n];
	
	for(int i=0;i<n;i++)
	{
		ll k1;
		cin>>k1;
		r[i]=k1;
		v[i].pb(k1);
		v[i].pb(i);
	}
	
	sort(v,v+n);
	
	vector <int> q[n];
	for(int i=0;i<k;i++)
	{
		int a,b;
		cin>>a>>b;
		a--; b--;
		q[a].pb(b);
		q[b].pb(a);
	}
	int ans[n];
	
	for(int i=0;i<n;i++)
	{
		ans[v[i][1]]=bs(v,v[i][0],0,i);
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<q[i].size();j++)
		{
			if(r[q[i][j]]<r[i]) ans[i]--;
		}
	}
	
	for(int i=0;i<n;i++)cout<<ans[i]<<" ";
}

