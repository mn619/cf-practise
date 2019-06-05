#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m;
int cnt[200001] = {0};
vector <int> v[200001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;
 	fr(i,1,m + 1)
 	{
 		int a, b;
 		cin>>a>>b;
 		
 		v[a].pb(b);
 		v[b].pb(a);

 		cnt[a]++;
 		cnt[b]++;
 	}

 	int node = 0; 

 	fr(i,1,n + 1)
 	{
 		if(cnt[i] >  cnt[node]) node = i;
 	}
 	
 	bool vis[n + 1] = {0};

 	queue < pair<int ,int> > q;
 	q.push({node, node});

 	vis[node] = 1;
 	while(!q.empty())
 	{
 		auto x = q.front();
 		vis[x.second] = 1;
 		q.pop();
 		if(x.second != x.first) cout<<x.first<<" "<<x.second<<"\n";

 		for(auto t: v[x.second])
 		{
 			if(!vis[t]){ q.push({x.second, t}); vis[t] = 1;}
 		}
 	}

}