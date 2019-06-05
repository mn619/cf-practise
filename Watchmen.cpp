#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define f(p,n) for(int i=p;i<n;i++)
#define mp make_pair

using namespace std;

signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	
	int x[n],y[n];
	map <pair<int,int> ,int> m;
	map<int,int> xmap;
	map <int,int> ymap;
	
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		m[mp (x[i],y[i])]++;
		if(xmap.count(x[i]))xmap[x[i]]++;
		else xmap[x[i]]=1;
		if(ymap.count(y[i]))ymap[y[i]]++;
		else ymap[y[i]]=1;
	}
	
	map <int,int>::iterator it=xmap.begin();
	
	int ans=0;
	
	while(1)
	{
		int x=it->second;
		ans=ans+x*(x-1)/2;
		it++;
		if(it==xmap.end())break;
	}
	it=ymap.begin();
	
	while(1)
	{
		int x=it->second;
		ans=ans+x*(x-1)/2;
		it++;
		if(it==ymap.end())break;
	}
	
	map<pair<int,int>,int>::iterator t=m.begin();
	while(1)
	{
		int x=t->second;
		ans=ans-x*(x-1)/2;
		t++;
		if(t==m.end())break;
	}
	cout<<ans;
}


