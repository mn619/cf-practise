#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n,t, a[200001], k, qans[200001], m[1000001] = {0};

pair <int, pair<int, int>> q[200001];

bool comp(pair <int, pair<int, int>> q1, pair <int, pair<int, int>> q2)
{
	if(q1.second.first/k != q2.second.first/k) return (q1.second.first < q2.second.first);
	return (q1.second.second < q2.second.second);
}

void read()
{
	cin>>n>>t;
	fr(i,1,n + 1) cin>>a[i];
	fr(i,1,t + 1)
	{
		int l, r;
		cin>>l>>r;
		q[i] = {i,{l,r}};
	}

	k = sqrt(n);
	sort(q + 1, q + t + 1, comp);
}

void solve()
{
	int cur = 1, l = 0, r = 0, ans = 0;
	
	while(cur <= t)
	{
		while(r < q[cur].second.second)
		{
			ans -= m[a[r + 1]]*m[a[r + 1]]*a[r + 1];
			m[a[r + 1]]++;
			ans += m[a[r + 1]]*m[a[r + 1]]*a[r + 1];
			r++;
		}
		
		while(l > q[cur].second.first)
		{
			ans -= m[a[l - 1]]*m[a[l - 1]]*a[l - 1];
			m[a[l - 1]]++;
			ans += m[a[l - 1]]*m[a[l - 1]]*a[l - 1];
			l--;
		}
	
		while(r > q[cur].second.second)
		{
			ans -= m[a[r]]*m[a[r]]*a[r];
			m[a[r]]--;
			ans += m[a[r]]*m[a[r]]*a[r];
			r--;
		}
			
		while(l < q[cur].second.first)
		{
			ans -= m[a[l]]*m[a[l]]*a[l];
			m[a[l]]--;
			ans += m[a[l]]*m[a[l]]*a[l];
			l++;
		}
		
		qans[q[cur].first] = ans;
		cur++;
	}

	fr(i,1,t + 1) cout<<qans[i]<<"\n";
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