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
 	start_routine

	priority_queue < pair<int, int> > pq;
	int n,m,d;
	cin>>n>>m>>d;

	int i;
	vector <int>  v[n+1];
	fr(i,1,n+1)
	{
		int x;
		cin>>x;
		v[i].pb(x);
		v[i].pb(i);
	}
	sort(v+1,v+n+1);

	int ans[n+1], days = 1;
	ans[v[1][1]] = 1;
	pq.push({-v[1][0], 1});

	fr(i,2,n+1)
	{
		if(v[i][0] > -pq.top().first + d)
		{
			ans[v[i][1]] = pq.top().second;
			pq.pop();
			pq.push({-v[i][0],ans[v[i][1]]});
		}
		else
		{
			days++;
			ans[v[i][1]] = days;
			pq.push({-v[i][0], days});
		}
	}
	cout<<days<<'\n';
	fr(i,1,n+1)cout<<ans[i]<<" ";


 	end_routine
}



