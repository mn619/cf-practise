#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007

using namespace std;
signed main()
{
 	//start_routine
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	vector <int> v[n+1];

	int i;

	fr(i,1,n)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}

 	int a[n+1];
 	fr(i,1,n+1)cin>>a[i];

 	bool vis[n+1] = {0};

 	queue <int> q;
 	q.push(1);
 	if(a[1]!=1) return cout<<"No",0;
 	i = 1;

 	while(i<n)
 	{
 		int node = q.front();
 		vis[node] = 1;
 		
 		int j;
 		set <int> s;
 		fr(j,0,v[node].size())
 		{
 			if(!vis[v[node][j]]) {s.insert(v[node][j]);}
 		}
 		int l = s.size();
 		fr(j,i+1,i+l+1)
 		{
 			
 			if(!(s.count(a[j])) && !(vis[a[j]])) return cout<<"No",0;
 			if(!(vis[a[j]])) {s.erase(a[j]); q.push(a[j]);}
 		}
 		i = j - 1;
 		q.pop();
 	}

 	cout<<"Yes\n";
 	//end_routine
}



