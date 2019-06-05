#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;


int n, m;
vector <int> del[110];


int f(int x, int y)
{
	bool in[n + 1] = {0};
	fr(i,0,del[y].size()) in[del[y][i]] = 1;

	int ans = n*(del[y].size() - 1);
	int las = 0;
	fr(i,0,n)
	{
		int cur = (y + i)%n;
		while(cur < 0) cur += n;
		while(cur >= n) cur-=n;
		if(cur == 0) cur = n;
		if(in[cur]) las = cur;
	}

	cout<<x<<" "<<y<<" "<<las<<'\n';
	fr(i,1,n)
	{
		int cur = (las + i)%n;
		while(cur < 0) cur += n;
		while(cur >= n) cur-=n;
		if(cur == 0) cur = n;
		if(in[cur]) {ans += i; break;}
	}
	return ans;
}

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
 		del[a].pb(b);
 	}

 	vector <int> v;
 	int mx = 0;
 	fr(i,1,n + 1)
 	{
 		mx = max(mx, (int) del[i].size());
 	}

 	fr(i,1,n +1 )if(del[i].size() == mx) v.pb(i);

 	fr(i,1,n + 1)
 	{
 		int ans = 0;
 		fr(j,0,v.size())
 		{
 			ans = max(ans, f(i, v[j]));
 		}
 		cout<<ans<<' ';
 	}
}