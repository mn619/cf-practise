#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[1000001], mx[1000001], x;
vector <int> v[1000001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>x;

 	fr(i, 1, n + 1){
 		cin>>a[i];
 		mx[i] = max(mx[i - 1], a[i]);
 		v[a[i]].pb(i);
 	}

 	int dp[x + 1] = {1};

 	fr(i, 1, x + 1){
 		int minind = n + 1;
 		for(auto p: v[i]){
 			minind = min(p,  minind);
 		}
 		cout<<minind<<' '<<mx[minind - 1]<<'\n';

 		dp[i] = dp[i - 1] + dp[mx[minind - 1]];
 	}

 	cout<<dp[x];
}