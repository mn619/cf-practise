#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[1001];
int dp[1001][1001];
pair <int, int> p[1001][1001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n;

	fr(i, 1, n + 1) cin>>a[i];

	for(int i = n + 2; i >= 1; i--){
		for(int j = 1; j < i; j++){
			if(i > n){
				dp[i][j] = a[j];
				continue;
			}
			if(i == n){
				dp[i][j] = max(a[n], a[j]);
				p[i][j] = {j, i};
				continue;
			}
			int x  = max(a[i], a[i + 1]) + dp[i + 2][j];
			int y  = max(a[j], a[i + 1]) + dp[i + 2][i];
			int z  = max(a[j], a[i]) + dp[i + 2][i + 1];

			dp[i][j] = min(x, min(y, z));
			if(dp[i][j] == x){
				p[i][j] = {i, i + 1};
			}
			else if(dp[i][j] == y){
				p[i][j] = {j, i + 1};
			}
			else p[i][j] = {j, i};
		}
	}

	int ans = dp[2][1];
	cout<<ans<<'\n';
	int i = 2, j = 1;
	


	while(i <= n  and j <= n ){
		cout<<p[i][j].first<<" "<<p[i][j].second<<"\n";
		if(p[i][j].first == j and p[i][j].second == i){
			j = i + 1;
			i = i + 2;
		}
		else if(p[i][j].first == j and p[i][j].second == i + 1){
			j = i, i = i + 2;
		}
		else{
			i = i + 2;
		}
	}
	if(n&1) cout<<min(i, j);
	
}