#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n,t[100001], a[100001] = {0}, k, qans[100001], cnt[300001], queris, block;
pair <int, int>  m[400001];
pair <int, pair<int, int>> q[100001];

bool comp(pair <int, pair<int, int>> q1, pair <int, pair<int, int>> q2)
{
	if(q1.second.first/block != q2.second.first/block) return (q1.second.first < q2.second.first);
	return (q1.second.second < q2.second.second);
}

void compress()
{
	vector <int> v;
	map <int, int> compressor;
	
	for(int i = 0; i<=n; i++)
	{
		int x = a[i];
		v.pb(x);
		v.pb(x + k);
		v.pb(x - k);
	}
	sort(v.begin(), v.end());
	int i = 0;
	for(auto x: v) compressor[x] = i++;
	
	for(auto it: compressor) if(compressor.count(it.first - k) && compressor.count(it.first + k))m[it.second] = {compressor[it.first - k], compressor[it.first + k]};
	//cout<<compressor.size()<<" is the size "<<compressor[0]<<" "<<m[11].first<<" "<<m[11].second;
	fr(j,0,n + 1) a[j] = compressor[a[j]];
}

void read()
{
	cin>>n>>k;
	
	fr(i,1,n + 1) cin>>t[i];
	fr(i,1,n + 1) {cin>>a[i]; if(t[i] == 2) a[i]*=-1; a[i] += a[i - 1];}

	compress();
	
	cin>>queris;
	fr(i,1,queris + 1)
	{
		int l, r;
		cin>>l>>r;
		l--;
		q[i] = {i,{l,r}};
	}

	block = sqrt(n);
	sort(q + 1, q + queris + 1, comp);
}

void solve()

{
	int cur = 1, l = 0, r = 1, ans = 0;
	cnt[a[0]]++;
	cnt[a[1]]++;
	if(a[1] == m[a[0]].second) ans++;

	while(cur <= queris)
	{
		while(r < q[cur].second.second)
		{
			r++;
			ans += cnt[m[a[r]].first];
			cnt[a[r]]++;
		}
		while(l > q[cur].second.first)
		{
			l--;
			ans += cnt[m[a[l]].second];
			cnt[a[l]]++;
		}
	
		while(r > q[cur].second.second)
		{
			cnt[a[r]]--;
			ans -= cnt[m[a[r]].first];
			r--;
		}
			
		while(l < q[cur].second.first)
		{
			cnt[a[l]]--;
			ans -= cnt[m[a[l]].second];
			l++;
		}
		
		qans[q[cur].first] = ans;
		cur++;
	}

	fr(i,1,queris + 1) cout<<qans[i]<<"\n";
}

signed main()
{
	
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
	
 	FLASH
 	read();
 	solve();

}