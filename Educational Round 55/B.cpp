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
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;

signed main()
{
	FILEIO
 	//start_routine
	int n;
	string s;
	cin>>n;
	cin>>s;
	bool in = 0;
	int  las = -1;
	int cnt = 0;
	int i;
	vector <int> l,r;

	fr(i,0,n)
	{
		if(s[i] == 'G') cnt++;
		if(s[i] == 'S' && in == 1)
		{
			l.pb(las), r.pb(i - 1);
			in = 0;
		}
		else if(s[i] == 'G' && in == 0)
		{
			las = i;
			in = 1;
		}
	}
	if(in == 1)
	{
		l.pb(las);
		r.pb(n-1);
	}

	int len = l.size();
	int ans = 0;

	fr(i,0,len)
	{
		if(i < len - 1 && r[i] + 2 == l[i+1])
		{
			ans = max(ans, r[i+1] - l[i] + 1);
		}
		ans = max(ans, r[i] - l[i] + 1);
	}

	if(ans != cnt + 1)
	{
		cout<<ans;
		return 0;
	}

	cout<<ans - 1<<'\n';
 	//end_routine
}
