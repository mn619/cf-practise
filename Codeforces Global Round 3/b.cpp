#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200001

using namespace std;


int n, m, ta, tb, k, a[200001], b[200001];

int bs(int x){
	int l = 1, r = m;
	int ans = m + 1;
	while(l <= r){
		int mid = (l + r)/2;
		if(b[mid] >= x){
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}

	return ans;
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n>>m>>ta>>tb>>k;
	fr(i, 1, maxn){
		a[i] = inf;
		b[i] = inf;
	}

	fr(i, 1, n + 1) cin>>a[i];
	fr(i, 1, m + 1) cin>>b[i];

	int ans = -1;

	if(k >= min(n, m)) return cout<<-1, 0;

	fr(i, 0, min(n, k) + 1){
		int t = a[i + 1] + ta;
		int ind = bs(t);
		if(ind + (k - i) > m) return cout<<-1, 0;
		else ans = max(ans, b[ind + (k - i)] + tb);
	}

	cout<<ans;
}