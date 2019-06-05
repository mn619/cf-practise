#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int n,m,k,a[100001], qans[100001], Bsiz, cnt[2000001] = {0};
pair<pair<int, int>, int> q[100001];

bool comp(pair<pair<int, int>, int> m1, pair<pair<int, int>, int> m2)
{
	if(m1.first.first/Bsiz != m2.first.first/Bsiz) return (m1.first.first < m2.first.first);
	return (m1.first.second < m2.first.second);
}

void read()
{
	cin>>n>>m>>k;
	fr(i,1,n + 1) {cin>>a[i]; a[i]^=a[i - 1];}

	fr(i,1,m + 1)
	{
		int l,r;
		cin>>l>>r;
		l--;
		q[i] = {{l,r}, i};
	}

	Bsiz = sqrt(n);
	sort(q + 1, q + m + 1, comp);

}

void solve()
{
	int cur = 1, ans = 0, l = 0, r = 1;
	
	
	cnt[0]++;
	cnt[a[1]]++;
	if(a[1] == k) ans++;

	while(cur <= m)
	{
		while(r < q[cur].first.second)
		{
			r++;
			ans += cnt[a[r]^k];
			cnt[a[r]]++;
		}

		while(l > q[cur].first.first)
		{
			l--;
			ans += cnt[a[l]^k];
			cnt[a[l]]++;
		}

		while(r > q[cur].first.second)
		{
			cnt[a[r]]--;
			ans -= cnt[a[r]^k];
			r--;
		}

		while(l < q[cur].first.first)
		{
			cnt[a[l]]--;
			ans -= cnt[a[l]^k];
			l++;
		}

		qans[q[cur].second] = ans;
		cur++;
	}

	fr(i,1,m + 1) cout<<qans[i]<<" ";
}
signed main()
{
	FILEIO
 	FLASH

 	read();
 	solve();
}