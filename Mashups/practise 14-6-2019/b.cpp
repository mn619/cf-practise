#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

const int inf =  5e18;
int n, m, k, x, s, a[200001], b[200001], c[200001], d[200001];

int bs(int e){
	int l = 1, r = k, ans = 0;
	while(l <= r){
		int mid = (l + r)/2;
		if(d[mid] <= e){
			ans = c[mid];
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int solve(int t, int e){
	int rem = n - bs(e);
	return rem*t;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH


	cin>>n>>m>>k>>x>>s;

	fr(i, 1, m + 1) cin>>a[i]; 	
	fr(i, 1, m + 1) cin>>b[i];
	fr(i, 1, k + 1) cin>>c[i];
	fr(i, 1, k + 1) cin>>d[i];

	int ans = solve(x, s);
	fr(i, 1, m + 1){
		if(b[i] > s) continue; 
		ans = min(ans, solve(a[i], s - b[i]));
	}

	cout<<ans;
}