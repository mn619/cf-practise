#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;

int n, T;
vector <int> v[200001];

signed main()
{
	//FILEIO
 	//start_routine
	
	cin>>n>>T;
	fr(i,1,n + 1)
	{
		int a, t;
		cin>>a>>t;
		v[i].pb(a);
		v[i].pb(t);
		v[i].pb(i);
	}

	sort(v + 1, v + n + 1);

	int l = 0, r = n;
	int ans;
	while(l <= r)
	{
		int mid = (l + r)/2;
		int t = 0, in = 0;
		vector <int> x;
		fr(i,1,n + 1)
		{
			if(v[i][0] >= mid)
			{
				x.pb(v[i][1]);
			}
		}

		sort(x.begin(), x.end());
		fr(i,0,x.size())
		{
			if(in == mid) break;
			t += x[i];
			in++;
		}

		if( t<=T && in==mid )ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout<<ans<<'\n';
	vector <int> Ans[n + 1];
	int cnt = 1;
	fr(i,1,n + 1)
	{
		if(v[i][0] >= ans) 
		{
			Ans[cnt].pb(v[i][1]);
			Ans[cnt].pb(v[i][0]);
			Ans[cnt].pb(v[i][2]);
			cnt++;
		}
	}
	cnt--;
	sort(Ans + 1, Ans + cnt + 1);
	cout<<ans<<'\n';
	int in = 0;
	fr(i,1,ans + 1)
	{
	 	cout<<Ans[i][2]<<" ";
	}
 	//end_routine
}
